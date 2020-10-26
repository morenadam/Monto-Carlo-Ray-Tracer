cmake_minimum_required(VERSION 3.17)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 14)

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
        Camera.h
        Definitions.h
        Sphere.cpp
        Sphere.h
        Tetrahedron.cpp
        Tetrahedron.h Types.h)

#[[if(OpenMP_CXX_FOUND)
    target_compile_options(ray_tracer PRIVATE -Wall ${OpenMP_CXX_FLAGS})
    target_link_libraries(ray_tracer PRIVATE ${OpenMP_CXX_FLAGS})
endif()]]

include_directories(.)


