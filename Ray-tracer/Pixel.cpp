//
// Created by Adam on 9/13/2020.
//

#include "Pixel.h"

Pixel::Pixel() {}

Pixel::~Pixel() {

}

ColorDbl Pixel::getColor() {
    return color;
}

void Pixel::setColor(const ColorDbl color) {
    Pixel::color = color;
}

double Pixel::getBrightness() const {
    return brightness;
}

void Pixel::setBrightness(double brightness) {
    Pixel::brightness = brightness;
}
