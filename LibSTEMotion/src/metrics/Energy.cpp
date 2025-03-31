//
// Created by mdgaziur001 on 3/29/25.
//

#include <LibSTEMotion/metrics/Energy.h>
#include <utility>

namespace STEMotion {
    Energy::Energy(std::string name, f64 energy, Metric metric) : BaseQuantity(std::move(name)) {
        this->energy = to_mks(energy, metric);
        this->metric = metric;
    }

    void Energy::to_metric(Metric metric) {
        this->metric = metric;
    }

    f64 Energy::to_mks(f64 energy, Metric metric) {
        switch (metric) {
            case MKS:
                return energy;
            case CGS:
                return energy / 1e-7;
            case FPS:
                return energy / 1.3558179483;
            default:
                return -1;
        }
    }

    f64 Energy::display() const {
        switch (metric) {
            case MKS:
                return energy;
            case CGS:
                return energy * 1e-7;
            case FPS:
                return energy * 1.3558179483;
            default:
                return -1;
        }
    }
} // STEMotion