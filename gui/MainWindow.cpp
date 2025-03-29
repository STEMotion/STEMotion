//
// Created by mdgaziur001 on 3/29/25.
//

#include "MainWindow.h"

namespace STEMotion {
    MainWindow::MainWindow() {
        set_title("STEMotion");
        set_default_size(800, 600);
        set_resizable(false);

        Gtk::Box box;
        box.set_hexpand(true);
        box.set_vexpand(true);
        box.set_halign(Gtk::Align::CENTER);
        box.set_valign(Gtk::Align::CENTER);

        Gtk::Label name;
        name.set_text("<span size=\"25000\"><b>STEMotion</b></span>");
        name.set_halign(Gtk::Align::CENTER);
        name.set_valign(Gtk::Align::CENTER);
        name.set_hexpand(true);
        name.set_use_markup(true);
        name.set_use_markup(true);

        box.append(name);
        set_child(box);
    }
} // STEMotion