cmake_minimum_required(VERSION 3.27)

add_library(hasi "")

target_include_directories(hasi PRIVATE "${PROJECT_SOURCE_DIR}/hasilib/include")
add_subdirectory("include")
add_subdirectory("src")
