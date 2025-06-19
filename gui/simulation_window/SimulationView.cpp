//
// Created by mdgaziur001 on 3/29/25.
//

#include "SimulationView.h"

#include <iostream>

#include "../../renderer/Renderer.h"

namespace STEMotion {
    SimulationView::SimulationView(SimulationPlugin &simulation_plugin) : plugin(simulation_plugin) {
        renderer = new Renderer();
        set_auto_render(false);
        set_size_request(512, 512);
    }
    SimulationView::~SimulationView() { delete renderer; }

    bool SimulationView::on_render(const Glib::RefPtr<Gdk::GLContext> &gl_context) {
        const auto time = get_frame_clock()->get_frame_time() / 1e6;
        if (lastTime == 0) {
            lastTime = time;
        }
        if (has_params_been_updated) {
            lastTime = time;
            has_params_been_updated = false;
        }
        const auto delta_time = time - lastTime;
        lastTime = time;

        auto [draw_queue, simulation_output] = plugin.run(delta_time);
        renderer->render_draw_queue(draw_queue, time, get_allocated_width(),
                                    get_allocated_height());

        return true;
    }

    void SimulationView::on_realize() {
        GLArea::on_realize();

        const auto clock = get_frame_clock();
        clock->signal_update().connect([this] { queue_render(); });
        clock->begin_updating();
    }
} // namespace STEMotion
