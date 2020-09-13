//
// Created by Adam on 9/13/2020.
//

#ifndef UNTITLED_RAY_H
#define UNTITLED_RAY_H
#include "Vertex.h"
#include "ColorDbl.h"

class Ray {
private:
    Vertex startPoint;
    Vertex endPoint;
    ColorDbi color;

public:
    Ray();

    //TODO: add reference to the triangle which the end point is located

    Ray(Vertex _startPoint, Vertex _endPoint) {
        startPoint = _startPoint;
        endPoint = _endPoint;
    }
    ~Ray();
};


#endif //UNTITLED_RAY_H
