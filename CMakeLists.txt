cmake_minimum_required(VERSION 2.8.8)

project(msiHidKeyboard)

set(BIN_EXEC "msiHidKeyboard")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

INCLUDE(CheckApplyCompilerFlags)

find_package(hidapi REQUIRED)

# --- global compiler flags ---
if (UNIX)
  COMPILER_FLAGS(FLAGS "-pipe" "-Wall" "-Wextra"
                           "--std=c++1y"
                           "-Wchar-subscripts" "-Winit-self" "-Wswitch-enum"
                           "-Wstrict-aliasing=3"
                           "-Wundef" "-Wno-endif-labels"
                           "-Wshadow" "-Wno-builtin-macro-redefined"
                           "-Wmissing-declarations"
                           "-Wdocumentation"
                           "-Wno-switch-enum"
                FLAGS_RELEASE  "-march=native" "-O2"
                FLAGS_DEBUG    "-DNDEBUG" "-g3"
                           )
elseif (MSVC)
  COMPILER_FLAGS(FLAGS "/EHsc")
endif()

file(
  GLOB_RECURSE
  bin_source_files
  src/*
)

file(
  GLOB_RECURSE
  bin_include_files
  inc/*
)

add_executable(
    ${BIN_EXEC}
    ${bin_source_files}
    ${bin_include_files}
)

target_link_libraries(${BIN_EXEC} ${LIBHIDAPI_LIBRARIES})

include_directories("inc/")
include_directories(${LIBHIDAPI_INCLUDE_DIR})

