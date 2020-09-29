//
// Created by adamm on 2020-09-29.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H
#include "Definitions.h"


class Sphere {
private:
    double radius;
    Vertex center;
    ColorDbl color;

public:
    Sphere();
    ~Sphere();

    Sphere(double _radius, Vertex _center, ColorDbl _color);
};


#endif //RAY_TRACER_SPHERE_H
