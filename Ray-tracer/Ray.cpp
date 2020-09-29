//
// Created by Adam on 9/13/2020.
//

#include "Ray.h"

Ray::Ray() {}

Ray::~Ray() {

}

Ray::Ray(Vertex _startPoint, Direction _dir) : startPoint(_startPoint), dir(_dir){

}

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


