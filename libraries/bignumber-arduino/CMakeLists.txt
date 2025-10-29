cmake_minimum_required(VERSION 3.31)
project(bignumber-arduino)

set(CMAKE_CXX_STANDARD 17)
set(BIGNUMBER_LIB_DIR ${CMAKE_SOURCE_DIR}/libraries/bignumber-cpp)
set(BIGNUMBER_LIB_SOURCE_DIR ${CMAKE_SOURCE_DIR}/libraries/bignumber-cpp/src)
set(BIGNUMBER_ARDUINO_DIR ${CMAKE_SOURCE_DIR}/libraries/bignumber-arduino)
set(BIGNUMBER_ARDUINO_SOURCE_DIR ${BIGNUMBER_ARDUINO_DIR}/src)
set(BIGNUMBER_ARDUINO_EXAMPLES_DIR ${BIGNUMBER_ARDUINO_DIR}/examples)
set(BIGNUMBER_ARDUINO_SINE_DIR ${BIGNUMBER_ARDUINO_EXAMPLES_DIR}/Sine)

# Define your sketch file
set(SKETCH_FILE ${BIGNUMBER_ARDUINO_SINE_DIR}/Sine.ino)

set(BOARD "rp2040:rp2040:adafruit_feather_rp2350_hstx")
set(PORT "/dev/cu.usbmodem1101")

set(OUTPUT_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/arduino/rp2350/bignumber-arduino)
file(GLOB_RECURSE BIGNUMBER_FILES ${BIGNUMBER_LIB_SOURCE_DIR}/*.cpp ${BIGNUMBER_ARDUINO_SOURCE_DIR}/*.cpp ${BIGNUMBER_ARDUINO_SOURCE_DIR}/*.ino)

add_executable(bignumber-arduino ${BIGNUMBER_FILES})
add_dependencies(bignumber-arduino build_bignumber_arduino)
target_link_libraries(bignumber-arduino PRIVATE bignumber-cpp)

add_custom_target(build_bignumber_arduino ALL
        COMMAND arduino-cli compile
            --fqbn ${BOARD}
            --output-dir ${OUTPUT_DIR}
            --build-property "compiler.cpp.extra_flags=-std=c++17 -D_BSD_SOURCE -D_DEFAULT_SOURCE"
            --library ${BIGNUMBER_LIB_DIR}
            --library ${BIGNUMBER_ARDUINO_DIR}
  ${SKETCH_FILE}
        WORKING_DIRECTORY ${BIGNUMBER_ARDUINO_SOURCE_DIR}
        COMMENT "Building bignumber-arduino with arduino-cli"
)

add_custom_target(upload_bignumber_arduino_protocol_server ALL
        COMMAND arduino-cli upload
        -p ${PORT}
        --fqbn ${BOARD}
        ${BIGNUMBER_ARDUINO_PROTOCOL_SERVER_DIR}
        COMMENT "Uploading bignumber-arduino-protocol-server with arduino-cli"
)
add_dependencies(upload_bignumber_arduino_protocol_server build_bignumber_arduino)