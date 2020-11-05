//
// Created by Chris Paulusson on 2020-09-13.
//

#include "Scene.h"
#include "Definitions.h"
#include "Triangle.h"
//#include <string>
#include <random>

Scene::Scene() {

    //__________________FLOOR____________________
    triangleList[0] = Triangle(Vertex(5.0f, 0.0f, -5.0f),
                               Vertex(10.0f, 6.0f, -5.0f),
                               Vertex(0.0f, 6.0f, -5.0f),
                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[1] = Triangle(Vertex(5.0f, 0.0f, -5.0f),
                               Vertex(13.0f, 0.0f, -5.0f),
                               Vertex(10.0f, 6.0f, -5.0f),
                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[2] = Triangle(Vertex(5.0f, 0.0f, -5.0f),
                               Vertex(10.0f, -6.0f, -5.0f),
                               Vertex(13.0f, 0.0f, -5.0f),
                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[3] = Triangle(Vertex(5.0f, 0.0f, -5.0f),
                               Vertex(0.0f, -6.0f, -5.0f),
                               Vertex(10.0f, -6.0f, -5.0f),
                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[4] = Triangle(Vertex(5.0f, 0.0f, -5.0f),
                               Vertex(-3.0f, 0.0f, -5.0f),
                               Vertex(0.0f, -6.0f, -5.0f),
                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[5] = Triangle(Vertex(5.0f, 0.0f, -5.0f),
                               Vertex(0.0f, 6.0f, -5.0f),
                               Vertex(-3.0f, 0.0f, -5.0f),
                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    //__________________CEILING____________________
    triangleList[6] = Triangle(Vertex(5.0f, 0.0f, 5.0f),
                               Vertex(0.0f, 6.0f, 5.0f),
                               Vertex(10.0f, 6.0f, 5.0f),

                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[7] = Triangle(Vertex(5.0f, 0.0f, 5.0f),
                               Vertex(10.0f, 6.0f, 5.0f),
                               Vertex(13.0f, 0.0f, 5.0f),

                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[8] = Triangle(Vertex(5.0f, 0.0f, 5.0f),
                               Vertex(13.0f, 0.0f, 5.0f),
                               Vertex(10.0f, -6.0f, 5.0f),

                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[9] = Triangle(Vertex(5.0f, 0.0f, 5.0f),
                               Vertex(10.0f, -6.0f, 5.0f),
                               Vertex(0.0f, -6.0f, 5.0f),

                               ColorDbl(1.0f, 1.0f, 1.0f),
                               LAMBERTIAN);

    triangleList[10] = Triangle(Vertex(5.0f, 0.0f, 5.0f),
                                Vertex(0.0f, -6.0f, 5.0f),
                               Vertex(-3.0f, 0.0f, 5.0f),

                                ColorDbl(1.0f, 1.0f, 1.0f),
                                LAMBERTIAN);

    triangleList[11] = Triangle(Vertex(5.0f, 0.0f, 5.0f),
                                Vertex(-3.0f, 0.0f, 5.0f),
                               Vertex(0.0f, 6.0f, 5.0f),

                                ColorDbl(1.0f, 1.0f, 1.0f),
                                LAMBERTIAN);

    //__________________SOUTH____________________
    triangleList[12] = Triangle(Vertex(10.0f, -6.0f, -5.0f),
                                Vertex(0.0f, -6.0f, -5.0f),
                                Vertex(0.0f, -6.0f, 5.0f),
                                ColorDbl(0.2f, 1.0f, 0.2f),
                                LAMBERTIAN);

    triangleList[13] = Triangle(Vertex(10.0f, -6.0f, -5.0f),
                                Vertex(0.0f, -6.0f, 5.0f),
                                Vertex(10.0f, -6.0f, 5.0f),
                                ColorDbl(0.2f, 1.0f, 0.2f),
                                LAMBERTIAN);

    //__________________NORTH____________________
    triangleList[14] = Triangle(Vertex(10.0f, 6.0f, -5.0f),
                                Vertex(10.0f, 6.0f, 5.0f),
                                Vertex(0.0f, 6.0f, -5.0f),
                                ColorDbl(1.0f, 0.2f, 0.2f),
                                LAMBERTIAN);

    triangleList[15] = Triangle(Vertex(0.0f, 6.0f, -5.0f),
                                Vertex(10.0f, 6.0f, 5.0f),
                                Vertex(0.0f, 6.0f, 5.0f),
                                ColorDbl(1.0f, 0.2f, 0.2f),
                                LAMBERTIAN);

    //__________________NORTH-EAST___________________
    triangleList[16] = Triangle(Vertex(13.0f, 0.0f, -5.0f),
                                Vertex(13.0f, 0.0f, 5.0f),
                                Vertex(10.0f, 6.0f, -5.0f),
                                ColorDbl(0.2f, 0.2f, 1.0f),
                                LAMBERTIAN);

    triangleList[17] = Triangle(Vertex(10.0f, 6.0f, -5.0f),
                                Vertex(13.0f, 0.0f, 5.0f),
                                Vertex(10.0f, 6.0f, 5.0f),
                                ColorDbl(0.2f, 0.2f, 1.0f),
                                LAMBERTIAN);

    //__________________SOUTH-EAST___________________
    triangleList[18] = Triangle(Vertex(10.0f, -6.0f, -5.0f),
                                Vertex(10.0f, -6.0f, 5.0f),
                                Vertex(13.0f, 0.0f, -5.0f),
                                ColorDbl(0.2f, 1.0f, 0.2f),
                                MIRROR);

    triangleList[19] = Triangle(Vertex(13.0f, 0.0f, -5.0f),
                                Vertex(10.0f, -6.0f, 5.0f),
                                Vertex(13.0f, 0.0f, 5.0f),
                                ColorDbl(0.2f, 1.0f, 0.2f),
                                MIRROR);


    //__________________SOUTH-WEST___________________
    triangleList[20] = Triangle(Vertex(-3.0f, 0.0f, -5.0f),
                                Vertex(-3.0f, 0.0f, 5.0f),
                                Vertex(0.0f, -6.0f, -5.0f),
                                ColorDbl(0.0f, 1.0f, 0.0f),
                                LAMBERTIAN);

    triangleList[21] = Triangle(Vertex(0.0f, -6.0f, -5.0f),
                                Vertex(-3.0f, 0.0f, 5.0f),
                                Vertex(0.0f, -6.0f, 5.0f),
                                ColorDbl(0.0f, 1.0f, 0.0f),
                                LAMBERTIAN);

    //__________________NORTH-WEST___________________
    triangleList[22] = Triangle(Vertex(0.0f, 6.0f, -5.0f),
                                Vertex(0.0f, 6.0f, 5.0f),
                                Vertex(-3.0f, 0.0f, -5.0f),
                                ColorDbl(1.0f, 1.0f, 0.0f),
                                LAMBERTIAN);

    triangleList[23] = Triangle(Vertex(-3.0f, 0.0f, -5.0f),
                                Vertex(0.0f, 6.0f, 5.0f),
                                Vertex(-3.0f, 0.0f, 5.0f),
                                ColorDbl(1.0f, 1.0f, 0.0f),
                                LAMBERTIAN);

    //AREA LIGHT
    triangleList[24] = Triangle(Vertex(5.5f, 0.5f, 4.9f),
                                Vertex(5.5f, -0.5f, 4.9f),
                                Vertex(4.5f, -0.5f, 4.9f),
                                ColorDbl(1.0f, 1.0f, 1.0f),
                                LIGHT);

    triangleList[25] = Triangle(Vertex(4.5f, -0.5f, 4.9f),
                                Vertex(4.5f, 0.5f, 4.9f),
                                Vertex(5.5f, 0.5f, 4.9f),
                                ColorDbl(1.0f, 1.0f, 1.0f),
                                LIGHT);

    tetrahedron = Tetrahedron(Vertex(10.0f,1.0f,0.0f));

    //sphereList[0] = Sphere(1.0f, Vertex(8.0f,2.0f,2.0f), ColorDbl(0.0f,0.0f,0.0f), MIRROR);
    //sphereList[1] = Sphere(1.0f, Vertex(7.0f,-3.0f,-4.0f), ColorDbl(0.8f,0.0f,0.0f), LAMBERTIAN);
    //sphereList[2] = Sphere(1, Vertex(6,-3,-4), ColorDbl(0,0.8,0), LAMBERTIAN);
    sphereList[1] = Sphere(1.0f, Vertex(4.0f,3.0f,-2.0f), ColorDbl(0.5f,0.5f,0.5f), TRANSPARENT);
    sphereList[2] = Sphere(0.5f, Vertex(5.0f,-3.0f,0.0f), ColorDbl(0.5f,0.5f,0.5f), TRANSPARENT);
    sphereList[3] = Sphere(0.5f, Vertex(8.0f,1.0f,-2.0f), ColorDbl(0.5f,0.5f,0.5f), TRANSPARENT);
    sphereList[4] = Sphere(1.0f, Vertex(7.0f,-1.0f,-4.0f), ColorDbl(0.5f,0.5f,0.5f), MIRROR);
    sphereList[5] = Sphere(1.0f, Vertex(10.0f,3.0f,-4.0f), ColorDbl(0.5f,0.5f,0.5f), MIRROR);

}

Scene::~Scene() = default;

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution(0.0f,1.0f);

void Scene::CastRay(Ray &ray, int rayDepth){

    ray.setColor(ColorDbl(0.0f,0.0f,0.0f));
    if(rayDepth > 10) return;

    float minDistance = 1000;

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
                if(ray.getRayType() == SECONDARY){
                    ray.setColor(ColorDbl(0.0f,0.0f,0.0f));
                    break;
                }
                float kr = 1; //amount of light reflected
                Ray reflectionRay(ray.getEndPoint(), glm::normalize(reflect(ray.getDirection(), ray.getObjectNormal())), REFLECTION);
                CastRay(reflectionRay, rayDepth + 1);
                ray.setColor(reflectionRay.getColor() * kr);
                break;
            }

            case LIGHT:{
                break;
            }

            case LAMBERTIAN:{

                //direct light
                ColorDbl directLighting = computeDirectLight(ray, false);

                //indirect light:
                ColorDbl indirectLighting = computeIndirectLight(ray, rayDepth);

                //hitColor = (directLighting / M_PI + 2 * indirectLigthing) * isect.hitObject->albedo;
                ray.setColor(directLighting + indirectLighting);
                break;
            }

            case TRANSPARENT: {

                float n1 = 1.0f; // air
                float n2 = 1.5f; // glass
                Direction N = glm::normalize(ray.getObjectNormal());
                Direction I = glm::normalize(ray.getDirection());

                if(ray.getRayType() == INSIDE_TRANSPARENT) {

                    N = -N;

                    //Schlicks law
                    float R0 = pow(((n2-n1) / (n2 + n1)), 2.0f);
                    float cosTheta = glm::dot(-I,N);
                    float reflectCof = R0 + (1 - R0) * pow(1.0f - cosTheta, 5.0f);
                    float transmission = 1.0f - reflectCof;

                    float brewsterAngle  = asin(n1 / n2);
                    float alpha = acos(glm::dot(-I, N));

                    Direction R = glm::normalize(reflect(I, N));
                    Ray reflectionRay(ray.getEndPoint(), R, INSIDE_TRANSPARENT);

                    // We need to test if the value of alpha gives a new transmitted ray
                    if (alpha > brewsterAngle) {
                        // Totally reflected and no T exists
                        CastRay(reflectionRay, rayDepth + 1);
                        ray.setColor(reflectionRay.getColor()); // Kr (reflection coeff) = 1
                        //ray.setColor(ColorDbl(0,0,0));
                    }
                    else {
                        // Both R and T
                        // hitColor = reflectionColor * kr + refractionColor * (1 - kr);

                        Direction T = glm::normalize((n2/n1) * I + N * (float)(-(n2/n1) *glm::dot(N, I) - sqrt(1.0f - pow((n2/n1), 2.0f)*(1.0f - pow(glm::dot(N, I), 2.0f)))));
                        Ray refractionRay(ray.getEndPoint() - N * 0.002f, T, REFLECTION);

                        // cast both R and T
                        CastRay(reflectionRay, rayDepth + 1);
                        CastRay(refractionRay, rayDepth + 1);

                        // Set color based on Schlicks law
                        ray.setColor((reflectionRay.getColor() * reflectCof + refractionRay.getColor() * transmission));
                        //ray.setColor((refractionRay.getColor() * transmission));

                    }
                }
                else {

                    //Schlicks law
                    float R0 = pow(((n1-n2) / (n1 + n2)), 2.0f);
                    float cosTheta = glm::dot(-I,N);
                    float reflectCof = R0 + (1 - R0) * pow(1.0f - cosTheta, 5.0f);
                    float transmission = 1.0f - reflectCof;

                    Direction R = glm::normalize(reflect(I, N));
                    Ray reflectionRay(ray.getEndPoint(), R, REFLECTION);

                    Direction T = glm::normalize((n1/n2) * I + N * (float)(-(n1/n2) *glm::dot(N, I) - sqrt(1.0f - pow((n1/n2), 2.0f)*(1.0f - pow(glm::dot(N, I), 2.0f)))));
                    Ray refractionRay(ray.getEndPoint() - N * 0.002f, T, INSIDE_TRANSPARENT);

                    // cast both R and T
                    CastRay(reflectionRay, rayDepth + 1);
                    CastRay(refractionRay, rayDepth + 1);

                    // Set color based on Schlicks law
                    ray.setColor((reflectionRay.getColor() * reflectCof + refractionRay.getColor() * transmission));
                    //ray.setColor((reflectionRay.getColor() * reflectCof));
                }

            }
            case OREN_NAYAR:{

            }

            default:{
                break;
            }
        }
    }
}

ColorDbl Scene::computeDirectLight(Ray &ray, bool orenNayar){

    ColorDbl directLight = ColorDbl(0.0f,0.0f,0.0f);

    //define corners of area light
    Vertex v0 = Vertex(0.0f, 0.0f, 0.0f);
    Vertex v1 = Vertex(0.0f, 1.0f, 0.0f);
    Vertex v2 = Vertex(1.0f, 0.0f, 0.0f);
    Vertex v3 = Vertex(1.0f, 1.0f, 0.0f);

    Direction lightNormal = Direction (0.0f,0.0f,-1.0f);

    int numberOfShadowRays = 1;
    for(int i = 0; i < numberOfShadowRays; i++){
        float vk;
        //parametrize point q on the area light
        float u = distribution(generator);
        float v = distribution(generator);

        //random point on light surface
        Vertex qi = Vertex(u*(v1-v0) + v*(v2-v0));
        //move to global coordinates
        qi += Vertex(4.5f,-0.5f,4.8f);

        Direction s_i = qi - ray.getEndPoint();
        float d_i = glm::length(s_i);
        float cos_alpha = glm::max(0.0f, glm::dot(-s_i,lightNormal));
        float cos_beta = glm::max(0.0f,glm::dot(s_i,ray.getObjectNormal()));

        //shadow ray
        Direction rayDir = glm::normalize(s_i);
        Ray shadowRay = Ray(ray.getEndPoint(), rayDir, SHADOW);
        CastRay(shadowRay, 0);
        float shadowRayLength = glm::length(shadowRay.getEndPoint() - shadowRay.getStart());

        if(shadowRayLength < d_i && shadowRay.getMaterial() != TRANSPARENT ){
            vk = 0.0f;
        }
        else vk = 1.0f;

        if(orenNayar){

            std::random_device dev;
            std::mt19937 gen(dev());

            float roughness = 0.9f;
            float sigma2 = roughness * roughness;

            float in_angle = acos(dot(rayDir, ray.getObjectNormal()));

            std::normal_distribution<float> distNormal(0.0f, sigma2);

            float phi_out = distNormal(gen) * float(M_PI); //random azimuth angle for outgoing ray
            float theta_out = asin(sqrt(distNormal(gen))); //"random" inclination, optimized for near normal's direction

            float A = 1.0f - 0.5f * (sigma2) / (sigma2 + 0.33f);
            float B = 0.45f * (sigma2) / (sigma2 + 0.09f);

            float alpha = std::max(in_angle, theta_out); //max of in_angle and theta_out
            float beta = std::min(in_angle, theta_out); //min of in_angle and theta_out
            float maxPhi = std::max((float)cos(-phi_out), 0.0f); //max of cos(-phi_out) and 0

            float BRDF = A + (B * maxPhi) * sin(alpha) * tan(beta);

            directLight += 0.9f*BRDF*ray.getColor()*vk*(cos_alpha*cos_beta/(d_i*d_i));
        }
        else directLight += 0.9f*ray.getColor()*vk*(cos_alpha*cos_beta/(d_i*d_i));


    }
    //surface A of light source
    float A = glm::length(glm::cross(v1-v0, v3-v0));

    return  (A*directLight/(float)numberOfShadowRays);
}

ColorDbl Scene::computeIndirectLight(Ray &ray, int rayDepth){

    ColorDbl indirectLight = ColorDbl(0,0,0);

    //russian roulette
    float P = 0.25;
    float random = (float)rand()/RAND_MAX;

    if(random < P){//terminate 25% of the rays
        return (indirectLight);
    }

    // step1: compute shaded point coordinate system using normal N.
    Direction Nt, Nb;
    createLocalCoordinateSystem(ray.getObjectNormal(), Nt, Nb);

    // step 2: create sample in world space
    float r1 = distribution(generator);
    float r2 = distribution(generator);
    Direction sample = uniformSampleHemisphere(r1, r2);

    // step 3: transform sample from world space to shaded point local coordinate system
    Direction sampleWorld(
            sample.x * Nb.x + sample.y * ray.getObjectNormal().x + sample.z * Nt.x,
            sample.x * Nb.y + sample.y * ray.getObjectNormal().y + sample.z * Nt.y,
            sample.x * Nb.z + sample.y * ray.getObjectNormal().z + sample.z * Nt.z);


    // step 4 & 5: cast a ray in this direction
    Ray sampleRay = Ray(ray.getEndPoint(), glm::normalize(sampleWorld), SECONDARY);
    CastRay(sampleRay, rayDepth + 1);
    indirectLight = (0.9f*ray.getColor()) * r1 * sampleRay.getColor();
    return indirectLight; //divide by (1-P), P = 0.25
}

void Scene::createLocalCoordinateSystem(const Direction &N, Direction &Nt, Direction &Nb)
{
    if (std::fabs(N.x) > std::fabs(N.y))
        Nt = Direction(N.z, 0.0f, -N.x) / (float)sqrt(N.x * N.x + N.z * N.z);
    else
        Nt = Direction(0.0f, -N.z, N.y) / (float)sqrt(N.y * N.y + N.z * N.z);
    Nb = glm::cross(N, Nt);
}

Direction Scene::uniformSampleHemisphere(const float &r1, const float &r2)
{
    // cos(theta) = r1 = y
    // cos^2(theta) + sin^2(theta) = 1 -> sin(theta) = sqrt(1 - cos^2(theta))
    float sinTheta = sqrt(1.0f - r1 * r1);
    float phi = 2.0f * M_PI * r2;
    float x = sinTheta * cosf(phi);
    float z = sinTheta * sinf(phi);
    return Direction(x, r1, z);
}