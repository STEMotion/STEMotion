//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef VELOCITY_H
#define VELOCITY_H
#include <string>

#include "BaseQuantity.h"
#include "metrics.h"

namespace STEMotion {

class Velocity final : BaseQuantity {
    f64 velocity;
    Metric metric;

public:
    Velocity(std::string name, f64 velocity, Metric metric);
    void to_metric(Metric metric) override;
    [[nodiscard]] f64 display() const override;
    [[nodiscard]] std::string unit() const override;
private:
    static f64 to_mks(f64 velocity, Metric metric);
};

} // STEMotion

#endif //VELOCITY_H
