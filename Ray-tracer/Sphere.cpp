//
// Created by adamm on 2020-09-29.
//

#include "Sphere.h"

Sphere::Sphere() {}

Sphere::~Sphere() {}

Sphere::Sphere(double _radius, Vertex _center, ColorDbl _color) : radius(_radius), center(_center),
                                                                             color(_color) {}

bool Sphere::rayIntersection(Ray &ray, double &minDistance){

    float a, b ;
    Vertex o, d;
    Direction l;
    double c;
    double r;

    o = ray.getStart();
    l = ray.getDirection();
    a = 1;
    b = glm::dot(2.0* l, (o - center));
    c = glm::dot((o-center),(o-center)) - pow(radius,2);

    double d1 = -(b/2) + sqrt(pow((b/2),2) - a*c);
    double d2 = -(b/2) - sqrt(pow((b/2),2) - a*c);

    Vertex tempIntersection;
    if(d1 < 0 && d2 <0) {
        return false;
    }
    else if(d2 > 0) {
        tempIntersection = o + d2*l;
    }
    else {
        tempIntersection = o + d1*l;
    }

    if(glm::length(tempIntersection - ray.getStart()) < minDistance) {
        ray.setColor(this->getColor());
        ray.setEnd(tempIntersection);
    }

    // ||x−c||2= r^2


}

const ColorDbl &Sphere::getColor() const {
    return color;
}
