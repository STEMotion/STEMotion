//
// Created by mdgaziur001 on 3/31/25.
//

#pragma once

#include <memory>
#include <unordered_map>

#include "metrics/Angle.h"
#include "metrics/BaseQuantity.h"
#include "metrics/Time.h"

namespace STEMotion {

    typedef std::unordered_map<const char *, BaseQuantity *> MetricQuantityParamsList;
    typedef std::unordered_map<const char *, Time *> TimeParamsList;
    typedef std::unordered_map<const char *, Angle *> AngleParamsList;

    class SimulationParams {
        MetricQuantityParamsList params;
        TimeParamsList time_params;
        AngleParamsList angle_params;

        friend class SimulationPlugin;

    public:
        SimulationParams() = default;

        void set_metric_param(const char *name, BaseQuantity *param);
        [[nodiscard]] BaseQuantity const &get_metric_param(const char *name);
        [[nodiscard]] bool has_metric_param(const char *name) const;
        [[nodiscard]] MetricQuantityParamsList const &get_metric_params_list() const { return params; };
        void remove_metric_param(const char *name);

        void set_time_param(const char *name, Time *param);
        [[nodiscard]] Time const &get_time_param(const char *name);
        [[nodiscard]] bool has_time_param(const char *name) const;
        [[nodiscard]] TimeParamsList const &get_time_params_list() const { return time_params; };
        void remove_time_param(const char *name);

        void set_angle_param(const char *name, Angle *param);
        [[nodiscard]] Angle const &get_angle_param(const char *name);
        [[nodiscard]] bool has_angle_param(const char *name) const;
        [[nodiscard]] AngleParamsList const &get_angle_params_list() const { return angle_params; };
        void remove_angle_param(const char *name);
    };

} // namespace STEMotion
