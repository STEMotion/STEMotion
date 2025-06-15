#include <gtkmm.h>
#include <iostream>

#include "gui/MainWindow.h"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.stemotion");
    return app->make_window_and_run<STEMotion::MainWindow>(argc, argv, *app);
}
