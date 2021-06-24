project("example2" VERSION "1.0.0")

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Boost 1.75 REQUIRED system)
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} Boost::system)

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

add_subdirectory(benchmarks)