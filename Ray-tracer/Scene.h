//
// Created by Chris Paulusson on 2020-09-13.
//

#ifndef UNTITLED_SCENE_H
#define UNTITLED_SCENE_H

#include <list>
#include "Triangle.h"
#include <math.h>

//Scene contains instances of Triangle.  We use one Scene object that consists of 24
//instances of Triangle. Scene objects are closed. The triangles of the floor and the
//ceiling should be white.  Each of the 6walls has a different color.
//It should have a method that determines which triangle is intersected by the Ray arg by
//calling successively the rayIntersection(Ray arg) method of each Triangle.  It then passes references
//to the triangle and the intersection point to theRay arg.
class Scene {

private:

    Triangle triangleList[24];

public:

    Scene(){

        //__________________FLOOR____________________

        triangleList[0] = Triangle(Vertex(0, -6, -5, 1),
                                   Vertex(10, -6, -5, 1),
                                   Vertex(10, 0, -5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,1));

        triangleList[1] = Triangle(Vertex(0, -6, -5, 1),
                                   Vertex(10, 0, -5, 1),
                                   Vertex(0, 0, -5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,1));

        triangleList[2] = Triangle(Vertex(0, 0, -5, 1),
                                   Vertex(10, 0, -5, 1),
                                   Vertex(10, 6, -5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,1));

        triangleList[3] = Triangle(Vertex(0, 0, -5, 1),
                                   Vertex(0, 6, -5, 1),
                                   Vertex(10, 6, -5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,1));

        triangleList[4] = Triangle(Vertex(-3, 0, -5, 1),
                                   Vertex(0, -6, -5, 1),
                                   Vertex(0, 6, -5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,1));

        triangleList[5] = Triangle(Vertex(13, 0, -5, 1),
                                   Vertex(10, -6, -5, 1),
                                   Vertex(10, 6, -5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,1));

        //__________________CEILING____________________

        triangleList[6] = Triangle(Vertex(0, -6, 5, 1),
                                   Vertex(10, -6, 5, 1),
                                   Vertex(10, 0, 5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,-1));

        triangleList[7] = Triangle(Vertex(0, -6, 5, 1),
                                   Vertex(10, 0, 5, 1),
                                   Vertex(0, 0, 5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,-1));

        triangleList[8] = Triangle(Vertex(0, 0, 5, 1),
                                   Vertex(10, 0, 5, 1),
                                   Vertex(10, 6, 5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,-1));

        triangleList[9] = Triangle(Vertex(0, 0, 5, 1),
                                   Vertex(0, 6, 5, 1),
                                   Vertex(10, 6, 5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,-1));

        triangleList[10] = Triangle(Vertex(-3, 0, 5, 1),
                                   Vertex(0, -6, 5, 1),
                                   Vertex(0, 6, 5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,-1));

        triangleList[11] = Triangle(Vertex(13, 0, 5, 1),
                                   Vertex(10, -6, 5, 1),
                                   Vertex(10, 6, 5, 1),
                                   ColorDbl(1,1,1),
                                   Direction(0,0,-1));

        //__________________SOUTH____________________
        triangleList[12] = Triangle(Vertex(0, -6, -5, 1),
                                    Vertex(10, -6, -5, 1),
                                    Vertex(10, -6, 5, 1),
                                    ColorDbl(0,0,1),
                                    Direction(0,1,0));

        triangleList[12] = Triangle(Vertex(0, -6, -5, 1),
                                    Vertex(10, -6, 5, 1),
                                    Vertex(0, -6, 5, 1),
                                    ColorDbl(0,0,1),
                                    Direction(0,1,0));

        //__________________NORTH____________________
        triangleList[12] = Triangle(Vertex(0, 6, -5, 1),
                                    Vertex(10, 6, -5, 1),
                                    Vertex(10, 6, 5, 1),
                                    ColorDbl(0,1,0),
                                    Direction(0,-1,0));

        triangleList[12] = Triangle(Vertex(0, 6, -5, 1),
                                    Vertex(10, 6, 5, 1),
                                    Vertex(0, 6, 5, 1),
                                    ColorDbl(0,1,0),
                                    Direction(0,-1,0));

        //__________________NORTH-EAST___________________
        triangleList[12] = Triangle(Vertex(10, 6, 5, 1),
                                    Vertex(13, 0, -5, 1),
                                    Vertex(10, 6, -5, 1),
                                    ColorDbl(1,0,0),
                                    Direction(0,0,0));

        triangleList[12] = Triangle(Vertex(10, 6, 5, 1),
                                    Vertex(13, 0, 5, 1),
                                    Vertex(13, 0, -5, 1),
                                    ColorDbl(1,0,0),
                                    Direction(0,0,0));

        //TODO: finish room triangles

    }



};


#endif //UNTITLED_SCENE_H
