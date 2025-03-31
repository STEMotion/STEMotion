//
// Created by mdgaziur001 on 3/31/25.
//

#ifndef SIMULATIONPARAMS_H
#define SIMULATIONPARAMS_H

#include <memory>
#include <string>
#include <unordered_map>

#include "metrics/BaseQuantity.h"

namespace STEMotion {

typedef std::unordered_map<std::string, std::unique_ptr<BaseQuantity>> ParamsList;

class SimulationParams {
    ParamsList params;

friend class SimulationPlugin;
public:
    SimulationParams() = default;
    void set_param(const std::string& name, std::unique_ptr<BaseQuantity> param);
    [[nodiscard]] BaseQuantity const& get_param(const std::string &name);
    [[nodiscard]] bool has_param(const std::string &name) const;
    [[nodiscard]] ParamsList const& get_params() const { return params; };
    void remove_param(const std::string &name);
};

}

#endif //SIMULATIONPARAMS_H
