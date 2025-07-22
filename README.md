# README
This repository is my shot at solving the programming puzzles for [Advent of Code 2024](https://adventofcode.com/2024).

## Background
This repository is for my solutions for programming puzzles provided by Advent of Code. I chose to write my solutions in C++ to practice the language and familiarize my self better with the tools available in the standard library.
To run this code, one requires CMake and a C++ compiler compliant to at least C++17. I use CMake 3.28.3 and gcc 13.3.0.

In order to properly run any of the code to solve puzzles, one requires the proper inputs. Advent of Code generates unique puzzle input sets per user and does not permit sharing of tyhe input sets. Therefore, to properly run this code, one is required to log in to Advent of Code at the provided link above. It may be authenticated using other services like Github, Reddit, and more. For each day, please copy-paste your inputs into the day's input directory as either example.txt or input.txt.

## Repository Layout
Each day is its own self-contained directory. All build products remain within that directory and no code requires any code outside the day's directory.

## Build
Building any day's solution is very easy and is standard for each puzzle. navigate to the desired day directory. Then, invoke CMake; after that, invoke Make.
The following lines are an example that build the solution for day 1.
```
cd 'day 1'
cmake .
make
```

## Run
The build process results in an executible that is the day followed by a .exe extension in the day's directory. From the example above, that would result in an exeutible `day.exe` under the 'day 1' directory. The program accepts one command line argument, which is the name of the input file. I named these example.txt and input.txt for each day's example text and real input, respectively, but these could be named anything. By default, executing the program with no arguments will target input/example.txt.

Each day has two parts to the puzzle. While solving the puzzles these must be solved sequentially and the second part is not revealed until the first part is solved. A design goal of mine was that each day's puzzle may be run and still give the correct response for both parts of the puzzle. That is, solving the 2nd part of the puzzle does not bar the program solving the 1st part.

Each day prints two lines to the terminal, with the answers for part 1 and part 2 of the day's puzzle.

## Debug
If desired, each day's code can be compiled with gdb to enable debugging. To do this, the CMake build products must be cleaned, then CMake re-invoked with the debug flag enabled.
To clean the build products, for example, for day 1:
```
cd 'day 1'
rm -r CMakeFiles
rm cmake_install.cmake CMakeCache.txt
```
And then the program must be rebuilt, enabling the debug flag. Here is an example for day 1 again, assuming the user starts from the repository top-level:
```
cd 'day 1'
cmake -DCMAKE_DEBUG_BUILD-debug .
make
```
