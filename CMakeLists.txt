project(spokecalc)
cmake_minimum_required(VERSION 3.7.2)

set(EXECUTABLE_OUTPUT_PATH  ${spokecalc_SOURCE_DIR}/bin/)

#Bring the headers, any .h files, into the project
include_directories(include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(spokecalc ${SOURCES})

install(
    TARGETS
        spokecalc
    RUNTIME DESTINATION
        ${CMAKE_INSTALL_PREFIX}/bin
    )
