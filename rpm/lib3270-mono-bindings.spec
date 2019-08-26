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

%define libname tn3270-sharp

Summary:	Mono binding for pw3270/lib3270
Name:		lib3270-mono-bindings
Version:	5.2
Release:	0
License:	LGPL-3.0
Source:		%{name}-%{version}.tar.xz
URL:		https://portal.softwarepublico.gov.br/social/pw3270/
Group: 		Development/Languages/Other

BuildRoot:	/var/tmp/%{name}-%{version}

BuildRequires:	mono-devel
BuildRequires:  autoconf >= 2.61
BuildRequires:  automake
BuildRequires:  binutils
BuildRequires:  coreutils
BuildRequires:  gcc-c++
BuildRequires:  m4
BuildRequires:  pkgconfig
BuildRequires:  fdupes
BuildRequires:  pkgconfig(ipc3270)

%description

Mono bindings for tn3270 acesss using lib3270 or pw3270.

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

%doc README.md LICENCA LICENSE AUTHORS

/usr/lib/mono/gac/%{libname}

%dir /usr/lib/mono/%{libname}-5.2
/usr/lib/mono/%{libname}-5.2/tn3270-sharp.dll

%{_libdir}/lib3270-mono.so
%{_libdir}/lib3270-mono.so.5
%{_libdir}/lib3270-mono.so.5.2
%{_libdir}/pkgconfig/tn3270-sharp.pc

%dir /usr/share/gapi-2.0
%dir /usr/share/gapi-2.0/%{libname}
/usr/share/gapi-2.0/%{libname}/tn3270-sharp.xml

%post
/sbin/ldconfig
exit 0

%postun
/sbin/ldconfig
exit 0

%changelog


