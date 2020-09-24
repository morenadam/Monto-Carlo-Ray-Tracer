//
// Created by Adam on 9/15/2020.
//
#include <iostream>
#include <fstream>
#include "Camera.h"
#include "Scene.h"

Camera::~Camera() {

}



void Camera::switchEyePoint() {
    isEyePointOne = !isEyePointOne;
}
void Camera::render(Scene scene) {

    std::cout << "Hello, from camera!" << std::endl;

    //set starting point of ray
    Vertex eyePoint;
    if (isEyePointOne) eyePoint = eyePointOne;
    else eyePoint = eyePointTwo;

    const double delta = 0.0025; //side length of each pixel

    for (int i = 0; i < imageHeight; ++i) {
        for (int j = 0; j < imageWidth; ++j) {
            double rand_y = (double) rand()/RAND_MAX;
            double rand_z = (double) rand()/RAND_MAX;

            Vertex pixelPoint = Vertex(0.0, (401 - i + rand_y) * delta, (401 - j + rand_z) * delta);

            Direction ray_dir = pixelPoint - eyePoint;
            ray_dir = glm::normalize(ray_dir);

            //create new ray (has no endpoint yet)
            Ray ray(eyePoint, ray_dir);

            scene.FindRayIntersection(ray);
            image[i][j].setColor(ray.getColor());

//            if(j < 400) image[i][j].setColor(ColorDbl(0,1,0));
//            else image[i][j].setColor(ColorDbl(0,0,1));

//            // compute ray direction
//            //Ray primRay(eyepoint, pixelpoint);
//            //Compute the direction from eyepoint to pixelpoint below
//            //primDirection = primRay.computDirection();
//            //Shoot the ray in that direction into the scene and search for intersecions
//            //primRay shoot(primDirection)
//
////            Point pHit;
////            Normal nHit;
////            float minDist = INFINITY;
////            Object object = NULL;
////            for (int k = 0; k < objects.size(); ++k) {
////                if (Intersect(objects[k], primRay, &pHit, &nHit)) {
////                    float distance = Distance(eyePosition, pHit);
////                    if (distance < minDistance) {
////                        object = objects[k];
////                        minDistance = distance; // update min distance
////                    }
////                }
////            }
////            if (object != NULL) {
////                // compute illumination
////                Ray shadowRay;
////                shadowRay.direction = lightPosition - pHit;
////                bool isShadow = false;
////                for (int k = 0; k < objects.size(); ++k) {
////                    if (Intersect(objects[k], shadowRay)) {
////                        isInShadow = true;
////                        break;
////                    }
////                }
////            }
////            if (!isInShadow)
////                pixels[i][j] = object->color * light.brightness;
////            else
////                pixels[i][j] = 0;
        }
    }
}

void Camera::createImage() {
    //TODO: create image
    // Save result to a PPM image (keep these flags if you compile under Windows)
    std::ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << imageWidth << " " << imageHeight << "\n255\n";
    for (int j = 0; j < imageHeight; ++j) {
        for (int i = 0; i < imageWidth; ++i) {
        ofs << (unsigned char)((image[i][j].getColor().x) * (double)255.99) <<
            (unsigned char)((image[i][j].getColor().y) * (double)255.99) <<
            (unsigned char)((image[i][j].getColor().z) * (double)255.99);
    }}
    ofs.close();
    //delete[] image;
}
