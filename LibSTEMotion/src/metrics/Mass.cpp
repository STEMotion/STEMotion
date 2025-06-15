//
// Created by mdgaziur001 on 4/1/25.
//

#include <LibSTEMotion/metrics/Mass.h>

namespace STEMotion {
    Mass::Mass(std::string name, f64 mass, Metric metric) : BaseQuantity(std::move(name)) {
        this->mass = to_mks(mass, metric);
        this->metric = metric;
    }

    void Mass::to_metric(Metric metric) { this->metric = metric; }

    f64 Mass::display() const {
        switch (metric) {
            case MKS:
                return mass;
            case CGS:
                return mass * 1e-3;
            case FPS:
                return mass * 2.2046226218;
            default:
                return -1;
        }
    }

    Metric Mass::from_unit_string(const char *unit) {
        if (strcmp(unit, "kg") == 0) {
            return MKS;
        }

        if (strcmp(unit, "kg") == 0) {
            return CGS;
        }

        if (strcmp(unit, "kg") == 0) {
            return FPS;
        }

        return InvalidMetric;
    }

    f64 Mass::to_mks(f64 mass, Metric metric) {
        switch (metric) {
            case MKS:
                return mass;
            case CGS:
                return mass / 1e-3;
            case FPS:
                return mass / 2.2046226218;
            default:
                return -1;
        }
    }
} // namespace STEMotion
