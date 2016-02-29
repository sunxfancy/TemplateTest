cmake_minimum_required(VERSION 2.8)
project(template_test)
SET(CMAKE_CXX_COMPILER_ENV_VAR "CXX")
SET(CMAKE_CXX_FLAGS "-std=c++11")
file(GLOB_RECURSE source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(template_test ${source_files})
install(TARGETS template_test RUNTIME DESTINATION bin)


