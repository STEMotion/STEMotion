//
// Created by mdgaziur001 on 4/1/25.
//

#pragma once

#include "BaseQuantity.h"

namespace STEMotion {

    class Mass final : public BaseQuantity {
        f64 mass;
        Metric metric;

        const char *units[4] = {"kg", "gm", "lb", "Invalid Metric"};

    public:
        Mass(std::string name, f64 mass, Metric metric);
        void to_metric(Metric metric) override;
        [[nodiscard]] f64 display() const override;
        [[nodiscard]] const char *unit() const override { return units[metric]; }

        [[nodiscard]] const char **get_units() override { return units; }

        [[nodiscard]] Metric from_unit_string(const char *unit) override;

    private:
        static f64 to_mks(f64 mass, Metric metric);
    };

} // namespace STEMotion
