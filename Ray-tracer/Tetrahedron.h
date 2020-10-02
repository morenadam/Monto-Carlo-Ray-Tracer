//
// Created by Chris Paulusson on 2020-09-24.
//

#ifndef RAY_TRACER_TETRAHEDRON_H
#define RAY_TRACER_TETRAHEDRON_H

#include "Triangle.h"


class Tetrahedron {
private:
    Triangle triangles [4];

public:
    Tetrahedron();
    ~Tetrahedron();
    Tetrahedron(Vertex v0, Vertex v1, Vertex v2, Vertex v3);
    Tetrahedron(Vertex v0);

    bool rayIntersection(Ray &ray, Vertex &intersection, double &minDistance);

};


#endif //RAY_TRACER_TETRAHEDRON_H
