cmake_minimum_required(VERSION 3.16)

add_compile_options(-std=c++2a -g)
aux_source_directory(. inheritance_srcs)

add_executable(inheritance ${inheritance_srcs})