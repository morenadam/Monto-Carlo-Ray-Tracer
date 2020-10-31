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
    const float delta = 0.0025; //side length of each pixel

    int samplesPerPixel = 10;
    Vertex pixelCenter;
    ColorDbl sampledPixelColor;
    Vertex subPixelPoint;

    for (int i = 0; i < imageHeight; ++i) {
        if (i % 10 == 0) std::cout << "\r" << (float)i*100.0f/float(imageHeight) << "%" << std::endl;
        for (int j = 0; j < imageWidth; ++j) {

            //Calculate center of pixel (i,j)
            pixelCenter = Vertex(0.0f, (401.0f - (float)i + 0.5f) * delta, (401.0f - (float)j + 0.5f) * delta);
            sampledPixelColor = ColorDbl (0,0,0);

            // Supersampling
            for (int k = 0; k < samplesPerPixel; k++)
            {
                float rand_y = ((float)std::rand() / RAND_MAX) -0.5f; //[-0.5, 0.5]
                float rand_z = ((float)rand() / RAND_MAX) -0.5f; //[-0.5, 0.5]
                subPixelPoint = pixelCenter + Vertex(0, rand_y*delta, rand_z*delta);

                //create new ray
                Ray ray(eyePoint, glm::normalize(subPixelPoint - eyePoint), PRIME);
                int rayDepth = 0;
                //find ray-triangle intersection point
                scene.CastRay(ray, rayDepth);
                sampledPixelColor += ray.getColor();
            }
            ColorDbl pixelColor = sampledPixelColor/(float)samplesPerPixel;

            image[i][j].setColor(pixelColor);

            //Store the highest color value
            float newMax = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);
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
        ofs << (unsigned char)((image[i][j].getColor().x) * (float)255 /iMax) <<
            (unsigned char)((image[i][j].getColor().y) * (float)255 /iMax) <<
            (unsigned char)((image[i][j].getColor().z) * (float)255 /iMax);
    }}
    ofs.close();
    //delete[] image;

    std::cout << "Finished" << std::endl;

}
