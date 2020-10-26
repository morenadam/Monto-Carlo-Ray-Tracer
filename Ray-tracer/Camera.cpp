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
    int samplesPerPixel = 4;

    const double delta = 0.005; //side length of each pixel

    Vertex pixelCenter;
    ColorDbl sampledPixelColor;
    Vertex subPixelPoint;

    for (int i = 0; i < imageHeight; ++i) {
        if (i % 10 == 0) std::cout << "\r" << i*100.0/400 << "%" << std::endl;
        for (int j = 0; j < imageWidth; ++j) {

            //Calculate center of pixel (i,j)
            pixelCenter = Vertex(0.0, (201.0 - (double)i + 0.5) * delta, (201.0 - (double)j + 0.5) * delta);
            sampledPixelColor = ColorDbl (0,0,0);
            // Supersampling
            for (int k = 0; k < samplesPerPixel; k++)
            {
                double rand_y = ((double)rand() / RAND_MAX) / 2.0;
                double rand_z = ((double)rand() / RAND_MAX) / 2.0;

                switch(k) {
                    case 0:
                        subPixelPoint = pixelCenter + Vertex(0.0, - rand_y*delta, rand_z*delta);
                        break;
                    case 1:
                        subPixelPoint = pixelCenter + Vertex(0, rand_y*delta, rand_z*delta);
                        break;
                    case 2:
                        subPixelPoint = pixelCenter + Vertex(0, - rand_y*delta, - rand_z*delta);
                        break;
                    case 3:
                        subPixelPoint = pixelCenter + Vertex(0, rand_y*delta, - rand_z*delta);
                    default:
                        break;
                }

                //create new ray
                Ray ray(eyePoint, glm::normalize(subPixelPoint - eyePoint), PRIME);
                int rayDepth = 0;
                //find ray-triangle intersection point
                scene.CastRay(ray, rayDepth);
                sampledPixelColor += ray.getColor();
            }
            ColorDbl pixelColor = sampledPixelColor/(double)samplesPerPixel;

            image[i][j].setColor(pixelColor);

            //Store the highest color value
            double newMax = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);


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
        ofs << (unsigned char)((image[i][j].getColor().x) * (double)255.99f /iMax) <<
            (unsigned char)((image[i][j].getColor().y) * (double)255.99f /iMax) <<
            (unsigned char)((image[i][j].getColor().z) * (double)255.99f /iMax);
    }}
    ofs.close();
    //delete[] image;

    std::cout << "Finished" << std::endl;

}
