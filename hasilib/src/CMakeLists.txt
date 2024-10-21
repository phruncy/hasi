cmake_minimum_required(VERSION 3.27)

add_library(hasi "")
target_sources(hasi
    PRIVATE
    "Scanner.h"
    "Scanner.cpp"
    "Token.h"
)