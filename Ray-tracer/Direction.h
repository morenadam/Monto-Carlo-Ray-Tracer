//
// Created by Chris Paulusson on 2020-09-13.
//

#ifndef UNTITLED_DIRECTION_H
#define UNTITLED_DIRECTION_H

//It has the three components of a direction vector x, y, z.
class Direction {

private:
    double x, y, z;

public:

    Direction();

    Direction(double _x, double _y, double _z){
        x = _x, y = _y, z = _z;
    }

    ~Direction();
};


#endif //UNTITLED_DIRECTION_H
