//
// Created by Adam on 9/13/2020.
//

#ifndef UNTITLED_RAY_H
#define UNTITLED_RAY_H
#include "Definitions.h"


//It has two instances of Vertex, which are the ray’s starting point and endpoint.
//You can put the vertices into a vertex list and use references to these points inRay.
//Ray contains a reference to the triangle on which the end point is located.
//The ray color is aColorDbl.
class Ray {
private:
    Vertex startPoint;
    Vertex endPoint;
    Direction dir;
    ColorDbl color;

public:

    Ray();

    ~Ray();


    //TODO: add reference to the triangle which the end point is located

    Ray(Vertex _startPoint, Direction _dir) {
        startPoint = _startPoint;
        dir = _dir;
    }

    void setEnd(Vertex _end){
        endPoint = _end;
    }

    void setColor(ColorDbl _color){
        color = _color;
    }

    ColorDbl getColor(){
        return color;
    }

    const Vertex &getEndPoint() const;

    Vertex getStart(){
        return startPoint;
    }

    Direction getDirection(){
        return dir;
    }
};


#endif //UNTITLED_RAY_H
