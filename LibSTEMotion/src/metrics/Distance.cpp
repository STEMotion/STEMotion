//
// Created by mdgaziur001 on 3/29/25.
//

#include <LibSTEMotion/metrics/Distance.h>

#include <utility>

namespace STEMotion {
    Distance::Distance(std::string name, f64 distance, Metric metric) : BaseQuantity(std::move(name)) {
        this->distance = to_mks(distance, metric);
        this->metric = metric;
    }

    void Distance::to_metric(Metric metric) {
        this->metric = metric;
    }

    f64 Distance::display() const {
        switch (metric) {
            case MKS:
                return distance;
            case CGS:
                return distance * 100;
            case FPS:
                return distance * 3.2808399;
            default:
                return -1;
        }
    }

    [[nodiscard]] Metric Distance::from_unit_string(const char *unit) {
        if (strcmp("m", unit) == 0) {
            return MKS;
        }

        if (strcmp("cm", unit) == 0) {
            return CGS;
        }

        if (strcmp("ft", unit) == 0) {
            return FPS;
        }

        return InvalidMetric;
    }

    f64 Distance::to_mks(f64 distance, Metric metric) {
        switch (metric) {
            case MKS:
                return distance;
            case CGS:
                return distance / 100;
            case FPS:
                return distance / 3.2808399;
            default:
                return -1;
        }
    }
}

