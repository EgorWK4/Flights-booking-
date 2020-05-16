cmake_minimum_required(VERSION 3.16)
project(containers)

set(BOOST_ROOT "/path_to_boost_1_65_1")

set(CMAKE_CXX_STANDARD 20)

add_executable(containers main.cpp airport.h customer.h  exceptions_validate.h airport.cpp customer.cpp file_writing.h interface.h)