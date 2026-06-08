cmake_minimum_required(VERSION 4.2)
project(wordleClone)

set(CMAKE_CXX_STANDARD 23)

add_executable(wordleClone main.cpp
        words.cpp
        words.h
        guess.cpp
        guess.h
        display.cpp
        display.h)
