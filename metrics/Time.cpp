//
// Created by mdgaziur001 on 3/29/25.
//

#include "Time.h"

namespace STEMotion {
    Time::Time(f64 time, Unit unit) {
        this->time = time * unit;
        this->t_unit = unit;
    }

    f64 Time::display() const {
        return time / t_unit;
    }

    std::string Time::unit() const {
        switch (t_unit) {
            case Day:
                return "d";
            case Hour:
                return "h";
            case Minute:
                return "min";
            case Second:
                return "s";
            default:
                return "";
        }
    }
}
