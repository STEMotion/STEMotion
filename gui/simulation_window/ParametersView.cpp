//
// Created by mdgaziur001 on 3/29/25.
//

#include "ParametersView.h"

// TODO: remove this
#include <iostream>

#include "LibSTEMotion/metrics/Distance.h"

namespace STEMotion {
    ParametersView::ParametersView(SimulationParams &params) : params(params) {
        set_size_request(150, -1);
        set_hexpand(true);
        set_vexpand(true);

        set_halign(Gtk::Align::START);
        set_valign(Gtk::Align::START);

        // TODO: process the params and create necessary fields.
        for (auto& param: params.get_params()) {
            std::cout << "Param: " << param.first << " Value: " << param.second->display() << " " << param.second->unit() << std::endl;
        }

        label.set_text("Parameters");
        append(label);
    }
} // STEMotion