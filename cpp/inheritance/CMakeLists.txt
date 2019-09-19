cmake_minimum_required(VERSION 3.14)

add_compile_options(-std=c++17 -g)
aux_source_directory(. inheritance_srcs)

add_executable(inheritance ${inheritance_srcs})