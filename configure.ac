# initial information about the project
AC_INIT([ls-color],[2.0],[agpchil@gmail.com])

# check if the source folder is correct
AC_CONFIG_SRCDIR([src/ls-color.c])

# Checks for programs

# check for C compiler
AC_PROG_CC

# automake initialisation (mandatory) and check for minimal automake API version 1.9
AM_INIT_AUTOMAKE([1.9])

# use the C compiler for the following checks
AC_LANG([C])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([strings.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# distribute additional compiler and linker flags
# --> set these variables instead of CXXFLAGS or LDFLAGS
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([LIBS])

# files to generate via autotools (.am or .in source files)
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([src/Makefile])

# generate the final Makefile etc.
AC_OUTPUT
