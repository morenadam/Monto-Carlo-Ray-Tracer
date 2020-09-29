cmake_minimum_required(VERSION 3.17)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ray_tracer
        main.cpp
        Ray.cpp
        Ray.h
        Triangle.cpp
        Triangle.h
        Pixel.cpp
        Pixel.h
        Scene.cpp
        Scene.h
        Camera.cpp
        Camera.h Definitions.h Sphere.cpp Sphere.h)

