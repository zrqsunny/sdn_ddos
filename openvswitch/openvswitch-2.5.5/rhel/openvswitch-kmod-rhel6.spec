# Generated automatically -- do not modify!    -*- buffer-read-only: t -*-
# Spec file for Open vSwitch kernel modules on Red Hat Enterprise
# Linux 6.

# Copyright (C) 2011, 2012 Nicira, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without warranty of any kind.

%define oname openvswitch

Name:           %{oname}-kmod
Version:        2.5.5
Release:        1%{?dist}
Summary:        Open vSwitch kernel module

Group:          System/Kernel
License:        GPLv2
URL:            http://openvswitch.org/
Source0:        %{oname}-%{version}.tar.gz
Source1:        %{oname}-kmod.files
BuildRoot:      %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)
BuildRequires:  %kernel_module_package_buildreqs

# Without this we get an empty openvswitch-debuginfo package (whose name
# conflicts with the openvswitch-debuginfo package for OVS userspace).
%undefine _enable_debug_packages

# Use -D 'kversion 2.6.32-131.6.1.el6.x86_64' to build package
# for specified kernel version.
%{?kversion:%define kernel_version %kversion}

# Use -D 'kflavors default debug kdump' to build packages for
# specified kernel variants.
%{!?kflavors:%define kflavors default}

%kernel_module_package -n %{oname} -f %{SOURCE1} %kflavors

%description
Open vSwitch Linux kernel module.

%prep

%setup -n %{oname}-%{version}
cat > %{oname}.conf << EOF
override %{oname} * extra/%{oname}
override %{oname} * weak-updates/%{oname}
EOF

%build
for flavor in %flavors_to_build; do
	mkdir _$flavor
	(cd _$flavor && ../configure --with-linux="%{kernel_source $flavor}")
	%{__make} -C _$flavor/datapath/linux %{?_smp_mflags}
done

%install
export INSTALL_MOD_PATH=$RPM_BUILD_ROOT
export INSTALL_MOD_DIR=extra/%{oname}
for flavor in %flavors_to_build ; do
         make -C %{kernel_source $flavor} modules_install \
                 M="`pwd`"/_$flavor/datapath/linux

         # Cleanup unnecessary kernel-generated module dependency files.
         find $INSTALL_MOD_PATH/lib/modules -iname 'modules.*' -exec rm {} \;
done
install -d %{buildroot}%{_sysconfdir}/depmod.d/
install -m 644 %{oname}.conf %{buildroot}%{_sysconfdir}/depmod.d/

%clean
rm -rf $RPM_BUILD_ROOT
