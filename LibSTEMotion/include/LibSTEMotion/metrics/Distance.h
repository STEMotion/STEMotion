//
// Created by mdgaziur001 on 3/29/25.
//

#pragma once

#include <string>

#include "BaseQuantity.h"
#include "metrics.h"


namespace STEMotion {

    class Distance final : public BaseQuantity {
        f64 distance;
        Metric metric;

        const char *units[4] = {"m", "cm", "ft", "Invalid Metric"};

    public:
        Distance(std::string name, f64 distance, Metric metric);
        void to_metric(Metric metric) override;
        [[nodiscard]] f64 display() const override;

        [[nodiscard]] const char *unit() const override { return units[metric]; }

        [[nodiscard]] const char **get_units() override { return units; }

        [[nodiscard]] Metric from_unit_string(const char *unit) override;

    private:
        static f64 to_mks(f64 distance, Metric metric);
    };

} // namespace STEMotion
