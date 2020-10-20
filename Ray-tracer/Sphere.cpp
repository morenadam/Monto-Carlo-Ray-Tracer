//
// Created by adamm on 2020-09-29.
//

#include "Sphere.h"

Sphere::Sphere() = default;

Sphere::~Sphere() = default;

Sphere::Sphere(double _radius, Vertex _center, ColorDbl _color, Material _material) : radius(_radius), center(_center),
                                                                                   color(_color), material(_material) {}

bool Sphere::rayIntersection(Ray &ray, double &minDistance){

    // Analytical solution

    double discriminant;
    double d1, d2;

    Vertex o = ray.getStart();
    Direction l = ray.getDirection();

    double a = 1; //Since the direction is normalized
    double b = 2 * glm::dot(l, (o - center));
    double c = glm::dot((o-center),(o-center)) - pow(radius,2);

    discriminant = b * b - 4 * a * c;
    Vertex tempIntersection;

    // No solutions
    if(discriminant < 0) {
        return false;
    }
    //One solution
    else if (discriminant < DBL_EPSILON ){
        d1 = - (b / 2);
        tempIntersection = o + d1 *l;
    }
    //Two solutions
    else {
        d1 = -(b/2) + sqrt(pow((b/2),2) - a*c);
        d2 = -(b/2) - sqrt(pow((b/2),2) - a*c);

        if(d2 > 0) {
            tempIntersection = o + d2*l;
        }
        else if (d1 > 0){
            tempIntersection = o + d1*l;
        }
        else return false;
    }

    if(glm::length(tempIntersection - ray.getStart()) < minDistance) {
        Direction normal = glm::normalize(tempIntersection - center);
        ray.setObjectNormal(normal);
        ray.setColor(getColor());
        ray.setEnd(tempIntersection + normal*0.0001);
        if (ray.getRayType() != SHADOW) ray.setMaterial(getMaterial());
    }

}

const ColorDbl &Sphere::getColor() const {
    return color;
}

Material Sphere::getMaterial() const {
    return material;
}
