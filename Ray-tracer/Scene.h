//
// Created by Chris Paulusson on 2020-09-13.
//

#ifndef UNTITLED_SCENE_H
#define UNTITLED_SCENE_H

#include <list>
#include "Triangle.h"
#include <math.h>
#include "Definitions.h"
#include "Tetrahedron.h"
#include "Sphere.h"

//Scene contains instances of Triangle.  We use one Scene object that consists of 24
//instances of Triangle. Scene objects are closed. The triangles of the floor and the
//ceiling should be white.  Each of the 6walls has a different color.
//It should have a method that determines which triangle is intersected by the Ray arg by
//calling successively the rayIntersection(Ray arg) method of each Triangle.  It then passes references
//to the triangle and the intersection point to theRay arg.
class Scene {
private:
    Triangle triangleList[24];
    Tetrahedron tetrahedron;
    Sphere sphere;
    //Sphere sphere2;
    Vertex lightPoint = Vertex(5,0,4.9);
    int rayDepth = 0;

public:
    Scene();
    ~Scene();

    void FindRayIntersection(Ray &ray, int rayDepth);

    const Vertex &getLightPoint() const;

    Direction reflect(const Direction I, const Direction N);

};

#endif //UNTITLED_SCENE_H
