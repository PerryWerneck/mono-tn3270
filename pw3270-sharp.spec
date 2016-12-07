Summary:		C-Sharp API for pw3270/lib3270
Name:			pw3270-sharp
Version:		1.0
Release:		0
License:		GPL-2.0
Source:			%{name}-%{version}.tar.bz2
URL:			https://portal.softwarepublico.gov.br/social/pw3270/
Group: 			Development/Languages/Mono

BuildRoot:		/var/tmp/%{name}-%{version}

BuildRequires:	mono-core
BuildRequires:  autoconf >= 2.61
BuildRequires:  automake
BuildRequires:  binutils
BuildRequires:  coreutils
BuildRequires:  gcc-c++
BuildRequires:  m4
BuildRequires:  pkgconfig
BuildRequires:	pw3270-devel >= 5.1

Requires:		lib3270 >= 5.1

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
make clean
make Release

%install
rm -rf $RPM_BUILD_ROOT

%makeinstall

%fdupes $RPM_BUILD_ROOT

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)

%changelog

