//
// Created by Chris Paulusson on 2020-09-13.
//

#ifndef UNTITLED_TRIANGLE_H
#define UNTITLED_TRIANGLE_H

#include "Definitions.h"
#include "Ray.h"
#include "glm/gtx/normal.hpp"

//The triangle is defined by three objects of the classVertex. The Triangle has a color,
//which we represent by an instance of ColorDbl. The triangle’s normal direction is stored
//in an instance of Direction. It has a method rayIntersection(Ray arg)
//that computes the intersection between a Ray and the Triangle with the Möller-Trumbore algorithm.
class Triangle {
private:
    Vertex v0, v1, v2;
    ColorDbl color;
    Direction normal;

public:
    Triangle();
    ~Triangle();
    Triangle(Vertex _v0, Vertex _v1, Vertex _v2, ColorDbl _color);

    bool rayIntersection(Ray &ray, double &minDistance);
    ColorDbl getColor();

};


#endif //UNTITLED_TRIANGLE_H
