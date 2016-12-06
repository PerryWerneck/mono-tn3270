
dnl Process this file with autoconf to produce a configure script.

dnl The minimum version of autoconf required.
AC_PREREQ(2.59)

dnl Initialise automake with the package name, version and
dnl bug-reporting address.
AC_INIT([lib3270-mono], [1.0], [perry.werneck@gmail.com])

dnl Place auxilliary scripts here.
AC_CONFIG_AUX_DIR([scripts])

dnl Compute the canonical host-system type
AC_CANONICAL_HOST

dnl Put macro definitions here (though they aren't used).
AC_CONFIG_HEADER([src/include/config.h])

dnl Initialise automake stuff.
AM_INIT_AUTOMAKE

dnl Check for iconv
AM_ICONV

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_SED
AC_PROG_LN_S

AC_LANG([C++])

dnl ---------------------------------------------------------------------------
dnl Initialize defaults
dnl ---------------------------------------------------------------------------
DLLFLAGS="-shared -Wl,-soname,\$(@F)"
DBG_CFLAGS="-DDEBUG=1"
RLS_CFLAGS="-DNDEBUG=1"

dnl ---------------------------------------------------------------------------
dnl Check for OS specifics
dnl ---------------------------------------------------------------------------

case "$host" in
	*-mingw32)
		RLS_LDFLAGS="-Wl,--strip-all"
		DBG_LDFLAGS=""
		APP_LDFLAGS=""

		DBG_DATADIR=""
		RLS_DATADIR=""

		EXEEXT=".exe"

		DLLPREFIX=""
		DLLEXT=".dll"

		CFLAGS="$CFLAGS -Wall -Werror -D_WIN32_WINNT=0x0600"
		LDFLAGS="-static-libstdc++ -static-libgcc $LDFLAGS"
		LIBS="$LIBS -lws2_32 -lntdll -lwtsapi32"

		LOGDIR=.
		;;

 	*)
		RLS_LDFLAGS=""
		DBG_LDFLAGS=""
		APP_LDFLAGS=""

		DBG_DATADIR="-DDATADIR=."
		DBG_CFLAGS="-fstack-check $DBG_CFLAGS"

		RLS_DATADIR="-DDATADIR=\$(datarootdir)/\$(PACKAGE_NAME)"

		EXEEXT=""

		DLLPREFIX="lib"
		DLLEXT=".so"

		CFLAGS="$CFLAGS -Wall -Werror"

		# LIBS="-Wl,--no-allow-shlib-undefined,--as-needed,--no-undefined -pthread $LIBS"
		LIBS="-pthread $LIBS"

		LOGDIR="/var/log"


esac

AC_SUBST(LIBS)

AC_SUBST(DBG_DATADIR)
AC_SUBST(DBG_CFLAGS)

AC_SUBST(RLS_DATADIR)
AC_SUBST(RLS_CFLAGS)

AC_SUBST(DBG_LDFLAGS)
AC_SUBST(RLS_LDFLAGS)
AC_SUBST(APP_LDFLAGS)

AC_SUBST(EXEEXT)
AC_SUBST(DLLEXT)
AC_SUBST(DLLPREFIX)

AC_SUBST(LOGDIR)

dnl ---------------------------------------------------------------------------
dnl Check for other programs
dnl ---------------------------------------------------------------------------
AC_PATH_TOOL([STRIP], [strip])
AC_PATH_TOOL([RPMBUILD], [rpmbuild], [no])
AC_PATH_TOOL([MAKENSIS], [makensis], [no])
AC_PATH_TOOL([VALGRIND], [valgrind], [no])
AC_PATH_TOOL([WINDRES], [windres], [no])
AC_PATH_TOOL([ZIP], [zip], [zip])
AC_PATH_TOOL([MCS], [mcs], [mcs])

AC_PATH_PROG([MONO], [mono], [no])

dnl ---------------------------------------------------------------------------
dnl Version info
dnl ---------------------------------------------------------------------------

AC_DEFINE(PACKAGE_RELEASE,APP_LEVEL)
AC_SUBST(PACKAGE_RELEASE, APP_LEVEL)

app_vrs_major=$(echo $VERSION | cut -d. -f1)
app_vrs_minor=$(echo $VERSION | cut -d. -f2)

AC_SUBST(PACKAGE_MAJOR_VERSION,$app_vrs_major)
AC_SUBST(PACKAGE_MINOR_VERSION,$app_vrs_minor)

