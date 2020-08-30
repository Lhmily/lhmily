cmake_minimum_required(VERSION 3.17)
project(lhmily)
add_definitions(-I/usr/local/include)

#add_link_options(-lboost_system)

add_subdirectory(inheritance)
add_subdirectory(net)
add_subdirectory(game)
add_subdirectory(leetcode)
add_subdirectory(nio/client)
add_subdirectory(nio/server)
add_subdirectory(pthread)
add_subdirectory(base)