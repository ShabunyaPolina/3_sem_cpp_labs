cmake_minimum_required(VERSION 3.19)
project(sem3_cpp_lab_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(sem3_cpp_lab_list main.cpp bidirectional_list.cpp
        bidirectional_list.h iterator.cpp iterator.h aggregate.h aggregate.cpp
        visitor.h visitor.cpp)