AC_DEFINE_UNQUOTED(PACKAGE_MAJOR_VERSION, $app_vrs_major)
AC_DEFINE_UNQUOTED(PACKAGE_MINOR_VERSION, $app_vrs_minor)

AC_SUBST(PACKAGE_MAJOR_VERSION,$app_vrs_major)
AC_SUBST(PACKAGE_MINOR_VERSION,$app_vrs_minor)

app_cv_description="C# Bindings for lib3270/pw3270"

AC_DEFINE_UNQUOTED(PACKAGE_DESCRIPTION,"$app_cv_description")
AC_SUBST(PACKAGE_DESCRIPTION,"$app_cv_description")

dnl ---------------------------------------------------------------------------
dnl Check for integer types & library functions
dnl ---------------------------------------------------------------------------

AC_CHECK_TYPES([pid_t, uint8_t, uint16_t, uint32_t, int32_t, uint64_t, int64_t])

dnl ---------------------------------------------------------------------------
dnl Check for libintl
dnl ---------------------------------------------------------------------------

AC_PATH_TOOL([XGETTEXT], [xgettext], [no])
AC_PATH_TOOL([MSGCAT], [msgcat], [no])
AC_PATH_TOOL([MSGINIT], [msginit], [no])
AC_PATH_TOOL([MSGMERGE], [msgmerge], [no])
AC_PATH_TOOL([MSGFMT], [msgfmt], [no])

AC_CHECK_HEADER(libintl.h, [
	AC_DEFINE(HAVE_LIBINTL, 1)
])

dnl --------------------------------------------------
dnl test for clock_gettime
dnl --------------------------------------------------

AC_CHECK_FUNCS(clock_gettime, [], [
  AC_CHECK_LIB(rt, clock_gettime, [
    AC_DEFINE(HAVE_CLOCK_GETTIME, 1)
    LIBS="$LIBS -lrt"
  ])
])

dnl --------------------------------------------------
dnl test for in_addr_t
dnl --------------------------------------------------
AC_MSG_CHECKING(for in_addr_t in netinet/in.h)
AC_EGREP_HEADER(in_addr_t, netinet/in.h,
 [ AC_DEFINE([HAVE_IN_ADDR_T], [1], [Define to 1 if in_addr_t is available.]) AC_MSG_RESULT(yes) ],
 AC_MSG_RESULT(no))

dnl ---------------------------------------------------------------------------
dnl test for reentrant time routines
dnl ---------------------------------------------------------------------------

AC_MSG_CHECKING(for localtime_r in time.h)
AC_EGREP_HEADER(localtime_r, time.h,
 [ AC_DEFINE([HAVE_LOCALTIME_R], [1], [Define to 1 if localtime_r is available.]) AC_MSG_RESULT(yes) ],
 AC_MSG_RESULT(no))

AC_MSG_CHECKING(for gmtime_r in time.h)
AC_EGREP_HEADER(gmtime_r, time.h,
 [ AC_DEFINE([HAVE_GMTIME_R], [1], [Define to 1 if gmtime_r is available.]) AC_MSG_RESULT(yes) ],
 AC_MSG_RESULT(no))

dnl ---------------------------------------------------------------------------
dnl Check for C++ 2011 support
dnl ---------------------------------------------------------------------------
AC_DEFUN([AX_CHECK_COMPILE_FLAG],
[AC_PREREQ(2.59)dnl for _AC_LANG_PREFIX
AS_VAR_PUSHDEF([CACHEVAR],[ax_cv_check_[]_AC_LANG_ABBREV[]flags_$4_$1])dnl
AC_CACHE_CHECK([whether _AC_LANG compiler accepts $1], CACHEVAR, [
  ax_check_save_flags=$[]_AC_LANG_PREFIX[]FLAGS
  _AC_LANG_PREFIX[]FLAGS="$[]_AC_LANG_PREFIX[]FLAGS $4 $1"
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM()],
    [AS_VAR_SET(CACHEVAR,[yes])],
    [AS_VAR_SET(CACHEVAR,[no])])
  _AC_LANG_PREFIX[]FLAGS=$ax_check_save_flags])
AS_IF([test x"AS_VAR_GET(CACHEVAR)" = xyes],
  [m4_default([$2], :)],
  [m4_default([$3], :)])
AS_VAR_POPDEF([CACHEVAR])dnl
])dnl AX_CHECK_COMPILE_FLAGS

