# Generated automatically -- do not modify!    -*- buffer-read-only: t -*-
# Spec file for Open vSwitch.

# Copyright (C) 2009, 2010, 2013, 2014, 2015 Nicira Networks, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without warranty of any kind.
#
# If tests have to be skipped while building, specify the '--without check'
# option. For example:
# rpmbuild -bb --without check rhel/openvswitch-fedora.spec

#%define kernel 2.6.40.4-5.fc15.x86_64

# If libcap-ng isn't available and there is no need for running OVS
# as regular user, specify the '--without libcapng'
%bcond_without libcapng
# To enable DPDK support, specify '--with dpdk' when building
%bcond_with dpdk

# Enable PIE, bz#955181
%global _hardened_build 1

# some distros (e.g: RHEL-7) don't define _rundir macro yet
# Fedora 15 onwards uses /run as _rundir
%if 0%{!?_rundir:1}
%define _rundir /run
%endif

Name: openvswitch
Summary: Open vSwitch
Group: System Environment/Daemons
URL: http://www.openvswitch.org/
Version: 2.5.5

# Nearly all of openvswitch is ASL 2.0.  The bugtool is LGPLv2+, and the
# lib/sflow*.[ch] files are SISSL
# datapath/ is GPLv2 (although not built into any of the binary packages)
License: ASL 2.0 and LGPLv2+ and SISSL
Release: 1%{?dist}
Source: http://openvswitch.org/releases/%{name}-%{version}.tar.gz

BuildRequires: autoconf automake libtool
BuildRequires: systemd-units openssl openssl-devel
BuildRequires: python python-twisted-core python-zope-interface PyQt4
BuildRequires: desktop-file-utils
BuildRequires: groff graphviz
BuildRequires: checkpolicy, selinux-policy-devel
# make check dependencies
BuildRequires: procps-ng
%if %{with libcapng}
BuildRequires: libcap-ng libcap-ng-devel
%endif
%if %{with dpdk}
BuildRequires: dpdk-devel >= 2.2.0
Provides: %{name}-dpdk = %{version}-%{release}
%endif

Requires: openssl iproute module-init-tools
#Upstream kernel commit 4f647e0a3c37b8d5086214128614a136064110c3
#Requires: kernel >= 3.15.0-0

Requires(post): systemd-units
Requires(preun): systemd-units
Requires(postun): systemd-units
Obsoletes: openvswitch-controller <= 0:2.1.0-1

%bcond_without check

%description
Open vSwitch provides standard network bridging functions and
support for the OpenFlow protocol for remote per-flow control of
traffic.

%package selinux-policy
Summary: Open vSwitch SELinux policy
License: ASL 2.0
BuildArch: noarch
Requires: selinux-policy-targeted

%description selinux-policy
Tailored Open vSwitch SELinux policy

%package -n python-openvswitch
Summary: Open vSwitch python bindings
License: ASL 2.0
BuildArch: noarch
Requires: python

%description -n python-openvswitch
Python bindings for the Open vSwitch database

%package test
Summary: Open vSwitch testing utilities
License: ASL 2.0
BuildArch: noarch
Requires: python-openvswitch = %{version}-%{release}
Requires: python python-twisted-core python-twisted-web

%description test
Utilities that are useful to diagnose performance and connectivity
issues in Open vSwitch setup.

%package devel
Summary: Open vSwitch OpenFlow development package (library, headers)
License: ASL 2.0
Provides: openvswitch-static = %{version}-%{release}

%description devel
This provides static library, libopenswitch.a and the openvswitch header
files needed to build an external application.

%package ovn
Summary: Open vSwitch - Open Virtual Network support
License: ASL 2.0
Requires: openvswitch

%description ovn
OVN, the Open Virtual Network, is a system to support virtual network
abstraction.  OVN complements the existing capabilities of OVS to add
native support for virtual network abstractions, such as virtual L2 and L3
overlays and security groups.


%prep
%setup -q

%build
%configure \
%if %{with libcapng}
	--enable-libcapng \
%else
	--disable-libcapng \
