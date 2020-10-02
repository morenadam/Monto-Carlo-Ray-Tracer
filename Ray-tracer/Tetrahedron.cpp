//
// Created by Chris Paulusson on 2020-09-24.
//

#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(){

}
Tetrahedron::~Tetrahedron(){

}

Tetrahedron::Tetrahedron(Vertex v0, Vertex v1, Vertex v2, Vertex v3) {
    triangles[0] = Triangle(v0, v3, v2,ColorDbl(0.5, 0.5, 1));
    triangles[1] = Triangle(v0, v1, v3,ColorDbl(0.5, 0.5, 1));
    triangles[2] = Triangle(v1, v3, v2,ColorDbl(0.5, 0.5, 1));
    triangles[3] = Triangle(v1, v2, v3,ColorDbl(0.5, 0.5, 1));
}

Tetrahedron::Tetrahedron(Vertex _v0) {
    Vertex v0 = Vertex( 10 + _v0.x, 0 + _v0.y, 0 + _v0.z);
    Vertex v1 = Vertex(9 + _v0.x, 0 +_v0.y, -4 + _v0.z);
    Vertex v2 = Vertex(11 + _v0.x, -2 +_v0.y, -4 + _v0.z);
    Vertex v3 = Vertex(11 + _v0.x,2 + _v0.y, -4 + _v0.z);

    triangles[0] = Triangle(v0, v3, v2,ColorDbl(0.5, 0.5, 1));
    triangles[1] = Triangle(v0, v1, v3,ColorDbl(0.5, 0.5, 1));
    triangles[2] = Triangle(v1, v3, v2,ColorDbl(0.5, 0.5, 1));
    triangles[3] = Triangle(v1, v2, v3,ColorDbl(0.5, 0.5, 1));
}

bool Tetrahedron::rayIntersection(Ray &ray, Vertex &intersection, double &minDistance){
    for (Triangle triangle : triangles){
        if(triangle.rayIntersection(ray, intersection)){
            if(glm::length(intersection-ray.getStart()) < minDistance) {
                ray.setColor(triangle.getColor());
                minDistance = glm::length(intersection-ray.getStart());
            }
        }
    }
}
