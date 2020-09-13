//
// Created by Chris Paulusson on 2020-09-13.
//

#ifndef UNTITLED_TRIANGLE_H
#define UNTITLED_TRIANGLE_H

#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"

//The triangle is defined by three objects of the classVertex. The Triangle has a color,
//which we represent by an instance of ColorDbl. The triangle’s normal direction is stored
//in an instance of Direction. It has a method rayIntersection(Ray arg)
//that computes the intersection between a Ray and the Triangle with the Mö̈ller-Trumbore algorithm.
class Triangle {

private:
    Vertex v0, v1, v2;
    ColorDbl color;
    Direction normal;

public:

    Triangle() = default;

    Triangle(Vertex _v0, Vertex _v1, Vertex _v2, ColorDbl c, Direction n){
        v0 = _v0, v1 = _v1, v2 = _v2;
        color = c;
        normal = n;
    }

    void rayIntersection(Ray ray);

    /*
    void setVertices(Vertex _v0, Vertex _v1, Vertex _v2){
        v0 = _v0, v1 = _v1, v2 = _v2;
    }

    void setColor(ColorDbl c){
        color = c;
    };

    void setNormal(Direction n){
        normal = n;
    }*/

    ~Triangle() = default;

};


#endif //UNTITLED_TRIANGLE_H
