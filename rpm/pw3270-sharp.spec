#
# spec file for package pw3270-sharp
#
# Copyright (c) 2015 SUSE LINUX GmbH, Nuernberg, Germany.
# Copyright (C) <2008> <Banco do Brasil S.A.>
#
# All modifications and additions to the file contributed by third parties
# remain the property of their copyright owners, unless otherwise agreed
# upon. The license for this file, and modifications and additions to the
# file, is the same license as for the pristine package itself (unless the
# license for the pristine package is not an Open Source License, in which
# case the license is the MIT License). An "Open Source License" is a
# license that conforms to the Open Source Definition (Version 1.9)
# published by the Open Source Initiative.

# Please submit bugfixes or comments via http://bugs.opensuse.org/
#

%define vrslib %(pkg-config --modversion lib3270)

Summary:		C-Sharp API for pw3270/lib3270
Name:			pw3270-sharp
Version:		1.0
Release:		0
License:		GPL-2.0
Source:			%{name}-%{version}.tar.bz2
URL:			https://portal.softwarepublico.gov.br/social/pw3270/
Group: 			Development/Languages/Mono

BuildRoot:		/var/tmp/%{name}-%{version}

BuildRequires:	mono-devel
BuildRequires:  autoconf >= 2.61
BuildRequires:  automake
BuildRequires:  binutils
BuildRequires:  coreutils
BuildRequires:  gcc-c++
BuildRequires:  m4
BuildRequires:  pkgconfig
BuildRequires:  fdupes
BuildRequires:	pkgconfig(pw3270)
BuildRequires:	pkgconfig(lib3270)
BuildRequires:	gettext-devel

Requires:		lib3270 = %{vrslib}

%description

C-Sharp API for tn3270 acesss using pw3270 ou lib3270.

%prep

%setup

export CFLAGS="$RPM_OPT_FLAGS"
export CXXFLAGS="$RPM_OPT_FLAGS"
export FFLAGS="$RPM_OPT_FLAGS"

aclocal
autoconf
%configure

%build
%define debug_package %{nil}

make clean
make Release

%install
rm -rf $RPM_BUILD_ROOT

%make_install

%fdupes $RPM_BUILD_ROOT

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)

%doc README.md

%{_libdir}/lib3270-mono.*
/usr/lib/mono/gac/%{name}

%dir /usr/share/gapi-2.0
%dir /usr/share/gapi-2.0/%{name}
/usr/share/gapi-2.0/%{name}/%{name}.xml

%{_libdir}/pkgconfig/%{name}.pc
/usr/lib/mono/%{name}-*

%post
/sbin/ldconfig
exit 0

%postun
/sbin/ldconfig
exit 0

%changelog


