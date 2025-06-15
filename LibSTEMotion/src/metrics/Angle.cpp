//
// Created by MD Gaziur Rahman Noor on 14/6/25.
//

#include "LibSTEMotion/metrics/Angle.h"

namespace STEMotion {
    Angle::Angle(const f64 angle, const AngleUnit unit) {
        this->a_unit = unit;

        switch (a_unit) {
            case Radian:
                this->angle = angle;
                break;
            case Degree:
                this->angle = angle * M_PI / 180;
                break;
            default:
                this->angle = -1;
        }
    }

    f64 Angle::display() const {
        switch (a_unit) {
            case Radian:
                return angle;
            case Degree:
                return angle * 180 / M_PI;
            case InvalidAngleUnit:
                return -1;
        }
    }

    AngleUnit Angle::from_string(const char *unit) {
        if (strcmp("rad", unit) == 0) {
            return Radian;
        }

        if (strcmp("deg", unit) == 0) {
            return Degree;
        }

        return InvalidAngleUnit;
    }
} // namespace STEMotion
