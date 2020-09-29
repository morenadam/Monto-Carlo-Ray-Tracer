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

    Tetrahedron(Vertex v0, Vertex v1, Vertex v2, Vertex v3) {
        triangles[0] = Triangle(v0, v3, v2,ColorDbl(0.5, 0.5, 1));
        triangles[1] = Triangle(v0, v1, v3,ColorDbl(0.5, 0.5, 1));
        triangles[2] = Triangle(v1, v3, v2,ColorDbl(0.5, 0.5, 1));
        triangles[3] = Triangle(v1, v2, v3,ColorDbl(0.5, 0.5, 1));
    }

    bool rayIntersection(Ray &ray, Vertex &intersection, double &minDistance);


};


#endif //RAY_TRACER_TETRAHEDRON_H
