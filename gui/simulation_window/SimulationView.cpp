//
// Created by mdgaziur001 on 3/29/25.
//

#include "SimulationView.h"

#include "../../renderer/Renderer.h"

namespace STEMotion {
    SimulationView::SimulationView(SimulationPlugin &simulation_plugin)
        : plugin(simulation_plugin) {
        set_auto_render(false);
        set_size_request(512, 615);
    }

    bool SimulationView::on_render(const Glib::RefPtr<Gdk::GLContext> &gl_context) {
        auto time = get_frame_clock()->get_frame_time() / 1e6;
        if (lastTime == 0) {
            lastTime = time;
        }
        if (has_params_been_updated) {
            lastTime = time;
            has_params_been_updated = false;
        }
        auto deltaTime = time - lastTime;
        lastTime = time;

        DrawQueue *queue = plugin.run(deltaTime);
        render_draw_queue(queue, time);

        return true;
    }

    void SimulationView::on_realize() {
        GLArea::on_realize();

        auto clock = get_frame_clock();
        clock->signal_update().connect([this] {
           queue_render();
        });
        clock->begin_updating();
    }
}
