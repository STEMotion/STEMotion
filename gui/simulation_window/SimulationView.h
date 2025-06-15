//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <gtkmm.h>

#include <LibSTEMotion/SimulationParams.h>
#include "../../plugin/SimulationPlugin.h"

namespace STEMotion {

    class SimulationView final : public Gtk::GLArea {
    public:
        bool has_params_been_updated = false;

        explicit SimulationView(SimulationPlugin &simulation_plugin);

    private:
        SimulationPlugin &plugin;
        f64 lastTime = 0;

        bool on_render(const Glib::RefPtr<Gdk::GLContext> &) override;
        void on_realize() override;
    };

} // namespace STEMotion


#endif // SIMULATIONVIEW_H
