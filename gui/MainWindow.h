//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>

#include "SimulationWindow.h"

namespace STEMotion {

class MainWindow final : public Gtk::Window {
public:
    explicit MainWindow(Gtk::Application &app);
private:
    Gtk::Application &app;
    Gtk::Box box;
    Gtk::Label name;
    Gtk::Button launch_simulation;
};

} // STEMotion

#endif //MAINWINDOW_H
