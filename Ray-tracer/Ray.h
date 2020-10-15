//
// Created by Adam on 9/13/2020.
//

#ifndef UNTITLED_RAY_H
#define UNTITLED_RAY_H
#include "Definitions.h"

//forward declaration
class Triangle;


//It has two instances of Vertex, which are the ray’s starting point and endpoint.
//You can put the vertices into a vertex list and use references to these points inRay.
//Ray contains a reference to the triangle on which the end point is located.
//The ray color is a ColorDbl.
class Ray {
private:
    Vertex startPoint;
    Vertex endPoint;
    Direction dir;
    ColorDbl color;
    Triangle *triangle;
    Direction objectNormal; //intersected point's objectNormal

public:
    Ray();
    ~Ray();
    Ray(Vertex _startPoint, Direction _dir);

    void setEnd(Vertex _end);
    void setColor(ColorDbl _color);

    const Direction &getObjectNormal() const;
    void setObjectNormal(const Direction &objectNormal);

    ColorDbl getColor();
    Vertex getEndPoint();
    Vertex getStart();
    Direction getDirection();

    void setTriangle(Triangle *triangle);
    Triangle *getTriangle() const;

};


#endif //UNTITLED_RAY_H