%endif
%if %{with dpdk}
	--with-dpdk=$(dirname %{_datadir}/dpdk/*/.config) \
%endif
	--enable-ssl \
	--with-pkidir=%{_sharedstatedir}/openvswitch/pki

make %{?_smp_mflags}
cd selinux
make -f %{_datadir}/selinux/devel/Makefile

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT

install -d -m 0755 $RPM_BUILD_ROOT%{_sysconfdir}/openvswitch

install -p -D -m 0644 \
        rhel/usr_share_openvswitch_scripts_systemd_sysconfig.template \
        $RPM_BUILD_ROOT/%{_sysconfdir}/sysconfig/openvswitch
for service in openvswitch ovsdb-server ovs-vswitchd \
		ovn-controller ovn-controller-vtep ovn-northd; do
	install -p -D -m 0644 \
			rhel/usr_lib_systemd_system_${service}.service \
			$RPM_BUILD_ROOT%{_unitdir}/${service}.service
done
install -m 0755 rhel/etc_init.d_openvswitch \
        $RPM_BUILD_ROOT%{_datadir}/openvswitch/scripts/openvswitch.init

install -p -D -m 0644 rhel/etc_logrotate.d_openvswitch \
        $RPM_BUILD_ROOT/%{_sysconfdir}/logrotate.d/openvswitch

install -m 0644 vswitchd/vswitch.ovsschema \
        $RPM_BUILD_ROOT/%{_datadir}/openvswitch/vswitch.ovsschema

install -d -m 0755 $RPM_BUILD_ROOT/%{_sysconfdir}/sysconfig/network-scripts/
install -p -m 0755 rhel/etc_sysconfig_network-scripts_ifdown-ovs \
        $RPM_BUILD_ROOT/%{_sysconfdir}/sysconfig/network-scripts/ifdown-ovs
install -p -m 0755 rhel/etc_sysconfig_network-scripts_ifup-ovs \
        $RPM_BUILD_ROOT/%{_sysconfdir}/sysconfig/network-scripts/ifup-ovs

install -d -m 0755 $RPM_BUILD_ROOT%{python_sitelib}
mv $RPM_BUILD_ROOT/%{_datadir}/openvswitch/python/* \
   $RPM_BUILD_ROOT%{python_sitelib}
rmdir $RPM_BUILD_ROOT/%{_datadir}/openvswitch/python/

install -d -m 0755 $RPM_BUILD_ROOT/%{_sharedstatedir}/openvswitch

touch $RPM_BUILD_ROOT%{_sysconfdir}/openvswitch/conf.db
touch $RPM_BUILD_ROOT%{_sysconfdir}/openvswitch/system-id.conf

install -p -m 644 -D selinux/openvswitch-custom.pp \
        $RPM_BUILD_ROOT%{_datadir}/selinux/packages/%{name}/openvswitch-custom.pp

# remove unpackaged files
rm -f $RPM_BUILD_ROOT%{_bindir}/ovs-benchmark \
        $RPM_BUILD_ROOT%{_bindir}/ovs-parse-backtrace \
        $RPM_BUILD_ROOT%{_bindir}/ovs-pcap \
        $RPM_BUILD_ROOT%{_bindir}/ovs-tcpundump \
        $RPM_BUILD_ROOT%{_sbindir}/ovs-vlan-bug-workaround \
        $RPM_BUILD_ROOT%{_mandir}/man1/ovs-benchmark.1 \
        $RPM_BUILD_ROOT%{_mandir}/man1/ovs-pcap.1 \
        $RPM_BUILD_ROOT%{_mandir}/man1/ovs-tcpundump.1 \
        $RPM_BUILD_ROOT%{_mandir}/man8/ovs-vlan-bug-workaround.8 \
        $RPM_BUILD_ROOT%{_datadir}/openvswitch/scripts/ovs-save

%check
%if %{with check}
    if make check TESTSUITEFLAGS='%{_smp_mflags}' ||
       make check TESTSUITEFLAGS='--recheck'; then :;
    else
        cat tests/testsuite.log
        exit 1
    fi
%endif

%clean
rm -rf $RPM_BUILD_ROOT

%preun
%if 0%{?systemd_preun:1}
    %systemd_preun %{name}.service
%else
    if [ $1 -eq 0 ] ; then
    # Package removal, not upgrade
        /bin/systemctl --no-reload disable %{name}.service >/dev/null 2>&1 || :
        /bin/systemctl stop %{name}.service >/dev/null 2>&1 || :
    fi
%endif

%preun ovn
%if 0%{?systemd_preun:1}
    %systemd_preun ovn-controller.service
    %systemd_preun ovn-controller-vtep.service
    %systemd_preun ovn-northd.service
%else
    if [ $1 -eq 0 ] ; then
    # Package removal, not upgrade
        /bin/systemctl --no-reload disable ovn-controller.service >/dev/null 2>&1 || :
        /bin/systemctl stop ovn-controller.service >/dev/null 2>&1 || :
        /bin/systemctl --no-reload disable ovn-controller-vtep.service >/dev/null 2>&1 || :
        /bin/systemctl stop ovn-controller-vtep.service >/dev/null 2>&1 || :
        /bin/systemctl --no-reload disable ovn-northd.service >/dev/null 2>&1 || :
        /bin/systemctl stop ovn-northd.service >/dev/null 2>&1 || :
    fi
%endif

%post
%if 0%{?systemd_post:1}
    %systemd_post %{name}.service
%else
    # Package install, not upgrade
    if [ $1 -eq 1 ]; then
        /bin/systemctl daemon-reload >dev/null || :
    fi
%endif

%post ovn
%if 0%{?systemd_post:1}
    %systemd_post ovn-controller.service
    %systemd_post ovn-controller-vtep.service
    %systemd_post ovn-northd.service
%else
    # Package install, not upgrade
    if [ $1 -eq 1 ]; then
        /bin/systemctl daemon-reload >dev/null || :
    fi
%endif

%post selinux-policy
/usr/sbin/semodule -i %{_datadir}/selinux/packages/%{name}/openvswitch-custom.pp &> /dev/null || :

%postun
%if 0%{?systemd_postun:1}
    %systemd_postun %{name}.service
%else
    /bin/systemctl daemon-reload >/dev/null 2>&1 || :
%endif

%postun ovn
%if 0%{?systemd_postun_with_restart:1}
    %systemd_postun_with_restart ovn-controller.service
    %systemd_postun_with_restart ovn-controller-vtep.service
    %systemd_postun_with_restart ovn-northd.service
%else
    /bin/systemctl daemon-reload >/dev/null 2>&1 || :
    if [ "$1" -ge "1" ] ; then
    # Package upgrade, not uninstall
        /bin/systemctl try-restart ovn-controller.service >/dev/null 2>&1 || :
        /bin/systemctl try-restart ovn-controller-vtep.service >/dev/null 2>&1 || :
        /bin/systemctl try-restart ovn-northd.service >/dev/null 2>&1 || :
    fi
%endif

%postun selinux-policy
if [ $1 -eq 0 ] ; then
  /usr/sbin/semodule -r openvswitch-custom &> /dev/null || :
fi

%files selinux-policy
%defattr(-,root,root)
%{_datadir}/selinux/packages/%{name}/openvswitch-custom.pp

%files -n python-openvswitch
%{python_sitelib}/ovs
%doc COPYING

%files test
%{_bindir}/ovs-test
%{_bindir}/ovs-vlan-test
%{_bindir}/ovs-l3ping
%{_mandir}/man8/ovs-test.8*
%{_mandir}/man8/ovs-vlan-test.8*
%{_mandir}/man8/ovs-l3ping.8*
%{python_sitelib}/ovstest

%files devel
%{_libdir}/*.a
%{_libdir}/*.la
%{_libdir}/pkgconfig/*.pc
%{_includedir}/openvswitch/*
%{_includedir}/openflow/*

%files
%defattr(-,root,root)
%{_sysconfdir}/bash_completion.d/ovs-appctl-bashcomp.bash
%{_sysconfdir}/bash_completion.d/ovs-vsctl-bashcomp.bash
%dir %{_sysconfdir}/openvswitch
%config %ghost %{_sysconfdir}/openvswitch/conf.db
%config %ghost %{_sysconfdir}/openvswitch/system-id.conf
%config(noreplace) %{_sysconfdir}/sysconfig/openvswitch
%config(noreplace) %{_sysconfdir}/logrotate.d/openvswitch
%{_unitdir}/openvswitch.service
%{_unitdir}/ovsdb-server.service
%{_unitdir}/ovs-vswitchd.service
%{_datadir}/openvswitch/scripts/openvswitch.init
%{_sysconfdir}/sysconfig/network-scripts/ifup-ovs
%{_sysconfdir}/sysconfig/network-scripts/ifdown-ovs
%{_datadir}/openvswitch/bugtool-plugins/
%{_datadir}/openvswitch/scripts/ovs-bugtool-*
%{_datadir}/openvswitch/scripts/ovs-check-dead-ifs
%{_datadir}/openvswitch/scripts/ovs-lib
%{_datadir}/openvswitch/scripts/ovs-vtep
%{_datadir}/openvswitch/scripts/ovs-ctl
%config %{_datadir}/openvswitch/vswitch.ovsschema
%config %{_datadir}/openvswitch/vtep.ovsschema
%{_bindir}/ovs-appctl
%{_bindir}/ovs-docker
%{_bindir}/ovs-dpctl
%{_bindir}/ovs-dpctl-top
%{_bindir}/ovs-ofctl
%{_bindir}/ovs-vsctl
%{_bindir}/ovsdb-client
%{_bindir}/ovsdb-tool
%{_bindir}/ovs-testcontroller
%{_bindir}/ovs-pki
%{_bindir}/vtep-ctl
%{_sbindir}/ovs-bugtool
%{_sbindir}/ovs-vswitchd
%{_sbindir}/ovsdb-server
%{_mandir}/man1/ovsdb-client.1*
%{_mandir}/man1/ovsdb-server.1*
%{_mandir}/man1/ovsdb-tool.1*
%{_mandir}/man5/ovs-vswitchd.conf.db.5*
%{_mandir}/man5/vtep.5*
%{_mandir}/man8/vtep-ctl.8*
%{_mandir}/man8/ovs-appctl.8*
%{_mandir}/man8/ovs-bugtool.8*
%{_mandir}/man8/ovs-ctl.8*
%{_mandir}/man8/ovs-dpctl.8*
%{_mandir}/man8/ovs-dpctl-top.8*
%{_mandir}/man8/ovs-ofctl.8*
%{_mandir}/man8/ovs-pki.8*
%{_mandir}/man8/ovs-vsctl.8*
%{_mandir}/man8/ovs-vswitchd.8*
%{_mandir}/man8/ovs-parse-backtrace.8*
%{_mandir}/man8/ovs-testcontroller.8*
%doc COPYING DESIGN.md INSTALL.SSL.md NOTICE README.md WHY-OVS.md
%doc FAQ.md NEWS INSTALL.DPDK.md rhel/README.RHEL
/var/lib/openvswitch
/var/log/openvswitch
%ghost %attr(755,root,root) %{_rundir}/openvswitch

%files ovn
%{_bindir}/ovn-controller
%{_bindir}/ovn-controller-vtep
%{_bindir}/ovn-docker-overlay-driver
%{_bindir}/ovn-docker-underlay-driver
%{_bindir}/ovn-nbctl
%{_bindir}/ovn-northd
%{_bindir}/ovn-sbctl
%{_datadir}/openvswitch/scripts/ovn-ctl
%{_mandir}/man8/ovs-testcontroller.8*
%{_mandir}/man5/ovn-nb.5*
%{_mandir}/man5/ovn-sb.5*
%{_mandir}/man7/ovn-architecture.7*
%{_mandir}/man8/ovn-controller.8*
%{_mandir}/man8/ovn-controller-vtep.8*
%{_mandir}/man8/ovn-ctl.8*
%{_mandir}/man8/ovn-nbctl.8*
%{_mandir}/man8/ovn-northd.8*
%{_mandir}/man8/ovn-sbctl.8*
%config %{_datadir}/openvswitch/ovn-nb.ovsschema
%config %{_datadir}/openvswitch/ovn-sb.ovsschema
%{_unitdir}/ovn-controller.service
%{_unitdir}/ovn-controller-vtep.service
%{_unitdir}/ovn-northd.service

%changelog
* Wed Jan 12 2011 Ralf Spenneberg <ralf@os-s.net>
- First build on F14
