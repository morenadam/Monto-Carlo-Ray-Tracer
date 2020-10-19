//
// Created by Adam on 9/13/2020.
//

#include "Ray.h"

Ray::Ray() = default;

Ray::~Ray() = default;

Ray::Ray(Vertex _startPoint, Direction _dir) : startPoint(_startPoint), dir(_dir){}

void Ray::setEnd(Vertex _end){
    endPoint = _end;
}

void Ray::setColor(ColorDbl _color){
    color = _color;
}

ColorDbl Ray::getColor() {
    return color;
}

Vertex Ray::getEndPoint() {
    return endPoint;
}

Vertex Ray::getStart(){
    return startPoint;
}

Direction Ray::getDirection(){
    return dir;
}


Triangle *Ray::getTriangle() const {
    return triangle;
}

void Ray::setObjectNormal(const Direction &_objectNormal) {
    Ray::objectNormal = _objectNormal;
}

const Direction &Ray::getObjectNormal() const {
    return objectNormal;
}

const Material &Ray::getMaterial() const {
    return material;
}

void Ray::setMaterial(const Material &_material) {
    Ray::material = _material;
}

Direction Ray::reflect(){
    return dir - 2 * glm::dot(dir, objectNormal) * objectNormal;
}





