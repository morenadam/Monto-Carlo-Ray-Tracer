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

    const int subPixel = 8; //total # of subpixels = subPixel*subPixel
    const float delta = 0.0025; //side length of each pixel
    float subPixelLength = delta/float(subPixel); //side length of each sub pixel

    Vertex pixelCenter;
    Vertex subPixelPoint;

    //random number generator
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(-0.5, 0.5);

    for (int i = 0; i < imageHeight; ++i) {
        if (i % 10 == 0) std::cout << "\r" << (float)i*100.0f/float(imageHeight) << "%" << std::endl;
        for (int j = 0; j < imageWidth; ++j) {

            //Calculate center of pixel (i,j)
            pixelCenter = Vertex(0.0f, ((float)imageHeight/2.0f - (float)i + 0.5f) * delta, ((float)imageHeight/2.0f - (float)j + 0.5f) * delta);
            ColorDbl sampledPixelColor = ColorDbl (0,0,0);

            // Supersampling
            for (int n = 0; n < subPixel; n++){
                for (int m = 0; m < subPixel; m++){
                    subPixelPoint = pixelCenter + Vertex(0, ((float)subPixel/2.0f - n + distribution(generator))*subPixelLength, ((float)subPixel/2.0f - m + distribution(generator))*subPixelLength);

                    //create new ray
                    Ray ray(eyePoint, glm::normalize(subPixelPoint - eyePoint), PRIME);
                    int rayDepth = 0;

                    //find ray-triangle intersection point
                    scene.CastRay(ray, rayDepth);
                    sampledPixelColor += ray.getColor();
                }
            }

            ColorDbl pixelColor = sampledPixelColor/(((float)subPixel*(float)subPixel)*(1.0f/0.75f));
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
    std::cout << iMax << std::endl;

    std::cout << "Finished" << std::endl;

}
