//
// Created by Chris Paulusson on 2020-09-13.
//

#ifndef UNTITLED_COLORDBL_H
#define UNTITLED_COLORDBL_H

//It has three double precision variables that contain the intensities in the red, green and blue channel.
class ColorDbl {

private:

    double r, g, b;

public:

    ColorDbl();

    ColorDbl(double _r, double _g, double _b){
        r = _r, g = _g, b = _b;
    }

    ~ColorDbl();

};


#endif //UNTITLED_COLORDBL_H
