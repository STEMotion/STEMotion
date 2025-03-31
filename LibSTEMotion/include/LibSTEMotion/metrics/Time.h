//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef TIME_H
#define TIME_H
#include <string>

#include "../utils/numsize.h"

namespace STEMotion {

enum Unit {
    Day = 86400,
    Hour = 3600,
    Minute = 60,
    Second = 1,
};

class Time {
    // time is represented internally as seconds
    f64 time;
    Unit t_unit;

public:
    Time(f64 time, Unit unit);
    [[nodiscard]] f64 display() const;
    [[nodiscard]] std::string unit() const;
};

}



#endif //TIME_H
