//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef TIME_H
#define TIME_H
#include <string>

#include "../utils/numsize.h"

namespace STEMotion {

enum TimeUnit {
    Day = 86400,
    Hour = 3600,
    Minute = 60,
    Second = 1,
    InvalidTimeUnit = -1,
};

class Time {
    // time is represented internally as seconds
    f64 time;
    TimeUnit t_unit;

    const char *units[5] = { "d", "h", "min", "s", "Invalid unit" };

public:
    Time(f64 time, TimeUnit unit);
    [[nodiscard]] f64 display() const;
    [[nodiscard]] static TimeUnit from_string(const char *);

    [[nodiscard]] const char* unit() const {
        return units[t_unit];
    }

    [[nodiscard]] const char **get_units() {
        return units;
    }
};

}



#endif //TIME_H
