//
// Created by mdgaziur001 on 3/29/25.
//

#include "SimulationWindow.h"

namespace STEMotion {
    SimulationWindow::SimulationWindow(std::string simulation_plugin_path) {
        simulation_plugin = new SimulationPlugin(simulation_plugin_path);
        simulation_view = new SimulationView(*simulation_plugin);
        parameters_view = new ParametersView(simulation_plugin->get_params());

        set_title("Simulation");
        set_default_size(1024, 768);

        vpaned.set_orientation(Gtk::Orientation::VERTICAL);

        vpaned.set_start_child(*simulation_view);
        vpaned.set_resize_start_child(true);
        vpaned.set_shrink_start_child(false);

        vpaned.set_end_child(predictions_view);
        vpaned.set_resize_end_child(true);
        vpaned.set_shrink_end_child(false);

        hpaned.set_start_child(vpaned);
        hpaned.set_resize_start_child(true);
        hpaned.set_shrink_start_child(false);

        hpaned.set_end_child(*parameters_view);
        hpaned.set_resize_end_child(true);
        hpaned.set_shrink_end_child(false);

        set_child(hpaned);
    }

    SimulationWindow::~SimulationWindow() {
        delete simulation_view;
        delete parameters_view;
        delete simulation_plugin;
    }
} // STEMotion