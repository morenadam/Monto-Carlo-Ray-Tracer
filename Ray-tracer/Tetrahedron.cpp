//
// Created by Chris Paulusson on 2020-09-24.
//

#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(){

}
Tetrahedron::~Tetrahedron(){

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
