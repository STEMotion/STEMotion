//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef PARAMETERSVIEW_H
#define PARAMETERSVIEW_H

#include <gtkmm.h>

#include "LibSTEMotion/SimulationParams.h"

namespace STEMotion {

    class ParametersView final : public Gtk::Box {
    public:
        explicit ParametersView(SimulationParams &params);

    private:
        SimulationParams &params;
        Gtk::Label label;
    };

} // namespace STEMotion

#endif // PARAMETERSVIEW_H
