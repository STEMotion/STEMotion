//
// Created by mdgaziur001 on 3/31/25.
//

#include "platform/PlatformInterface.h"
#include "SimulationPlugin.h"

#include <glibmm/object.h>

#include "LibSTEMotion/metrics/Distance.h"
#include "LibSTEMotion/metrics/Mass.h"
#include "LibSTEMotion/metrics/Energy.h"
#include "LibSTEMotion/metrics/Force.h"
#include "LibSTEMotion/metrics/Velocity.h"

namespace STEMotion {
    SimulationPlugin::SimulationPlugin(std::string &path) {
        // TODO: remove after proper mechanism is implemented
        params.params.insert({ "d", std::make_unique<Distance>("d", 69.4, MKS) });
        params.params.insert({ "m1", std::make_unique<Mass>("m1", 69.4, FPS) });
        params.params.insert({ "m2", std::make_unique<Mass>("m2", 69.4, MKS) });
        params.params.insert({ "f", std::make_unique<Force>("f", 69.4, MKS) });
        params.params.insert({ "v", std::make_unique<Velocity>("v", 69.4, CGS) });
        params.params.insert({ "w", std::make_unique<Energy>("d", 69.4, FPS) });
    }

    DrawQueue* SimulationPlugin::run(f64 deltaTime) {
        return {};
    }

    SimulationParams& SimulationPlugin::get_params() {
        return params;
    }

    SimulationPlugin::~SimulationPlugin() {
    }
} // STEMotion