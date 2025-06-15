//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef BASEMETRIC_H
#define BASEMETRIC_H

#include <string>
#include <utility>

#include "../utils/numsize.h"
#include "metrics.h"

namespace STEMotion {
    class BaseQuantity {
        std::string name;
    public:
        explicit BaseQuantity(std::string name) : name(std::move(name)) {}
        virtual ~BaseQuantity() = default;

        virtual void to_metric(Metric metric) = 0;
        [[nodiscard]] virtual f64 display() const = 0;
        [[nodiscard]] virtual const char* unit() const = 0;
        [[nodiscard]] const char* get_name() const { return name.c_str(); }
        [[nodiscard]] virtual const char** get_units() = 0;
        [[nodiscard]] virtual Metric from_unit_string(const char *unit) = 0;
    };
}


#endif //BASEMETRIC_H
