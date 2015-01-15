#
# Try to find the LIBHIDAPI library
#
# Once done this will define
#
# ::
#
#   LIBHIDAPI_FOUND - System has LIBHIDAPI
#   LIBHIDAPI_INCLUDE_DIR - The LIBHIDAPI include directory
#   LIBHIDAPI_LIBRARIES - The libraries needed to use LIBHIDAPI
#   LIBHIDAPI_DEFINITIONS - Compiler switches required for using LIBHIDAPI
#   LIBHIDAPI_VERSION_STRING - the version of LIBHIDAPI found (since CMake 2.8.8)

#=============================================================================

# use pkg-config to get the directories and then use these values
# in the find_path() and find_library() calls
find_package(PkgConfig QUIET)
PKG_CHECK_MODULES(PC_LIBHIDAPI QUIET hidapi-libusb)
set(LIBHIDAPI_DEFINITIONS ${PC_LIBHIDAPI_CFLAGS_OTHER})

find_path(LIBHIDAPI_INCLUDE_DIR NAMES hidapi.h
   HINTS
   ${PC_LIBHIDAPI_INCLUDEDIR}
   ${PC_LIBHIDAPI_INCLUDE_DIRS}
   )

find_library(LIBHIDAPI_LIBRARIES NAMES hidapi-libusb hidapi-hidraw
   HINTS
   ${PC_LIBHIDAPI_LIBDIR}
   ${PC_LIBHIDAPI_LIBRARY_DIRS}
   )

if(PC_LIBHIDAPI_VERSION)
    set(LIBHIDAPI_VERSION_STRING ${PC_LIBHIDAPI_VERSION})
endif()

# handle the QUIETLY and REQUIRED arguments and set FOUND to TRUE if
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LibHidApi
                                  REQUIRED_VARS LIBHIDAPI_LIBRARIES LIBHIDAPI_INCLUDE_DIR
                                  VERSION_VAR LIBHIDAPI_VERSION_STRING)

mark_as_advanced(LIBHIDAPI_INCLUDE_DIR LIBHIDAPI_LIBRARIES)
