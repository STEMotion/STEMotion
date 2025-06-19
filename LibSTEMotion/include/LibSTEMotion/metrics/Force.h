//
// Created by mdgaziur001 on 3/29/25.
//

#pragma once

#include <string>

#include "BaseQuantity.h"
#include "metrics.h"

namespace STEMotion {

    class Force final : public BaseQuantity {
        f64 force;
        Metric metric;

        const char *units[4] = {"N", "dyn", "lbf", "Invalid Metric"};

    public:
        Force(std::string name, f64 force, Metric metric);
        void to_metric(Metric metric) override;
        [[nodiscard]] f64 display() const override;
        [[nodiscard]] const char *unit() const override { return units[metric]; }

        [[nodiscard]] const char **get_units() override { return units; }

        [[nodiscard]] Metric from_unit_string(const char *unit) override;

    private:
        static f64 to_mks(f64 force, Metric metric);
    };

} // namespace STEMotion
