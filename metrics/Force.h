//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef FORCE_H
#define FORCE_H
#include <string>

#include "BaseQuantity.h"
#include "metrics.h"

namespace STEMotion {

class Force final : BaseQuantity {
    f64 force;
    Metric metric;

public:
    Force(std::string name, f64 force, Metric metric);
    void to_metric(Metric metric) override;
    [[nodiscard]] f64 display() const override;
    [[nodiscard]] std::string unit() const override;
private:
    static f64 to_mks(f64 force, Metric metric);
};

} // STEMotion

#endif //FORCE_H
