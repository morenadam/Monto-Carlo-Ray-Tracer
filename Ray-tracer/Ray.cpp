//
// Created by Adam on 9/13/2020.
//

#include "Ray.h"

Ray::Ray() {}

Ray::~Ray() {

}

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

void Ray::setTriangle(Triangle *triangle) {
    Ray::triangle = triangle;
}

Triangle *Ray::getTriangle() const {
    return triangle;
}

void Ray::setObjectNormal(const Direction &objectNormal) {
    Ray::objectNormal = objectNormal;
}

const Direction &Ray::getObjectNormal() const {
    return objectNormal;
}

const std::string &Ray::getMaterialType() const {
    return MaterialType;
}

void Ray::setMaterialType(const std::string &MaterialType) {
    Ray::MaterialType = MaterialType;
}





