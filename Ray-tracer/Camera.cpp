//
// Created by Adam on 9/15/2020.
//
#include <iostream>
#include <fstream>
#include "Camera.h"


Camera::Camera() : image(imageHeight, std::vector<Pixel>(imageWidth)) {}

Camera::~Camera() = default;

void Camera::switchEyePoint() {
    isEyePointOne = !isEyePointOne;
}

void Camera::render(Scene scene) {

    std::cout << "Rendering Scene..." << std::endl;

    //set starting point of ray
    Vertex eyePoint;
    if (isEyePointOne) eyePoint = eyePointOne;
    else eyePoint = eyePointTwo;

    const float delta = 0.005; //side length of each pixel


    for (int i = 0; i < imageHeight; ++i) {
        if (i % 10 == 0) std::cout << "\r" << (float)i*100.0f/400.0f << "%" << std::endl;
        for (int j = 0; j < imageWidth; ++j) {
            float rand_y = 0.5;
            float rand_z = 0.5;

            //Calculate ray-pixel intersection point for pixel (i,j)
            Vertex pixelPoint = Vertex(0.0, (201.0f - (float)i + rand_y) * delta, (201.0f - (float)j + rand_z) * delta);

            //create new ray
            Ray ray(eyePoint, glm::normalize(pixelPoint - eyePoint), PRIME);

            int rayDepth = 0;
            //find ray-triangle intersection point
            scene.CastRay(ray, rayDepth);

            image[i][j].setColor(ray.getColor());

            //Store the highest color value
            float newMax = glm::max(glm::max(ray.getColor().x, ray.getColor().y), ray.getColor().z);
            if(newMax > iMax) {
                iMax = newMax;
            }
        }
    }

}

void Camera::createImage() {
    std::ofstream ofs("./scene.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << imageWidth << " " << imageHeight << "\n255\n";
    for (int j = 0; j < imageHeight; ++j) {
        for (int i = 0; i < imageWidth; ++i) {
        ofs << (unsigned char)((image[i][j].getColor().x) * (float)255.99 /iMax) <<
            (unsigned char)((image[i][j].getColor().y) * (float)255.99 /iMax) <<
            (unsigned char)((image[i][j].getColor().z) * (float)255.99 /iMax);
    }}
    ofs.close();
    //delete[] image;

    std::cout << "Finished" << std::endl;

}
