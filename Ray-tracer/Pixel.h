//
// Created by Adam on 9/13/2020.
//

#ifndef RAY_TRACER_PIXEL_H
#define RAY_TRACER_PIXEL_H
#include "Definitions.h"
#include "Ray.h"

//Pixel contains one instance of ColorDbl that holds the color and
//intensity for this pixel with a high dynamic range.
//Pixel has references to the rays that go through it.  We use for now one.
class Pixel {
private:
    ColorDbl color = ColorDbl(0.0f,0.0f,0.0f);
    Ray ray;
    float brightness = 1.0;

public:
    Pixel();
    ~Pixel();

    ColorDbl getColor();
    void setColor(ColorDbl _color);

    float getBrightness() const;

    void setBrightness(float _brightness);

};


#endif //RAY_TRACER_PIXEL_H
