cmake_minimum_required(VERSION 3.10.3)
project(polymer)

set(CMAKE_CXX_STANDARD 11)

set(POLYMER_LIB_HEADERS include/polymer/polymer.h)
set(POLYMER_LIB_SOURCES)
add_library(polymerLib ${POLYMER_LIB_HEADERS} ${POLYMER_LIB_SOURCES})
target_include_directories(polymerLib PUBLIC include)

set(POLYMER_SOURCES src/polymer.cc)
add_executable(polymer ${POLYMER_SOURCES})
target_include_directories(polymer PUBLIC include)