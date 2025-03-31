//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <gtkmm.h>

#include "simulation_window/ParametersView.h"
#include "simulation_window/PredictionsView.h"
#include "simulation_window/SimulationView.h"

namespace STEMotion {

class SimulationWindow final : public Gtk::Window {
public:
    explicit SimulationWindow(std::string simulation_plugin_path);
    ~SimulationWindow() override;
private:
    SimulationPlugin *simulation_plugin;
    SimulationView *simulation_view;
    ParametersView *parameters_view;
    PredictionsView predictions_view;
    Gtk::Paned hpaned;
    Gtk::Paned vpaned;
};

} // STEMotion

#endif //SIMULATIONWINDOW_H
