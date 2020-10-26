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

                               ColorDbl(0, 0, 0),
                               LAMBERTIAN);

    triangleList[7] = Triangle(Vertex(5, 0, 5),
                               Vertex(10, 6, 5),
                               Vertex(13, 0, 5),

                               ColorDbl(0, 0, 0),
                               LAMBERTIAN);

    triangleList[8] = Triangle(Vertex(5, 0, 5),
                               Vertex(13, 0, 5),
                               Vertex(10, -6, 5),

                               ColorDbl(0, 0, 0),
                               LAMBERTIAN);

    triangleList[9] = Triangle(Vertex(5, 0, 5),
                               Vertex(10, -6, 5),
                               Vertex(0, -6, 5),

                               ColorDbl(0, 0, 0),
                               LAMBERTIAN);

    triangleList[10] = Triangle(Vertex(5, 0, 5),
                                Vertex(0, -6, 5),
                               Vertex(-3, 0, 5),

                                ColorDbl(0, 0, 0),
                                LAMBERTIAN);

    triangleList[11] = Triangle(Vertex(5, 0, 5),
                                Vertex(-3, 0, 5),
                               Vertex(0, 6, 5),

                                ColorDbl(0, 0, 0),
                                LAMBERTIAN);

    //__________________SOUTH____________________
    triangleList[12] = Triangle(Vertex(10, -6, -5),
                                Vertex(0, -6, -5),
                                Vertex(0, -6, 5),
                                ColorDbl(0.5, 0, 0.5),
                                LAMBERTIAN);

    triangleList[13] = Triangle(Vertex(10, -6, -5),
                                Vertex(0, -6, 5),
                                Vertex(10, -6, 5),
                                ColorDbl(0.5, 0, 0.5),
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
                                MIRROR);

    triangleList[19] = Triangle(Vertex(13, 0, -5),
                                Vertex(10, -6, 5),
                                Vertex(13, 0, 5),
                                ColorDbl(1, 0, 0),
                                MIRROR);


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
                                ColorDbl(1, 1, 0),
                                LAMBERTIAN);

    triangleList[23] = Triangle(Vertex(-3, 0, -5),
                                Vertex(0, 6, 5),
                                Vertex(-3, 0, 5),
                                ColorDbl(1, 1, 0),
                                LAMBERTIAN);

    //AREA LIGHT
    triangleList[24] = Triangle(Vertex(5.5, 0.5, 4.9),
                                Vertex(5.5, -0.5, 4.9),
                                Vertex(4.5, -0.5, 4.9),
                                ColorDbl(1, 1, 1),
                                LIGHT);

    triangleList[25] = Triangle(Vertex(4.5, -0.5, 4.9),
                                Vertex(4.5, 0.5, 4.9),
                                Vertex(5.5, 0.5, 4.9),
                                ColorDbl(1, 1, 1),
                                LIGHT);

    tetrahedron = Tetrahedron(Vertex(8,-1,0));

    sphereList[0] = Sphere(1, Vertex(8,2,2), ColorDbl(0.8,0,0), LAMBERTIAN);
    sphereList[1] = Sphere(1, Vertex(5,1,-3), ColorDbl(0,0,0), MIRROR);
    sphereList[2] = Sphere(1, Vertex(6,-3,-4), ColorDbl(0,0.8,0), LAMBERTIAN);
}

Scene::~Scene() = default;

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0,1);

void Scene::CastRay(Ray &ray, int rayDepth){

    ray.setColor(ColorDbl(0,0,0));
    if(rayDepth > 1) return;

    double intensity = 1;
    double minDistance = 1000;

    //Borders
    for(Triangle triangle : triangleList) {
        triangle.rayIntersection(ray, minDistance);
    }

    //Tetrahedron
    tetrahedron.rayIntersection(ray, minDistance);

    //Spheres
    for(Sphere sphere : sphereList) {
        sphere.rayIntersection(ray, minDistance);
    }

    //if shadowRay we dont need to compute anything more
    if(ray.getRayType() != SHADOW ){
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
                //direct light
                ColorDbl directLighting = computeDirectLight(ray);

                //indirect light:
                ColorDbl indirectLighting = computeIndirectLight(ray, rayDepth);

                //hitColor = (directLighting / M_PI + 2 * indirectLigthing) * isect.hitObject->albedo;
                ray.setColor(directLighting + indirectLighting);
                break;
            }

            default:{
                break;
            }
        }
    }
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
    // cos^2(theta) + sin^2(theta) = 1 -> sin(theta) = sqrt(1 - cos^2(theta))
    float sinTheta = sqrt(1 - r1 * r1);
    float phi = 2 * M_PI * r2;
    float x = sinTheta * cosf(phi);
    float z = sinTheta * sinf(phi);
    return Direction(x, r1, z);
}

ColorDbl Scene::computeDirectLight(Ray &ray){

    ColorDbl directLight = ColorDbl(0,0,0);

    //define corners of area light
    Vertex v0 = Vertex(0, 0, 0);
    Vertex v1 = Vertex(0, 1, 0);
    Vertex v2 = Vertex(1, 0, 0);
    Vertex v3 = Vertex(1, 1, 0);

    Direction lightNormal = Direction (0,0,-1);

    int numberOfShadowRays = 5;
    for(int i = 0; i < numberOfShadowRays; i++){
        double vk;
        //parametrize point q on the area light
        double u = distribution(generator);
        double v = distribution(generator);

        //random point on light surface
        Vertex qi = Vertex(u*(v1-v0) + v*(v2-v0));
        //move to global coordinates
        qi += Vertex(4.5,-0.5,4.89);

        Direction s_i = qi - ray.getEndPoint();
        double d_i = glm::length(s_i);
        double cos_alpha = glm::max(0.0, glm::dot(-s_i,lightNormal));
        double cos_beta = glm::max(0.0,glm::dot(s_i,ray.getObjectNormal()));

        //shadow ray
        Direction rayDir = glm::normalize(s_i);
        Ray shadowRay = Ray(ray.getEndPoint(), rayDir, SHADOW);
        CastRay(shadowRay, 0);
        double shadowRayLength = glm::length(shadowRay.getEndPoint() - shadowRay.getStart());

        if(shadowRayLength < d_i ){
            vk = 0.0;
        }
        else vk = 1.0;

        directLight += ray.getColor()*vk*(cos_alpha*cos_beta/(d_i*d_i));
    }
    //surface A of light source
    double A = glm::length(glm::cross(v1-v0, v3-v0));

    return  (A*directLight/(double)numberOfShadowRays);
    //return directLight;
}

ColorDbl Scene::computeIndirectLight(Ray &ray, int rayDepth){

    ColorDbl indirectLight;
    // step1: compute shaded point coordinate system using normal N.
    Direction Nt, Nb;
    createLocalCoordinateSystem(ray.getObjectNormal(), Nt, Nb);

    //loop
    uint32_t N = 4; //number of sample rays
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
        indirectLight += r1 * (sampleRay.getColor());
        //step 6: repeat steps 2-5 N times
    }
    // step 7: divide the sum by the total number of samples N
    //pdf = 1/2pi
    indirectLight /= (((double)N)*2*M_PI);

    return indirectLight;
}

