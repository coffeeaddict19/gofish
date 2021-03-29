project(gofish)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(gofishlib)
#add_subdirectory(gofishterm)
add_subdirectory(gofishtest)
