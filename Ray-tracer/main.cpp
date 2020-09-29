#include <iostream>
#include "Camera.h"
#include <list>

int main() {

    Camera camera;
    Scene scene;
    camera.render(scene);
    camera.createImage();

    return 0;
}