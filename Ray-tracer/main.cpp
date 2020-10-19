#include <iostream>
#include "Camera.h"

int main() {

    Camera camera;
    Scene scene;
    //camera.switchEyePoint();
    camera.render(scene);
    camera.createImage();

    return 0;
}