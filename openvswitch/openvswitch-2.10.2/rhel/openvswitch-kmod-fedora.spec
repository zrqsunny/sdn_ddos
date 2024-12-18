# Generated automatically -- do not modify!    -*- buffer-read-only: t -*-
# Spec file for Open vSwitch.

# Copyright (C) 2009, 2010, 2015 Nicira Networks, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without warranty of any kind.

%global debug_package %{nil}

#%define kernel 3.1.5-1.fc16.x86_64
#define kernel %{kernel_source}
%{?kversion:%define kernel %kversion}

Name: openvswitch-kmod
Summary: Open vSwitch Kernel Modules
Group: System Environment/Daemons
URL: http://www.openvswitch.org/
Vendor: OpenSource Security Ralf Spenneberg <ralf@os-s.net>
Version: 2.10.2

# The entire source code is ASL 2.0 except datapath/ which is GPLv2
License: GPLv2
Release: 1%{?dist}
Source: openvswitch-%{version}.tar.gz
#Source1: openvswitch-init
Buildroot: /tmp/openvswitch-xen-rpm

%description
Open vSwitch provides standard network bridging functions augmented with
support for the OpenFlow protocol for remote per-flow control of
traffic. This package contains the kernel modules.

%prep
%setup -q -n openvswitch-%{version}

%build
%configure --with-linux=/lib/modules/%{kernel}/build --enable-ssl
make %{_smp_mflags} -C datapath/linux

%install
rm -rf $RPM_BUILD_ROOT
make INSTALL_MOD_PATH=$RPM_BUILD_ROOT -C datapath/linux modules_install
mkdir -p $RPM_BUILD_ROOT/etc/depmod.d
for module in $RPM_BUILD_ROOT/lib/modules/%{kernel}/extra/*.ko
do
    modname="$(basename ${module})"
    echo "override ${modname%.ko} * extra" >> \
        $RPM_BUILD_ROOT/etc/depmod.d/kmod-openvswitch.conf
    echo "override ${modname%.ko} * weak-updates" >> \
        $RPM_BUILD_ROOT/etc/depmod.d/kmod-openvswitch.conf
done

%clean
rm -rf $RPM_BUILD_ROOT

%post
# Ensure that modprobe will find our modules.
for k in $(cd /lib/modules && /bin/ls); do
    [ -d "/lib/modules/$k/kernel/" ] && depmod -a "$k"
done
if [ -x "/sbin/weak-modules" ]; then
    for m in openvswitch vport-gre vport-stt vport-geneve \
             vport-lisp vport-vxlan; do
        echo "/lib/modules/%{kernel}/extra/$m.ko"
    done | /sbin/weak-modules --add-modules
fi

%postun
for k in $(cd /lib/modules && /bin/ls); do
    [ -d "/lib/modules/$k/kernel/" ] && depmod -a "$k"
done
if [ "$1" = 0 ]; then  # Erase, not upgrade
    if [ -x "/sbin/weak-modules" ]; then
        for m in openvswitch vport-gre vport-stt vport-geneve \
                 vport-lisp vport-vxlan; do
        echo "/lib/modules/%{kernel}/extra/$m.ko"
    done | /sbin/weak-modules --remove-modules
    fi
fi

%files
%defattr(0644,root,root)
/lib/modules/%{kernel}/extra/*.ko
/etc/depmod.d/kmod-openvswitch.conf
%exclude /lib/modules/%{kernel}/modules.*

%changelog
* Wed Sep 21 2011 Kyle Mestery <kmestery@cisco.com>
- Updated for F15
* Wed Jan 12 2011 Ralf Spenneberg <ralf@os-s.net>
- First build on F14
