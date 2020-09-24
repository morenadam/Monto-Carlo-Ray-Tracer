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
    iMax = 0; // max intensity value of all pixels

    for (int i = 0; i < imageHeight; ++i) {
        for (int j = 0; j < imageWidth; ++j) {
            double rand_y = (double) rand()/RAND_MAX;
            double rand_z = (double) rand()/RAND_MAX;

            //Calculate ray-pixel intersection point for pixel (i,j)
            Vertex pixelPoint = Vertex(0.0, (401 - i + rand_y) * delta, (401 - j + rand_z) * delta);

            Direction ray_dir = pixelPoint - eyePoint;
            ray_dir = glm::normalize(ray_dir);

            //create new ray
            Ray ray(eyePoint, ray_dir);

            //find ray-triangle intersection point
            scene.FindRayIntersection(ray);
            image[i][j].setColor(ray.getColor());

            //Store the highest color value
            if (double newMax = glm::max(glm::max(ray.getColor().x, ray.getColor().y), ray.getColor().z) > iMax) {
                iMax = newMax;
            }
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
        ofs << (unsigned char)((image[i][j].getColor().x) * (double)255.99f /iMax) <<
            (unsigned char)((image[i][j].getColor().y) * (double)255.99f /iMax) <<
            (unsigned char)((image[i][j].getColor().z) * (double)255.99f /iMax);
    }}
    ofs.close();
    //delete[] image;
}
