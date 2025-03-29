//
// Created by mdgaziur001 on 3/29/25.
//

#include "Distance.h"

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

    std::string Distance::unit() const {
        switch (metric) {
            case MKS:
                return "m";
            case CGS:
                return "cm";
            case FPS:
                return "ft";
            default:
                return "";
        }
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

