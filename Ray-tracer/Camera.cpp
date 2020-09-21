//
// Created by Adam on 9/15/2020.
//

#include "Camera.h"
#include "Ray.h"

Camera::Camera() {}

Camera::~Camera() {

}



void Camera::switchEyePoint() {
    isEyePointOne = !isEyePointOne;
}
void Camera::render() {
    //TODO: check which eyePoint to use here
    for (int j = 0; j < imageHeight; ++j) {
        for (int i = 0; i < imageWidth; ++i) {
            // compute primary ray
            //Ray primRay(eyepoint, pixelpoint);
            //Compute the direction from eyepoint to pixelpoint below
            //primDirection = primRay.computDirection();
            //Shoot the ray in that direction into the scene and search for intersecions
            //primRay shoot(primDirection)

//            Point pHit;
//            Normal nHit;
//            float minDist = INFINITY;
//            Object object = NULL;
//            for (int k = 0; k < objects.size(); ++k) {
//                if (Intersect(objects[k], primRay, &pHit, &nHit)) {
//                    float distance = Distance(eyePosition, pHit);
//                    if (distance < minDistance) {
//                        object = objects[k];
//                        minDistance = distance; // update min distance
//                    }
//                }
//            }
//            if (object != NULL) {
//                // compute illumination
//                Ray shadowRay;
//                shadowRay.direction = lightPosition - pHit;
//                bool isShadow = false;
//                for (int k = 0; k < objects.size(); ++k) {
//                    if (Intersect(objects[k], shadowRay)) {
//                        isInShadow = true;
//                        break;
//                    }
//                }
//            }
//            if (!isInShadow)
//                pixels[i][j] = object->color * light.brightness;
//            else
//                pixels[i][j] = 0;
        }
    }
}

void Camera::createImage() {
    //TODO: create image
}
