cmake_minimum_required(VERSION 3.18)

add_definitions(-std=c++2a -g)


add_executable(pthread main.cpp count_down_latch.cpp)