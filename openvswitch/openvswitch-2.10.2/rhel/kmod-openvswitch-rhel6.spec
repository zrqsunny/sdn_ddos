# Generated automatically -- do not modify!    -*- buffer-read-only: t -*-
# Spec file for Open vSwitch kernel modules on Red Hat Enterprise
# Linux 6.

# Copyright (C) 2011, 2012, 2018 Nicira, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without warranty of any kind.

%define oname openvswitch

Name:           kmod-%{oname}
Version:        2.10.2
Release:        1%{?dist}
Summary:        Open vSwitch kernel module

Group:          System/Kernel
License:        GPLv2
URL:            http://openvswitch.org/
Source0:        %{oname}-%{version}.tar.gz
BuildRoot:      %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)

# Without this we get an empty openvswitch-debuginfo package (whose name
# conflicts with the openvswitch-debuginfo package for OVS userspace).
%undefine _enable_debug_packages

%define kernel_source_extended() /usr/src/kernels/%{2}$([ %{1} = default ] || echo ".%{1}")

# Use -D 'kversion 2.6.32-131.6.1.el6.x86_64' to build package
# for specified kernel version.
# Use -D 'kversion 3.10.0-693.1.1.el7.x86_64 3.10.0-693.17.1.el7.x86_64'
# to build package for mulitple kernel versions in the same package
# This only works for kernel 3.10.0 major revision 693 (RHEL 7.4)
# and major revision 327 (RHEL 7.2)
# By default, build against the latest installed kernel-devel
%{!?kversion:%global kversion %(rpm -qa | egrep "^kernel(-rt|-aarch64)?-devel" | /usr/lib/rpm/redhat/rpmsort -r | head -n 1| sed "s/^kernel.*-devel-//")}

# Use -D 'kflavors default debug kdump' to build packages for
# specified kernel variants.
%{!?kflavors:%global kflavors default}

%description
Open vSwitch Linux kernel module.

%prep

%setup -n %{oname}-%{version}

%build
for kv in %{kversion}; do
    for flavor in %{kflavors}; do
        mkdir -p _$flavor/_$kv
        (cd _$flavor/_$kv && ../../configure --with-linux="%{kernel_source_extended $flavor $kv}")
        %{__make} -C _$flavor/_$kv/datapath/linux %{?_smp_mflags}
        done
done

%install
export INSTALL_MOD_PATH=$RPM_BUILD_ROOT
export INSTALL_MOD_DIR=extra/%{oname}
for kv in %{kversion}; do
    for flavor in %{kflavors} ; do
        make -C %{kernel_source_extended $flavor $kv} modules_install \
                M="`pwd`"/_$flavor/_$kv/datapath/linux
        # Cleanup unnecessary kernel-generated module dependency files.
        find $INSTALL_MOD_PATH/lib/modules -iname 'modules.*' -exec rm {} \;
    done
done
install -d %{buildroot}%{_sysconfdir}/depmod.d/
for kv in %{kversion}; do
    for module in %{buildroot}/lib/modules/$kv/$INSTALL_MOD_DIR/*.ko;
    do
        modname="$(basename ${module})"
        grep -qsPo "^\s*override ${modname%.ko} \* extra\/%{oname}" %{oname}.conf || \
            echo "override ${modname%.ko} * extra/%{oname}" >> %{oname}.conf
        grep -qsPo "^\s*override ${modname%.ko} \* weak-updates\/%{oname}" %{oname}.conf || \
            echo "override ${modname%.ko} * weak-updates/%{oname}" >> %{oname}.conf
    done
done
install -m 644 %{oname}.conf %{buildroot}%{_sysconfdir}/depmod.d/
install -d -m 0755 $RPM_BUILD_ROOT/usr/share/%{oname}/scripts
install -p -m 0755 rhel/usr_share_openvswitch_scripts_ovs-kmod-manage.sh \
    $RPM_BUILD_ROOT/usr/share/%{oname}/scripts/ovs-kmod-manage.sh

%post
current_kernel=$(uname -r)
IFS=. read installed_major installed_minor installed_micro installed_arch \
    installed_build <<<"${current_kernel##*-}"
if [ "$installed_major" = "327" ] || [ "$installed_major" = "693" ]; then
    # Workaround for RHEL 7.2 and 7.4
    if [ -x "/usr/share/%{oname}/scripts/ovs-kmod-manage.sh" ]; then
        /usr/share/%{oname}/scripts/ovs-kmod-manage.sh
    fi
else
    # Ensure that modprobe will find our modules.
    for k in $(cd /lib/modules && /bin/ls); do
        [ -d "/lib/modules/$k/kernel/" ] && depmod -a "$k"
    done
    if [ -x "/sbin/weak-modules" ]; then
        rpm -ql kmod-%{oname} | grep '\.ko$' | \
            /sbin/weak-modules --add-modules
    fi
fi

%postun
if [ "$1" = 0 ]; then  # Erase, not upgrade
    for kname in `ls -d /lib/modules/*`
    do
        rm -rf $kname/weak-updates/openvswitch
    done
fi
/sbin/depmod -a

%files
%defattr(644,root,root,755)
/etc/depmod.d/%{oname}.conf
/lib/modules/
%attr(755,root,root) /usr/share/%{oname}/scripts/ovs-kmod-manage.sh

%clean
rm -rf $RPM_BUILD_ROOT
