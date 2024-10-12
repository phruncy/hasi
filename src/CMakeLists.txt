cmake_minimum_required(VERSION 3.27)

add_library(hasilib "")
target_sources(hasilib
    PRIVATE
    "Scanner.h"
    "Scanner.cpp"
    "Token.h"
)