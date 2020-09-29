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

bool Tetrahedron::rayIntersection(Ray &ray){
    bool firstIntersection = true;
    Vertex intersection;
    for (Triangle triangle : triangles){
        if(triangle.rayIntersection(ray, intersection)){
            if(firstIntersection){
                intersection = ray.getEndPoint();
                firstIntersection = false;
            }
            else{


            }

        }
    }
}
