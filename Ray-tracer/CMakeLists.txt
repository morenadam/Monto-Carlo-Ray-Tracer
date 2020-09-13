cmake_minimum_required(VERSION 3.17)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ray_tracer
        ColorDbl.cpp
        ColorDbl.h
        Direction.cpp
        Direction.h
        main.cpp
        Ray.cpp
        Ray.h
        Triangle.cpp
        Triangle.h
        Vertex.cpp
        Vertex.h)
