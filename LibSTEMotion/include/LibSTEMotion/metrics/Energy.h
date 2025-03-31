//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef ENERGY_H
#define ENERGY_H
#include <string>

#include "BaseQuantity.h"
#include "metrics.h"

namespace STEMotion {

class Energy final : public BaseQuantity {
    f64 energy;
    Metric metric;

    const char *units[3] = { "J", "erg", "ft-pound" };
public:
    Energy(std::string name, f64 energy, Metric metric);
    void to_metric(Metric metric) override;
    [[nodiscard]] f64 display() const override;
    [[nodiscard]] std::string unit() const override {
        return units[metric];
    }

    [[nodiscard]] const char** get_units() override {
        return units;
    }
private:
    static f64 to_mks(f64 energy, Metric metric);
};

} // STEMotion

#endif //ENERGY_H
