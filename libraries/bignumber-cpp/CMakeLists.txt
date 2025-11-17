cmake_minimum_required(VERSION 3.31)
project(bignumber-cpp-lib)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

set(BIGNUMBER_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BIGNUMBER_LIB_SOURCE_DIR ${BIGNUMBER_LIB_DIR}/src)

file(GLOB_RECURSE BIGNUMBER_FILES ${BIGNUMBER_LIB_SOURCE_DIR}/*.cpp ${BIGNUMBER_LIB_SOURCE_DIR}/*.c)
message(STATUS "BIGNUMBER source dir: ${BIGNUMBER_LIB_SOURCE_DIR}")
message(STATUS "BIGNUMBER_FILES found: ${BIGNUMBER_FILES}")

add_library(bignumber-cpp-lib STATIC ${BIGNUMBER_FILES})

target_include_directories(bignumber-cpp-lib PUBLIC
  ${BIGNUMBER_LIB_SOURCE_DIR}
)

if(ENABLE_COVERAGE AND (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CX_COMPILER_ID MATCHES "Clang"))
  target_compile_options(bignumber-cpp-lib PRIVATE --coverage -O0 -g)
  target_link_options(bignumber-cpp-lib PRIVATE --coverage)
endif()
