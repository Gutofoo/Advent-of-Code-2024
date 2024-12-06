cmake_minimum_required(VERSION 3.22)

project(advent_of_code_2024)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED 17)

include_directories(include)

add_executable(day2.exe
    day2.cpp
    src/parser.cpp
    src/solver.cpp
)
