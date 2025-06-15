//
// Created by MD Gaziur Rahman Noor on 14/6/25.
//

#ifndef ANGLE_H
#define ANGLE_H

#include <cmath>
#include <cstring>

#include "LibSTEMotion/utils/numsize.h"

namespace STEMotion {

    enum AngleUnit { Radian, Degree, InvalidAngleUnit };

    class Angle {
        f64 angle;
        AngleUnit a_unit;

        const char *units[3] = {"rad", "deg", "Invalid Unit"};

    public:
        Angle(f64 angle, AngleUnit unit);
        [[nodiscard]] f64 display() const;
        [[nodiscard]] static AngleUnit from_string(const char *unit);

        [[nodiscard]] const char *unit() const { return units[a_unit]; }

        [[nodiscard]] const char **get_units() { return units; }
    };

} // namespace STEMotion

#endif // ANGLE_H
