//
// Created by mdgaziur001 on 3/29/25.
//

#include <LibSTEMotion/metrics/Time.h>
#include <cstring>

namespace STEMotion {
    Time::Time(f64 time, TimeUnit unit) {
        this->time = time * static_cast<float>(unit);
        this->t_unit = unit;
    }

    f64 Time::display() const { return time / static_cast<float>(t_unit); }

    TimeUnit Time::from_string(const char *unit) {
        if (strcmp(unit, "d") == 0) {
            return Day;
        }

        if (strcmp(unit, "h") == 0) {
            return Hour;
        }

        if (strcmp(unit, "m") == 0) {
            return Minute;
        }

        if (strcmp(unit, "s") == 0) {
            return Second;
        }

        return InvalidTimeUnit;
    }
} // namespace STEMotion
