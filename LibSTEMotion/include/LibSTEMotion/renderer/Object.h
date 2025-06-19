//
// Created by MD Gaziur Rahman Noor on 15/6/25.
//

#pragma once

#include "LibSTEMotion/utils/numsize.h"


namespace STEMotion {
    enum ObjectKind {
        ObjectKindCircle,
        ObjectKindRectangle,
        ObjectKindLine,
        ObjectKindTriangle,
        ObjectKindText,
    };

    enum TextStyle {
        TextStyleRegular,
        TextStyleItalic,
        TextStyleBold,
    };

    struct Circle {
        f32 radius;
    };

    struct Rectangle {
        f32 height;
        f32 width;
    };

    struct Line {
        f32 x1, y1;
        f32 x2, y2;
    };

    struct Triangle {
        f32 x1, y1;
        f32 x2, y2;
        f32 x3, y3;
    };

    struct Text {
        char text[256];
        TextStyle style;
        float size;
    };

    struct Object {
        union {
            Circle circle;
            Rectangle rectangle;
            Line line;
            Triangle triangle;
            Text text;
        };
        f32 x0, y0;

        ObjectKind kind;
    };
}; // namespace STEMotion

