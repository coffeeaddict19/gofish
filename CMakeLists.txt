project(gofish)

cmake_minimum_required(VERSION 3.16)

add_subdirectory(gofishlib)
#add_subdirectory(gofishterm)
add_subdirectory(gofishtest)

enable_testing ()
