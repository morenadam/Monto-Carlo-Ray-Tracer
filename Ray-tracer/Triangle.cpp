//
// Created by Chris Paulusson on 2020-09-13.
//

#include "Ray.h"
#include "Triangle.h"
#include "Definitions.h"
#include "glm/glm.hpp"

Triangle::Triangle() {}


Triangle::Triangle(Vertex _v0, Vertex _v1, Vertex _v2,  ColorDbl color) : v0(_v0), v1(_v1), v2(_v2), color(color) {
    normal = glm::normalize(glm::cross((glm::dvec3)v1 - (glm::dvec3)v0, (glm::dvec3)v2 - (glm::dvec3)v0));
}

Triangle::~Triangle() {}

void Triangle::rayIntersection(Ray ray){

}




