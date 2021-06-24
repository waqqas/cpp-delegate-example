
set(BENCHMARK_TARGET ${PROJECT_NAME}-benchmark)

file(GLOB TEST_SOURCES *.cpp *.h)
add_executable(${BENCHMARK_TARGET} ${TEST_SOURCES})

target_include_directories(${BENCHMARK_TARGET} PUBLIC ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)

find_package(benchmark REQUIRED)
target_link_libraries(${BENCHMARK_TARGET} benchmark::benchmark)