//
// Created by Chris Paulusson on 2020-09-13.
//

#include "Scene.h"
#include "Definitions.h"

Scene::Scene() {

    //__________________FLOOR____________________
    triangleList[0] = Triangle(Vertex(5, 0, -5),
                               Vertex(10, 6, -5),
                               Vertex(0, 6, -5),
                               ColorDbl(1, 1, 1));

    triangleList[1] = Triangle(Vertex(5, 0, -5),
                               Vertex(13, 0, -5),
                               Vertex(10, 6, -5),
                               ColorDbl(1, 1, 1));

    triangleList[2] = Triangle(Vertex(5, 0, -5),
                               Vertex(10, -6, -5),
                               Vertex(13, 0, -5),
                               ColorDbl(1, 1, 1));

    triangleList[3] = Triangle(Vertex(5, 0, -5),
                               Vertex(0, -6, -5),
                               Vertex(10, -6, -5),
                               ColorDbl(1, 1, 1));

    triangleList[4] = Triangle(Vertex(5, 0, -5),
                               Vertex(-3, 0, -5),
                               Vertex(0, -6, -5),
                               ColorDbl(1, 1, 1));

    triangleList[5] = Triangle(Vertex(5, 0, -5),
                               Vertex(0, 6, -5),
                               Vertex(-3, 0, -5),
                               ColorDbl(1, 1, 1));

    //__________________CEILING____________________
    triangleList[6] = Triangle(Vertex(5, 0, 5),
                               Vertex(0, 6, 5),
                               Vertex(10, 6, 5),

                               ColorDbl(1, 1, 1));

    triangleList[7] = Triangle(Vertex(5, 0, 5),
                               Vertex(10, 6, 5),
                               Vertex(13, 0, 5),

                               ColorDbl(1, 1, 1));

    triangleList[8] = Triangle(Vertex(5, 0, 5),
                               Vertex(13, 0, 5),
                               Vertex(10, -6, 5),

                               ColorDbl(1, 1, 1));

    triangleList[9] = Triangle(Vertex(5, 0, 5),
                               Vertex(10, -6, 5),
                               Vertex(0, -6, 5),

                               ColorDbl(1, 1, 1));

    triangleList[10] = Triangle(Vertex(5, 0, 5),
                                Vertex(0, -6, 5),
                               Vertex(-3, 0, 5),

                               ColorDbl(1, 1, 1));

    triangleList[11] = Triangle(Vertex(5, 0, 5),
                                Vertex(-3, 0, 5),
                               Vertex(0, 6, 5),

                               ColorDbl(1, 1, 1));

    //__________________SOUTH____________________
    triangleList[12] = Triangle(Vertex(0, -6, -5),
                                Vertex(0, -6, -5),
                                Vertex(10, -6, 5),
                                ColorDbl(0, 0, 1));

    triangleList[13] = Triangle(Vertex(10, -6, -5),
                                Vertex(0, -6, 5),
                                Vertex(10, -6, 5),
                                ColorDbl(0, 0, 1));

    //__________________NORTH____________________
    triangleList[14] = Triangle(Vertex(10, 6, -5),
                                Vertex(10, 6, 5),
                                Vertex(0, 6, -5),
                                ColorDbl(0, 1, 0));

    triangleList[15] = Triangle(Vertex(0, 6, -5),
                                Vertex(10, 6, 5),
                                Vertex(0, 6, 5),
                                ColorDbl(0, 1, 0));

    //__________________NORTH-EAST___________________
    triangleList[16] = Triangle(Vertex(13, 0, -5),
                                Vertex(13, 0, 5),
                                Vertex(10, 6, -5),
                                ColorDbl(1, 0, 0));

    triangleList[17] = Triangle(Vertex(10, 6, -5),
                                Vertex(13, 0, 5),
                                Vertex(10, 6, 5),
                                ColorDbl(1, 0, 0));

    //__________________SOUTH-EAST___________________
    triangleList[18] = Triangle(Vertex(10, -6, -5),
                                Vertex(10, -6, 5),
                                Vertex(13, 0, -5),
                                ColorDbl(1, 1, 0));

    triangleList[19] = Triangle(Vertex(10, 6, -5),
                                Vertex(13, 0, 5),
                                Vertex(10, 6, 5),
                                ColorDbl(1, 1, 0));

    //__________________SOUTH-WEST___________________
    triangleList[20] = Triangle(Vertex(-3, 0, -5),
                                Vertex(-3, 0, 5),
                                Vertex(0, -6, -5),
                                ColorDbl(0.5, 0, 0.5));

    triangleList[21] = Triangle(Vertex(0, -6, -5),
                                Vertex(-3, 0, 5),
                                Vertex(0, -6, 5),
                                ColorDbl(0.5, 0, 0.5));

    //__________________NORTH-WEST___________________
    triangleList[22] = Triangle(Vertex(0, 6, -5),
                                Vertex(0, 6, 5),
                                Vertex(-3, 0, -5),
                                ColorDbl(1, 0, 1));

    triangleList[23] = Triangle(Vertex(-3, 0, -5),
                                Vertex(0, 6, 5),
                                Vertex(-3, 0, 5),
                                ColorDbl(1, 0, 1));
}

Scene::~Scene() {

}

//TODO: finish room triangles
