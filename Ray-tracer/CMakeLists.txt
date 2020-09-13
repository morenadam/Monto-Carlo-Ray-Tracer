cmake_minimum_required(VERSION 3.15)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ray_tracer
        main.cpp Vertex.cpp Vertex.h Ray.cpp Ray.h)
