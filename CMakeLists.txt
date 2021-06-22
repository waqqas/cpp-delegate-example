cmake_minimum_required(VERSION 3.19)
if(APPLE)
set(CMAKE_OSX_DEPLOYMENT_TARGET "11.1" CACHE STRING "Minimum OS X deployment version" FORCE)
endif()

project("delegator" VERSION "1.0.0")

include("cmake/macros.cmake")

# list(PREPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

###############################


# set(OTHER_SOURCES)
set(SOURCES main.cpp ${OTHER_SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

# ADD_OSX_FRAMEWORK(${PROJECT_NAME} NetworkExtension )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)



install(TARGETS ${PROJECT_NAME} 
  RUNTIME DESTINATION bin
  BUNDLE DESTINATION bin
  RESOURCE DESTINATION bin
)
