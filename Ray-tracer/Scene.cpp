//
// Created by Chris Paulusson on 2020-09-13.
//

#include "Scene.h"
#include "Definitions.h"
#include "Triangle.h"

#include <iostream>
#include <string>
Scene::Scene() {

    //__________________FLOOR____________________
    triangleList[0] = Triangle(Vertex(5, 0, -5),
                               Vertex(10, 6, -5),
                               Vertex(0, 6, -5),
                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[1] = Triangle(Vertex(5, 0, -5),
                               Vertex(13, 0, -5),
                               Vertex(10, 6, -5),
                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[2] = Triangle(Vertex(5, 0, -5),
                               Vertex(10, -6, -5),
                               Vertex(13, 0, -5),
                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[3] = Triangle(Vertex(5, 0, -5),
                               Vertex(0, -6, -5),
                               Vertex(10, -6, -5),
                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[4] = Triangle(Vertex(5, 0, -5),
                               Vertex(-3, 0, -5),
                               Vertex(0, -6, -5),
                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[5] = Triangle(Vertex(5, 0, -5),
                               Vertex(0, 6, -5),
                               Vertex(-3, 0, -5),
                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    //__________________CEILING____________________
    triangleList[6] = Triangle(Vertex(5, 0, 5),
                               Vertex(0, 6, 5),
                               Vertex(10, 6, 5),

                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[7] = Triangle(Vertex(5, 0, 5),
                               Vertex(10, 6, 5),
                               Vertex(13, 0, 5),

                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[8] = Triangle(Vertex(5, 0, 5),
                               Vertex(13, 0, 5),
                               Vertex(10, -6, 5),

                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[9] = Triangle(Vertex(5, 0, 5),
                               Vertex(10, -6, 5),
                               Vertex(0, -6, 5),

                               ColorDbl(1, 1, 1),
                               LAMBERTIAN);

    triangleList[10] = Triangle(Vertex(5, 0, 5),
                                Vertex(0, -6, 5),
                               Vertex(-3, 0, 5),

                               ColorDbl(1, 1, 1),
                                LAMBERTIAN);

    triangleList[11] = Triangle(Vertex(5, 0, 5),
                                Vertex(-3, 0, 5),
                               Vertex(0, 6, 5),

                               ColorDbl(1, 1, 1),
                                LAMBERTIAN);

    //__________________SOUTH____________________
    triangleList[12] = Triangle(Vertex(10, -6, -5),
                                Vertex(0, -6, -5),
                                Vertex(0, -6, 5),
                                ColorDbl(0, 0, 0.5),
                                LAMBERTIAN);

    triangleList[13] = Triangle(Vertex(10, -6, -5),
                                Vertex(0, -6, 5),
                                Vertex(10, -6, 5),
                                ColorDbl(0, 0, 0.5),
                                LAMBERTIAN);

    //__________________NORTH____________________
    triangleList[14] = Triangle(Vertex(10, 6, -5),
                                Vertex(10, 6, 5),
                                Vertex(0, 6, -5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    triangleList[15] = Triangle(Vertex(0, 6, -5),
                                Vertex(10, 6, 5),
                                Vertex(0, 6, 5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    //__________________NORTH-EAST___________________
    triangleList[16] = Triangle(Vertex(13, 0, -5),
                                Vertex(13, 0, 5),
                                Vertex(10, 6, -5),
                                ColorDbl(0.5, 0, 0),
                                LAMBERTIAN);

    triangleList[17] = Triangle(Vertex(10, 6, -5),
                                Vertex(13, 0, 5),
                                Vertex(10, 6, 5),
                                ColorDbl(0.5, 0, 0),
                                LAMBERTIAN);

    //__________________SOUTH-EAST___________________
    triangleList[18] = Triangle(Vertex(10, -6, -5),
                                Vertex(10, -6, 5),
                                Vertex(13, 0, -5),
                                ColorDbl(1, 1, 0),
                                MIRROR);

    triangleList[19] = Triangle(Vertex(13, 0, -5),
                                Vertex(10, -6, 5),
                                Vertex(13, 0, 5),
                                ColorDbl(1, 1, 0),
                                MIRROR);


    //__________________SOUTH-WEST___________________
    triangleList[20] = Triangle(Vertex(-3, 0, -5),
                                Vertex(-3, 0, 5),
                                Vertex(0, -6, -5),
                                ColorDbl(0.5, 0, 0.5),
                                LAMBERTIAN);

    triangleList[21] = Triangle(Vertex(0, -6, -5),
                                Vertex(-3, 0, 5),
                                Vertex(0, -6, 5),
                                ColorDbl(0.5, 0, 0.5),
                                LAMBERTIAN);

    //__________________NORTH-WEST___________________
    triangleList[22] = Triangle(Vertex(0, 6, -5),
                                Vertex(0, 6, 5),
                                Vertex(-3, 0, -5),
                                ColorDbl(1, 0, 1),
                                LAMBERTIAN);

    triangleList[23] = Triangle(Vertex(-3, 0, -5),
                                Vertex(0, 6, 5),
                                Vertex(-3, 0, 5),
                                ColorDbl(1, 0, 1),
                                LAMBERTIAN);

    tetrahedron = Tetrahedron(Vertex(-1,-1,1));

    sphere = Sphere(1, Vertex(5,0,-1), ColorDbl(0.8,0.8,0), MIRROR);
    //sphere2 = Sphere(1, Vertex(7,-1,0), ColorDbl(0.8,0.8,0));


}

Scene::~Scene() = default;

void Scene::CastRay(Ray &ray, int rayDepth){

    if(rayDepth > 5) return;

    double intensity = 1;
    double minDistance = 1000;

    //Borders
    for(Triangle triangle : triangleList) {
        triangle.rayIntersection(ray, minDistance);
    }

    //Tetrahedron
    tetrahedron.rayIntersection(ray, minDistance);

    //Sphere
    sphere.rayIntersection(ray, minDistance);
    //sphere2.rayIntersection(ray, minDistance);

    if(ray.getRayType() != SHADOW){
        switch (ray.getMaterial()){
            case MIRROR:
            {
                double kr = 0.9; //amount of light reflected
                Ray reflectionRay(ray.getEndPoint(), glm::normalize(reflect(ray.getDirection(), ray.getObjectNormal())), REFLECTION);
                CastRay(reflectionRay, rayDepth + 1);
                ray.setColor(reflectionRay.getColor() * kr);
                break;
            }

            case LIGHT:{
                break;
            }

            case LAMBERTIAN:{

                //shadow ray
                Direction shadowDir = glm::normalize(getLightPoint()-ray.getEndPoint());
                Ray shadowRay = Ray(ray.getEndPoint(), shadowDir, SHADOW);
                CastRay(shadowRay, 0);

                if((glm::length(shadowRay.getEndPoint() - shadowRay.getStart()) - (glm::length(getLightPoint() - shadowRay.getStart())) < DBL_EPSILON)){
                    intensity = 0;
                }
                ray.setColor(ray.getColor()*intensity);
            }

            default:{
                break;
            }
        }
    }




    //ray.setColor(ray.getColor()*glm::max(0.0, glm::dot(ray.getObjectNormal(), (getLightPoint() - ray.getEndPoint()))));

    //compute diffuse reflection
    //double diffuse = glm::max(0.0, glm::dot(ray.getObjectNormal(), (ray.getEndPoint()-getLightPoint())));
}


const Vertex &Scene::getLightPoint() const {
    return lightPoint;
}
