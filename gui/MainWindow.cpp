//
// Created by mdgaziur001 on 3/29/25.
//

#include "MainWindow.h"

#include "SimulationWindow.h"

namespace STEMotion {
    MainWindow::MainWindow(Gtk::Application &app) : app(app) {
        set_title("STEMotion");
        set_default_size(800, 600);
        set_resizable(false);

        box.set_hexpand(true);
        box.set_vexpand(true);
        box.set_halign(Gtk::Align::CENTER);
        box.set_valign(Gtk::Align::CENTER);
        box.set_orientation(Gtk::Orientation::VERTICAL);

        name.set_text("<span size=\"25000\"><b>STEMotion</b></span>");
        name.set_halign(Gtk::Align::CENTER);
        name.set_valign(Gtk::Align::CENTER);
        name.set_hexpand(true);
        name.set_use_markup(true);
        name.set_use_markup(true);

        launch_simulation.set_label("Launch Simulation");
        launch_simulation.signal_clicked().connect([this] {
            // TODO: load with actual plugin path
            auto *simulation_window = new SimulationWindow("bogus/plugin/path");
            this->app.add_window(*simulation_window);
            simulation_window->show();
            this->hide();

            simulation_window->signal_hide().connect([this, simulation_window] {
                this->show();
                this->app.remove_window(*simulation_window);
                delete simulation_window;
            });
        });

        box.append(name);
        box.append(launch_simulation);

        set_child(box);
    }
} // STEMotion