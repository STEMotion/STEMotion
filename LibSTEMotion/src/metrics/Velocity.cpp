//
// Created by mdgaziur001 on 3/29/25.
//

#include <iostream>
#include <ostream>
#include <LibSTEMotion/metrics/Velocity.h>

#include <utility>

namespace STEMotion {
    Velocity::Velocity(std::string name, f64 velocity, Metric metric) : BaseQuantity(std::move(name)) {
        this->velocity = to_mks(velocity, metric);
        this->metric = metric;
    }

    void Velocity::to_metric(Metric metric) {
        this->metric = metric;
    }

    f64 Velocity::display() const {
        switch (metric) {
            case MKS:
                return velocity;
            case CGS:
                return velocity * 100;
            case FPS:
                return velocity * 3.2808399;
            default:
                return -1;
        }
    }

    Metric Velocity::from_unit_string(const char *unit) {
        if (strcmp(unit, "m/s") == 0) {
            return MKS;
        }

        if (strcmp(unit, "cm/s") == 0) {
            return CGS;
        }

        if (strcmp(unit, "ft/s") == 0) {
            return FPS;
        }

        return InvalidMetric;
    }

    f64 Velocity::to_mks(f64 velocity, Metric metric) {
        switch (metric) {
            case MKS:
                return velocity;
            case CGS:
                return velocity / 1e2;
            case FPS:
                return velocity / 3.2808399;
            default:
                return -1;
        }
    }
} // STEMotion