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

%define __strip %{_mingw32_strip}
%define __objdump %{_mingw32_objdump}
%define _use_internal_dependency_generator 0
%define __find_requires %{_mingw32_findrequires}
%define __find_provides %{_mingw32_findprovides}
%define __os_install_post %{_mingw32_debug_install_post} \
                          %{_mingw32_install_post}

#---[ Package header ]------------------------------------------------------------------------------------------------

Summary:		A .NET library for TN3270
Name:			mingw32-mono-tn3270
Version:		5.2
Release:		0
License:		LGPL-3.0
Source:			mono-tn3270-%{version}.tar.xz
URL:			https://github.com/PerryWerneck/mono-tn3270
Group: 			Development/Languages/Other

BuildRoot:		/var/tmp/%{name}-%{version}

BuildRequires:	mono-devel
BuildRequires:	autoconf >= 2.61
BuildRequires:	automake
BuildRequires:	binutils
BuildRequires:	coreutils
BuildRequires:	fdupes

BuildRequires:	mingw32-cross-binutils
BuildRequires:	mingw32-cross-gcc
BuildRequires:	mingw32-cross-gcc-c++
BuildRequires:	mingw32-cross-pkg-config
BuildRequires:	mingw32-filesystem

BuildRequires:	mingw32(lib:iconv)
BuildRequires:	mingw32(lib:intl)

BuildRequires:	mingw32(pkg:ipc3270) 


%description
A .NET library for TN3270

#---[ Library ]-------------------------------------------------------------------------------------------------------

%define _product %(i686-w64-mingw32-pkg-config --variable=product_name lib3270)
%define MAJOR_VERSION %(echo %{version} | cut -d. -f1)
%define MINOR_VERSION %(echo %{version} | cut -d. -f2)
%define _libvrs %{MAJOR_VERSION}_%{MINOR_VERSION}

%package -n %{name}-%{_libvrs}
Summary:		A .NET library for TN3270
Group:			Development/Languages/Other

%description -n %{name}-%{_libvrs}
A .NET library for TN3270

See more details at https://softwarepublico.gov.br/social/pw3270/

#---[ Development package ]-------------------------------------------------------------------------------------------

%package devel
Summary: Devel files for TN3270 .NET library

%description devel
Development files for %{name}.

#---[ Build & Install ]-----------------------------------------------------------------------------------------------

%prep

%setup -n mono-tn3270-%{version}

NOCONFIGURE=1 \
	./autogen.sh

%{_mingw32_configure}

%build
make all %{?_smp_mflags}

%{_mingw32_strip} \
	--strip-all \
    .bin/Release/*.dll

%install

#%make_install
make DESTDIR=%{buildroot} install-native

%fdupes %{buildroot}/%{_prefix}

%files -n %{name}-%{_libvrs}
%defattr(-,root,root)

# https://en.opensuse.org/openSUSE:Packaging_for_Leap#RPM_Distro_Version_Macros
%if 0%{?sle_version} > 120200
%doc AUTHORS README.md
%license LICENSE
%else
%doc AUTHORS README.md LICENSE
%endif

%{_mingw32_libdir}/*.dll
%{_mingw32_libdir}/*.dll.%{MAJOR_VERSION}
%{_mingw32_libdir}/*.dll.%{MAJOR_VERSION}.%{MINOR_VERSION}

#/usr/lib/mono/gac
#/usr/share/gapi-2.0

#/usr/lib/mono/*

%files devel
%defattr(-,root,root)
#%{_mingw32_libdir}/pkgconfig/*.pc

%changelog


