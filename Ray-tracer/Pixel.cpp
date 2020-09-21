//
// Created by Adam on 9/13/2020.
//

#include "Pixel.h"

Pixel::Pixel() {}

Pixel::~Pixel() {

}

const ColorDbl &Pixel::getColor() const {
    return color;
}

void Pixel::setColor(const ColorDbl color) {
    Pixel::color = color;
}
