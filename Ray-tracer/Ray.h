//
// Created by Adam on 9/13/2020.
//

#ifndef UNTITLED_RAY_H
#define UNTITLED_RAY_H
#include "Definitions.h"
#include <string>
#include "Types.h"

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
    Direction objectNormal; //intersected point's objectNormal
    Material material;
    RayType rayType;

public:
    Ray();
    ~Ray();
    Ray(Vertex _startPoint, Direction _dir, RayType _rayType);

    void setEnd(Vertex _end);
    void setColor(ColorDbl _color);

    const Direction &getObjectNormal() const;
    void setObjectNormal(const Direction &_objectNormal);

    ColorDbl &getColor();
    Vertex getEndPoint();
    const Vertex &getStart() const;
    Direction getDirection();

    Triangle *getTriangle() const;

    const Material &getMaterial() const;

    void setMaterial(const Material &_material);

    Direction reflect();

    RayType getRayType() const;


};


#endif //UNTITLED_RAY_H
