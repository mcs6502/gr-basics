INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_BASICS basics)

FIND_PATH(
    BASICS_INCLUDE_DIRS
    NAMES basics/api.h
    HINTS $ENV{BASICS_DIR}/include
        ${PC_BASICS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    BASICS_LIBRARIES
    NAMES gnuradio-basics
    HINTS $ENV{BASICS_DIR}/lib
        ${PC_BASICS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BASICS DEFAULT_MSG BASICS_LIBRARIES BASICS_INCLUDE_DIRS)
MARK_AS_ADVANCED(BASICS_LIBRARIES BASICS_INCLUDE_DIRS)

