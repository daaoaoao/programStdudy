cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp ThreadPool_.cpp ThreadPool_.h Semaphore.cpp Semaphore.h)
