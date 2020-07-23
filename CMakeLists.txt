cmake_minimum_required (VERSION 3.8)

SET(BINARY_NAME mcast-sock-emulator)
project (${BINARY_NAME})

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

# Set application name
SET(APP_NAME "Multicast socket Tx emulator")
# The version number.
SET(APP_VERSION_MAJOR 0)
SET(APP_VERSION_MINOR 1)

include_directories("${PROJECT_SOURCE_DIR}/include")

IF( CMAKE_BUILD_TYPE MATCHES Debug )
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -DDEBUG -O0 -g3 -ggdb")
    message("Debug build enabled")
ELSE()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
    message("Release build enabled")
ENDIF()

# Get the current working branch
execute_process(
    COMMAND git rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
   "${PROJECT_SOURCE_DIR}/config.hpp.in"
   "${PROJECT_SOURCE_DIR}/include/config.hpp"
)

SET(EXTRA_LIBS pthread)

# add the executable
file(GLOB_RECURSE SOURCES RELATIVE ${PROJECT_SOURCE_DIR} "src/*.cpp")
add_executable(${BINARY_NAME} ${SOURCES})
target_link_libraries(${BINARY_NAME} ${EXTRA_LIBS})

# install
INSTALL(TARGETS ${BINARY_NAME} DESTINATION "/usr/local/bin")
