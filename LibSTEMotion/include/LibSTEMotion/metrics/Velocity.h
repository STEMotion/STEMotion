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

        const char *units[4] = {"m/s", "cm/s", "ft/s", "Invalid Metric"};

    public:
        Velocity(std::string name, f64 velocity, Metric metric);
        void to_metric(Metric metric) override;
        [[nodiscard]] f64 display() const override;
        [[nodiscard]] const char *unit() const override { return units[metric]; }
        [[nodiscard]] const char **get_units() override { return units; }

        [[nodiscard]] Metric from_unit_string(const char *unit) override;

    private:
        static f64 to_mks(f64 velocity, Metric metric);
    };

} // namespace STEMotion

#endif // VELOCITY_H
