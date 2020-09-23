#include <iostream>
#include "Camera.h"
#include <list>

int main() {
    std::cout << "Hello, World Test!" << std::endl;

    Camera camera;
    Scene scene;
    camera.render(scene);
    camera.createImage();
    return 0;
}