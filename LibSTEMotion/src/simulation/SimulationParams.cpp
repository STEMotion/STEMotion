//
// Created by mdgaziur001 on 3/31/25.
//

#include <LibSTEMotion/SimulationParams.h>

namespace STEMotion {
    void SimulationParams::set_metric_param(const char *name, BaseQuantity *param) {
        if (params.contains(name)) {
            params[name] = param;
            ;
        } else {
            params.insert({name, param});
        }
    }

    BaseQuantity const &SimulationParams::get_metric_param(const char *name) { return *params[name]; }

    bool SimulationParams::has_metric_param(const char *name) const { return params.contains(name); }

    void SimulationParams::remove_metric_param(const char *name) {
        if (params.contains(name)) {
            params.erase(name);
        }
    }

    void SimulationParams::set_time_param(const char *name, Time *param) {
        if (time_params.contains(name)) {
            time_params[name] = param;
        } else {
            time_params.insert({name, param});
        }
    }

    Time const &SimulationParams::get_time_param(const char *name) { return *time_params[name]; }

    bool SimulationParams::has_time_param(const char *name) const { return time_params.contains(name); }

    void SimulationParams::remove_time_param(const char *name) {
        if (time_params.contains(name)) {
            time_params.erase(name);
        }
    }

    void SimulationParams::set_angle_param(const char *name, Angle *param) {
        if (angle_params.contains(name)) {
            angle_params[name] = param;
        } else {
            angle_params.insert({name, param});
        }
    }

    Angle const &SimulationParams::get_angle_param(const char *name) { return *angle_params[name]; }

    bool SimulationParams::has_angle_param(const char *name) const { return angle_params.contains(name); }

    void SimulationParams::remove_angle_param(const char *name) {
        if (angle_params.contains(name)) {
            angle_params.erase(name);
        }
    }

} // namespace STEMotion
