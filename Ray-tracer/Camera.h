//
// Created by Adam on 9/15/2020.
//

#ifndef RAY_TRACER_CAMERA_H
#define RAY_TRACER_CAMERA_H

#include "Definitions.h"
#include "Pixel.h"
#include "Ray.h"
#include <vector>

/*
 * - It contains two instances of Vertex(the eye points) and a variable that allows you to switch between both eye points.
 * - It contains a 2D array of size 800×800. Each element is a Pixel.
 * - Its method render() launches a ray through each pixel one at a time.
 * - The ray is followed through the scene and the radiance we give to the pixel is computed according to what we learnt in lectures 4 and 5.
 * - Initially and to test your code you follow the ray until it hits the first triangle and assign the triangle color to the ray.
 * - Camera also contains a method createImage():
 */
class Camera {

private:
    static const int imageHeight = 800;
    static const int imageWidth = 800;
    Vertex eyePointOne = Vertex(-2,0,0,1);
    Vertex eyePointTwo = Vertex(-1,0,0,1);
    bool isEyePointOne = true;
    std::vector<std::vector<Pixel>> image;

public:
    Camera() : image(imageHeight, std::vector<Pixel>(imageWidth)) {};

    ~Camera();

    void render();

    void createImage();

    void switchEyePoint();

};


#endif //RAY_TRACER_CAMERA_H
