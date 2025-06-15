//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef PREDICTIONSVIEW_H
#define PREDICTIONSVIEW_H

#include <gtkmm.h>

namespace STEMotion {

    class PredictionsView final : public Gtk::Box {
    public:
        PredictionsView();

    private:
        Gtk::Label label;
    };

} // namespace STEMotion

#endif // PREDICTIONSVIEW_H
