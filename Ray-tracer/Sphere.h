//
// Created by adamm on 2020-09-29.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H
#include "Definitions.h"
#include "Ray.h"
#include <cmath>
#include "Types.h"


class Sphere {
private:
    float radius;
    Vertex center;
    ColorDbl color;
    Material material;

public:
    Sphere();
    ~Sphere();

    Sphere(float _radius, Vertex _center, ColorDbl _color, Material _material);

    bool rayIntersection(Ray &ray, float &minDistance);

    const ColorDbl &getColor() const;

    Material getMaterial() const;


};


#endif //RAY_TRACER_SPHERE_H
