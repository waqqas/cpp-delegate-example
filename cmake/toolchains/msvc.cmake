# Include common options.
include(${CMAKE_CURRENT_LIST_DIR}/common.cmake)

# Static runtime linkage.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "")

# Compiler options.
add_compile_options(
    /permissive-  # strict C++
    /W4           # enable all warnings
)
if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "Win32") # 32-bit
    add_compile_options(
        /arch:SSE2
        /bigobj
        /Zc:__cplusplus
    )
endif()

add_definitions(-D_WIN32_WINNT=0x0601 -D_CRT_SECURE_NO_WARNINGS)

# Linker options.
add_link_options(
)

# Disable logos.
foreach(lang C CXX ASM_MASM RC)
    set(CMAKE_${lang}_FLAGS_INIT "/nologo")
endforeach()
foreach(type EXE SHARED MODULE)
    set(CMAKE_${type}_LINKER_FLAGS_INIT "/nologo")
endforeach()

# Silence Visual Studio CMake integration warnings.
set(SILENCE_VS_DEFINITIONS ${CMAKE_TOOLCHAIN_FILE} ${CMAKE_C_COMPILER})
set(SILENCE_VS_DEFINITIONS)
