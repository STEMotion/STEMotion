//
// Created by mdgaziur001 on 3/31/25.
//

#ifndef SIMULATIONPLUGIN_H
#define SIMULATIONPLUGIN_H

#include <string>

#include <LibSTEMotion/SimulationParams.h>
#include <LibSTEMotion/renderer/DrawQueue.h>

#include "LibSTEMotion/SimulationOutput.h"

namespace STEMotion {

struct SimulationResult {
    DrawQueue draw_queue;
    SimulationOutput output;
};

// TODO: implement this properly
class SimulationPlugin {
    SimulationParams params;

public:
    explicit SimulationPlugin(std::string &path);
    SimulationResult run(f64 deltaTime);
    SimulationParams& get_params();
    ~SimulationPlugin();
};

} // STEMotion

#endif //SIMULATIONPLUGIN_H
