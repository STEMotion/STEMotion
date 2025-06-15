//
// Created by mdgaziur001 on 3/31/25.
//

#include "SimulationPlugin.h"
#include "platform/PlatformInterface.h"

#include <glibmm/object.h>

#include "LibSTEMotion/metrics/Distance.h"
#include "LibSTEMotion/metrics/Energy.h"
#include "LibSTEMotion/metrics/Force.h"
#include "LibSTEMotion/metrics/Mass.h"
#include "LibSTEMotion/metrics/Velocity.h"

namespace STEMotion {
    SimulationPlugin::SimulationPlugin(std::string &path) {
        // TODO: remove after proper mechanism is implemented
        params.set_metric_param("d", std::make_unique<Distance>("d", 69.4, MKS).release());
        params.set_metric_param("m1", std::make_unique<Mass>("m1", 69.4, FPS).release());
        params.set_metric_param("m2", std::make_unique<Mass>("m2", 69.4, MKS).release());
        params.set_metric_param("f", std::make_unique<Force>("f", 69.4, MKS).release());
        params.set_metric_param("v", std::make_unique<Velocity>("v", 69.4, CGS).release());
        params.set_metric_param("w", std::make_unique<Energy>("d", 69.4, FPS).release());
    }

    SimulationResult SimulationPlugin::run(f64 deltaTime) {
        return {
                .draw_queue = DrawQueue(),
                .output = SimulationOutput(),
        };
    }

    SimulationParams &SimulationPlugin::get_params() { return params; }

    SimulationPlugin::~SimulationPlugin() {
        // TODO: call plugin's destructor
    }
} // namespace STEMotion
