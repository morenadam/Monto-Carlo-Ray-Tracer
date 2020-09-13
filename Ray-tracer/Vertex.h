//
// Created by Adam on 9/13/2020.
//

#ifndef UNTITLED_VERTEX_H
#define UNTITLED_VERTEX_H

class Vertex {
private:
    double x;
    double y;
    double z;
    double w;

public:
    Vertex();

    Vertex(double _x, double _y, double _z, double _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    ~Vertex();
};

#endif //UNTITLED_VERTEX_H