AX_CHECK_COMPILE_FLAG([-std=gnu++11], [CFLAGS="$CFLAGS -std=gnu++11"])

dnl ---------------------------------------------------------------------------
dnl Check for ELF symbol visibility support
dnl ---------------------------------------------------------------------------
m4_define([GLIB_CHECK_COMPILE_WARNINGS],
[m4_ifvaln([$1], [AC_LANG_CONFTEST([$1])])dnl
rm -f conftest.$ac_objext
glib_ac_compile_save="$ac_compile"
ac_compile='$CC -c $CFLAGS $CPPFLAGS conftest.$ac_ext'
AS_IF([_AC_EVAL_STDERR($ac_compile) &&
         AC_TRY_COMMAND([(if test -s conftest.err; then false ; else true; fi)])],
      [$2],
      [echo "$as_me: failed program was:" >&AS_MESSAGE_LOG_FD
cat conftest.$ac_ext >&AS_MESSAGE_LOG_FD
m4_ifvaln([$3],[$3])dnl])
ac_compile="$glib_ac_compile_save"
rm -f conftest.$ac_objext conftest.err m4_ifval([$1], [conftest.$ac_ext])[]dnl
])# GLIB_CHECK_COMPILE_WARNINGS

AC_MSG_CHECKING(for GNUC visibility attribute)
GLIB_CHECK_COMPILE_WARNINGS([
void
__attribute__ ((visibility ("hidden")))
     f_hidden (void)
{
}
void
__attribute__ ((visibility ("internal")))
     f_internal (void)
{
}
void
__attribute__ ((visibility ("protected")))
     f_protected (void)
{
}
void
__attribute__ ((visibility ("default")))
     f_default (void)
{
}
int main (int argc, char **argv)
{
        f_hidden();
        f_internal();
        f_protected();
        f_default();
        return 0;
}
],g_have_gnuc_visibility=yes,g_have_gnuc_visibility=no)
AC_MSG_RESULT($g_have_gnuc_visibility)
if test x$g_have_gnuc_visibility = xyes; then
  AC_DEFINE(HAVE_GNUC_VISIBILITY, 1, [supports GCC visibility attributes])
fi

dnl ---------------------------------------------------------------------------
dnl Check for compiler visibility flag
dnl ---------------------------------------------------------------------------
AC_MSG_CHECKING(whether $CC accepts -fvisibility=hidden)
AC_CACHE_VAL(app_cv_fvisibility_ok,
[ac_save_cc="$CC"
CC="$CC -fvisibility=hidden"
AC_TRY_RUN([int main() { return 0; }],
  app_cv_fvisibility_ok=yes,
  app_cv_fvisibility_ok=no,
  app_cv_fvisibility_ok=no)
CC="$ac_save_cc"])
AC_MSG_RESULT($app_cv_fvisibility_ok)
if test $app_cv_fvisibility_ok = yes; then
  CFLAGS="$CFLAGS -fvisibility=hidden"
fi

dnl ---------------------------------------------------------------------------
dnl Check for pic
dnl ---------------------------------------------------------------------------
AC_ARG_ENABLE([pic],
	[AS_HELP_STRING([--disable-pic], [disable support for PIC libraries (required to compile on 64bits)])],
[
	app_cv_pic="$enableval"
],[

	case "$host" in
		*-mingw32)
			app_cv_pic="no"
		;;

 	s390x-*)
			app_cv_pic="yes"
		;;

	*)
		if test "$host_cpu" = "x86_64"; then
			app_cv_pic="yes"
		else
			app_cv_pic="no"
		fi
	esac
])

if test "$app_cv_pic" == "yes"; then
	CFLAGS="$CFLAGS -fPIC"
fi

dnl ---------------------------------------------------------------------------
dnl Output config
dnl ---------------------------------------------------------------------------

AC_SUBST(DLLFLAGS)
AC_SUBST(BASEDIR,$ac_pwd)

dnl ---------------------------------------------------------------------------
dnl Configure which files to generate.
dnl ---------------------------------------------------------------------------

AC_CONFIG_FILES(Makefile)
AC_CONFIG_FILES(src/native/Makefile)
AC_CONFIG_FILES(src/tn3270-sharp/Makefile)

dnl ---------------------------------------------------------------------------
dnl Output the generated config.status script.
dnl ---------------------------------------------------------------------------
AC_OUTPUT
