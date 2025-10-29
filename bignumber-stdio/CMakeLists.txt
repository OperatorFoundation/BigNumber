cmake_minimum_required(VERSION 3.31)
project(bignumber-stdio)

set(CMAKE_CXX_STANDARD 17)

set(BIGNUMBER_STDIO_DIR ${CMAKE_SOURCE_DIR}/bignumber-stdio)
set(BIGNUMBER_LIB_DIR ${CMAKE_SOURCE_DIR}/libraries/bignumber-cpp)
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)

add_executable(bignumber-stdio
  BignumberMain.cpp
  IostreamConnection.cpp
  IostreamStorageConnection.cpp
  main.cpp
)
target_link_libraries(bignumber-stdio bignumber-cpp-lib)

# Generate ctags for vim
set(TAGS_FILE ${BIGNUMBER_STDIO_DIR}/tags)
add_custom_target(
        GenerateStdbignumbergs
        COMMAND ctags -R -f ${TAGS_FILE} ${BIGNUMBER_STDIO_DIR} ${BIGNUMBER_LIB_DIR}
        WORKING_DIRECTORY ${BIGNUMBER_DIR}
        COMMENT "Generating ctags"
)
add_dependencies(${PROJECT_NAME} GenerateStdbignumbergs)
