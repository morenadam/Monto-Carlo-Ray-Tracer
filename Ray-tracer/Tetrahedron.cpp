//
// Created by Chris Paulusson on 2020-09-24.
//

#include "Tetrahedron.h"

Tetrahedron::Tetrahedron()= default;
Tetrahedron::~Tetrahedron()= default;

Tetrahedron::Tetrahedron(Vertex v0, Vertex v1, Vertex v2, Vertex v3) {
    triangles[0] = Triangle(v0, v3, v2,ColorDbl(0.5, 0.5, 1), LAMBERTIAN);
    triangles[1] = Triangle(v0, v1, v3,ColorDbl(0.5, 0.5, 1), LAMBERTIAN);
    triangles[2] = Triangle(v1, v3, v2,ColorDbl(0.5, 0.5, 1), LAMBERTIAN);
    triangles[3] = Triangle(v1, v2, v3,ColorDbl(0.5, 0.5, 1), LAMBERTIAN);
}

Tetrahedron::Tetrahedron(Vertex _v0) {
    Vertex v0 = Vertex(_v0.x, _v0.y, 2  + _v0.z);
    Vertex v1 = Vertex(-1  + _v0.x, _v0.y, -1 + _v0.z);
    Vertex v2 = Vertex(_v0.x, -1 +_v0.y, -1 + _v0.z);
    Vertex v3 = Vertex(_v0.x, 1 + _v0.y, -1 + _v0.z);

    triangles[0] = Triangle(v0, v1, v2,ColorDbl(0.5, 0, 0.5), LAMBERTIAN);
    triangles[1] = Triangle(v0, v3, v1,ColorDbl(0.5, 0, 0.5), LAMBERTIAN);
    triangles[2] = Triangle(v0, v2, v3,ColorDbl(0.5, 0, 0.5), LAMBERTIAN);
    triangles[3] = Triangle(v1, v3, v2,ColorDbl(0.5, 0, 0.5), LAMBERTIAN);
}

void Tetrahedron::rayIntersection(Ray &ray, float &minDistance){
    for (Triangle triangle : triangles){
        if(triangle.rayIntersection(ray, minDistance)){
            ray.setMaterial(LAMBERTIAN);
        }
    }
}
