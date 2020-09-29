//
// Created by Chris Paulusson on 2020-09-24.
//

#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(){

}
Tetrahedron::~Tetrahedron(){

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
