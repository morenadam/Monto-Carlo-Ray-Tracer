//
// Created by Chris Paulusson on 2020-09-13.
//

#include "Scene.h"
#include "Definitions.h"
#include "Triangle.h"

#include <iostream>
#include <string>
#include <random>

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
                                ColorDbl(1, 0, 0),
                                LAMBERTIAN);

    triangleList[15] = Triangle(Vertex(0, 6, -5),
                                Vertex(10, 6, 5),
                                Vertex(0, 6, 5),
                                ColorDbl(1, 0, 0),
                                LAMBERTIAN);

    //__________________NORTH-EAST___________________
    triangleList[16] = Triangle(Vertex(13, 0, -5),
                                Vertex(13, 0, 5),
                                Vertex(10, 6, -5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    triangleList[17] = Triangle(Vertex(10, 6, -5),
                                Vertex(13, 0, 5),
                                Vertex(10, 6, 5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    //__________________SOUTH-EAST___________________
    triangleList[18] = Triangle(Vertex(10, -6, -5),
                                Vertex(10, -6, 5),
                                Vertex(13, 0, -5),
                                ColorDbl(1, 0, 0),
                                LAMBERTIAN);

    triangleList[19] = Triangle(Vertex(13, 0, -5),
                                Vertex(10, -6, 5),
                                Vertex(13, 0, 5),
                                ColorDbl(1, 0, 0),
                                LAMBERTIAN);


    //__________________SOUTH-WEST___________________
    triangleList[20] = Triangle(Vertex(-3, 0, -5),
                                Vertex(-3, 0, 5),
                                Vertex(0, -6, -5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    triangleList[21] = Triangle(Vertex(0, -6, -5),
                                Vertex(-3, 0, 5),
                                Vertex(0, -6, 5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    //__________________NORTH-WEST___________________
    triangleList[22] = Triangle(Vertex(0, 6, -5),
                                Vertex(0, 6, 5),
                                Vertex(-3, 0, -5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    triangleList[23] = Triangle(Vertex(-3, 0, -5),
                                Vertex(0, 6, 5),
                                Vertex(-3, 0, 5),
                                ColorDbl(0, 1, 0),
                                LAMBERTIAN);

    tetrahedron = Tetrahedron(Vertex(-2,-1,1));

    sphere = Sphere(1, Vertex(8,2,2), ColorDbl(0.8,0.8,0), LAMBERTIAN);
    sphere2 = Sphere(1, Vertex(5,3,-4), ColorDbl(0,0,0), MIRROR);


}

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0, 1);

Scene::~Scene() = default;

void Scene::CastRay(Ray &ray, int rayDepth){

    ray.setColor(ColorDbl(0,0,0));
    if(rayDepth > 3) return;

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
    sphere2.rayIntersection(ray, minDistance);

    //if shadowRay we dont need more info
    if(ray.getRayType() != SHADOW){
        switch (ray.getMaterial()){
            case MIRROR:
            {
                if(ray.getRayType() == SECONDARY) break;
                double kr = 0.95; //amount of light reflected
                Ray reflectionRay(ray.getEndPoint(), glm::normalize(reflect(ray.getDirection(), ray.getObjectNormal())), REFLECTION);
                CastRay(reflectionRay, rayDepth);
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
                CastRay(shadowRay, rayDepth);

                if((glm::length(shadowRay.getEndPoint() - shadowRay.getStart()) - (glm::length(getLightPoint() - shadowRay.getStart())) < DBL_EPSILON)){
                    intensity = 0.0;
                }

                //direct light
                ColorDbl directLighting= ColorDbl(1,1,1);
                directLighting *= (glm::max(0.0, glm::dot(ray.getObjectNormal(),shadowRay.getDirection())) * intensity );

                //indirect light:
                ColorDbl indirectLighting = ColorDbl(0,0,0);

                // step1: compute shaded point coordinate system using normal N.
                Direction Nt, Nb;
                createLocalCoordinateSystem(ray.getObjectNormal(), Nt, Nb);

                //loop
                uint32_t N = 10; //number of sample rays
                double pdf = 1 / (2 * M_PI);
                for (uint32_t n = 0; n < N; ++n) {
                    // step 2: create sample in world space
                    double r1 = distribution(generator);
                    double r2 = distribution(generator);
                    Direction sample = uniformSampleHemisphere(r1, r2);

                    // step 3: transform sample from world space to shaded point local coordinate system
                    Direction sampleWorld(
                            sample.x * Nb.x + sample.y * ray.getObjectNormal().x + sample.z * Nt.x,
                            sample.x * Nb.y + sample.y * ray.getObjectNormal().y + sample.z * Nt.y,
                            sample.x * Nb.z + sample.y * ray.getObjectNormal().z + sample.z * Nt.z);

                    // step 4 & 5: cast a ray in this direction
                    Ray sampleRay = Ray(ray.getEndPoint(), sampleWorld, SECONDARY);
                    CastRay(sampleRay, rayDepth + 1);
                    indirectLighting += r1 * (sampleRay.getColor()*pdf);
                }
                // step 7: divide the sum by the total number of samples N
                indirectLighting /= (double)N;

                ray.setColor((directLighting/M_PI + 2.0*indirectLighting)*ray.getColor());
                break;
            }

            default:{
                break;
            }
        }
    }
}

const Vertex &Scene::getLightPoint() const {
    return lightPoint;
}

void Scene::createLocalCoordinateSystem(const Direction &N, Direction &Nt, Direction &Nb)
{
    if (std::fabs(N.x) > std::fabs(N.y))
        Nt = Direction(N.z, 0, -N.x) / sqrt(N.x * N.x + N.z * N.z);
    else
        Nt = Direction(0, -N.z, N.y) / sqrt(N.y * N.y + N.z * N.z);
    Nb = glm::cross(N, Nt);
}

Direction Scene::uniformSampleHemisphere(const double &r1, const double &r2)
{
    // cos(theta) = r1 = y
    // cos^2(theta) + sin^2(theta) = 1 -> sin(theta) = srtf(1 - cos^2(theta))
    float sinTheta = sqrt(1 - r1 * r1);
    float phi = 2 * M_PI * r2;
    float x = sinTheta * cosf(phi);
    float z = sinTheta * sinf(phi);
    return Direction(x, r1, z);
}