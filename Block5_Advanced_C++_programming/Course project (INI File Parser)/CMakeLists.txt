cmake_minimum_required(VERSION 3.22.0)
project(Parser)
add_executable(Parser main.cpp Parser.cpp Parser.h)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data.ini
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})