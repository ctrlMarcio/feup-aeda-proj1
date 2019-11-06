cmake_minimum_required(VERSION 3.15)
project(feup-aeda-proj1)

SET(CMAKE_CXX_STANDARD 14)

add_executable(feup-aeda-proj1 src/model/company/company.h src/model/company/company.cpp)

add_subdirectory(test)

target_link_libraries(feup-aeda-proj1 gtest_main)