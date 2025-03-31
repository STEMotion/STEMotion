//
// Created by mdgaziur001 on 3/29/25.
//

#include "PredictionsView.h"

namespace STEMotion {
    PredictionsView::PredictionsView() {
        set_size_request(-1, 128);
        set_hexpand(true);
        set_vexpand(true);

        set_halign(Gtk::Align::START);
        set_valign(Gtk::Align::BASELINE);

        label.set_text("Predictions");
        append(label);
    }
} // STEMotion