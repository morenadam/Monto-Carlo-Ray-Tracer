//
// Created by Adam on 9/13/2020.
//

#include "Pixel.h"

Pixel::Pixel() = default;

Pixel::~Pixel() = default;

ColorDbl Pixel::getColor() {
    return color;
}

void Pixel::setColor(const ColorDbl _color) {
    Pixel::color = _color;
}

float Pixel::getBrightness() const {
    return brightness;
}

void Pixel::setBrightness(float _brightness) {
    Pixel::brightness = _brightness;
}
