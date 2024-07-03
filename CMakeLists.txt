cmake_minimum_required(VERSION 3.23)
project(turing)

set(CMAKE_CXX_STANDARD 14)

add_executable(turing main.cpp TuringMachine.h TuringMachine.cpp MachineMaker.h MachineMaker.cpp Beaver.cpp Beaver.h)
