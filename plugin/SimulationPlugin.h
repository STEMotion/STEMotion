//
// Created by mdgaziur001 on 3/31/25.
//

#ifndef SIMULATIONPLUGIN_H
#define SIMULATIONPLUGIN_H

#include <string>

#include <LibSTEMotion/SimulationParams.h>
#include <LibSTEMotion/renderer/DrawQueue.h>

namespace STEMotion {

// TODO: implement this properly
class SimulationPlugin {
    SimulationParams params;

public:
    explicit SimulationPlugin(std::string &path);
    DrawQueue* run(f64 deltaTime);
    SimulationParams& get_params();
    ~SimulationPlugin();
};

} // STEMotion

#endif //SIMULATIONPLUGIN_H
