//
// Created by MD Gaziur Rahman Noor on 15/6/25.
//

#ifndef OBJECT_H
#define OBJECT_H
#include "LibSTEMotion/utils/numsize.h"


namespace STEMotion {
    enum ObjectKind {
        ObjectKindCircle,
        ObjectKindRectangle,
        ObjectKindLine,
        ObjectKindTriangle,
        ObjectKindText,
    };

    struct Circle {
        f64 radius;
    };

    struct Rectangle {
        f64 height;
        f64 width;
    };

    struct Line {
        f64 x1, y1;
        f64 x2, y2;
    };

    struct Triangle {
        f64 x1, y1;
        f64 x2, y2;
        f64 x3, y3;
    };

    struct Text {
        char text[256];
    };

    struct Object {
        union {
            Circle circle;
            Rectangle rectangle;
            Line line;
            Triangle triangle;
            Text text;
        };
        f64 x0, y0;

        ObjectKind kind;
    };
}; // namespace STEMotion


#endif // OBJECT_H
