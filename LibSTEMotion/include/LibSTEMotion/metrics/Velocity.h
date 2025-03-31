//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef VELOCITY_H
#define VELOCITY_H
#include <string>

#include "BaseQuantity.h"
#include "metrics.h"

namespace STEMotion {

class Velocity final : public BaseQuantity {
    f64 velocity;
    Metric metric;

    const char *units[3] = { "m/s", "cm/s", "ft/s" };
public:
    Velocity(std::string name, f64 velocity, Metric metric);
    void to_metric(Metric metric) override;
    [[nodiscard]] f64 display() const override;
    [[nodiscard]] std::string unit() const override {
        return units[metric];
    }
    [[nodiscard]] const char** get_units() override {
        return units;
    }

private:
    static f64 to_mks(f64 velocity, Metric metric);
};

} // STEMotion

#endif //VELOCITY_H
