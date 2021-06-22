# Include common options.
include(${CMAKE_CURRENT_LIST_DIR}/common.cmake)

add_compile_options(-Wshadow -fvisibility=hidden -fvisibility-inlines-hidden -fPIC -Wall -pedantic -Wextra -Werror -Wno-missing-braces -Wno-unused-variable -Wno-unused-parameter -Wno-ignored-qualifiers -Wno-c11-extensions -fdiagnostics-color)

if(${CMAKE_BUILD_TYPE} MATCHES Release)
    add_compile_options(-fno-omit-frame-pointer -DNDEBUG -O3)
endif()

# Compiler options.
