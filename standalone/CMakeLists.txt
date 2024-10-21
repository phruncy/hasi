cmake_minimum_required(VERSION 3.27)

add_executable(demo "main.cpp")

target_include_directories(demo PRIVATE "${PROJECT_SOURCE_DIR}/hasilib/include")
message("${PROJECT_SOURCE_DIR}/hasilib/include")
target_link_libraries(demo hasi)