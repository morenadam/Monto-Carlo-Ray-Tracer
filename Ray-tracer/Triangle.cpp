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

bool Triangle::rayIntersection(Ray ray, Vertex intersection){
//    Vertex v0v1 = v1 - v0;
//    Vertex v0v2 = v2 - v0;
//
//    const double kEpsilon = 0.0000001;
//
//    glm::dvec3 pvec = glm::cross(ray.getDir(),(glm::dvec3)v0v2);
//    float det = glm::dot((glm::dvec3)v0v1, pvec);
//
//    // if the determinant is negative the triangle is backfacing
//    // if the determinant is close to 0, the ray misses the triangle
//    if (det < kEpsilon) return false;
//
//    // ray and triangle are parallel if det is close to 0
//    if (fabs(det) < kEpsilon) return false;
//
//    float invDet = 1 / det;
//
//    //TODO: getStart()??? Finish rayIntersection
//    //https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection
//    glm::dvec3 tvec = (glm::dvec3)ray.getStart() - (glm::dvec3)v0;
//    double u = glm::dot(tvec, pvec) * invDet;
//    if (u < 0 || u > 1) return false;
//
//    glm::dvec3 qvec = glm::dot(tvec, (glm::dvec3)v0v1);
//    v = dir.dotProduct(qvec) * invDet;
//    if (v < 0 || u + v > 1) return false;
//
//    t = v0v2.dotProduct(qvec) * invDet;
//
//    }
}




