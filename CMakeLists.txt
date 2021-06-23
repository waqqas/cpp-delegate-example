cmake_minimum_required(VERSION 3.19)

project("delegate-examples" VERSION "1.0.0")

# Compiler options.
# C++ standard.
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wrange-loop-analysis)
add_compile_options(-Wshadow -fvisibility=hidden -fvisibility-inlines-hidden -fPIC -Wall -pedantic -Wextra -Werror -Wno-missing-braces -Wno-unused-variable -Wno-unused-parameter -Wno-ignored-qualifiers -Wno-c11-extensions -fdiagnostics-color)

if(${CMAKE_BUILD_TYPE} MATCHES Release)
    add_compile_options(-fno-omit-frame-pointer -DNDEBUG -O3)
endif()

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_subdirectory("example1")
add_subdirectory("example2")