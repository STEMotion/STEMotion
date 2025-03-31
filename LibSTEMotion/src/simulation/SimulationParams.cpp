//
// Created by mdgaziur001 on 3/31/25.
//

#include <LibSTEMotion/SimulationParams.h>

namespace STEMotion {
    void SimulationParams::set_param(const std::string& name, std::unique_ptr<BaseQuantity> value) {
        if (params.contains(name)) {
            params[name] = std::move(value);
        } else {
            params.insert({ name, std::move(value) });
        }
    }

    BaseQuantity const& SimulationParams::get_param(const std::string &name) {
        return *params[name];
    }

    bool SimulationParams::has_param(const std::string &name) const {
        return params.contains(name);
    }

    void SimulationParams::remove_param(const std::string &name) {
        if (params.contains(name)) {
            params.erase(name);
        }
    }

} // STEMotion
