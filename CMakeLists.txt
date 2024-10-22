cmake_minimum_required(VERSION 3.27)

project(Hasi_project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

add_subdirectory(hasilib)
add_subdirectory(standalone)
