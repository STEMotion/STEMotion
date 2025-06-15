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
        draw_queue.enqueue_command({
            .kind = ObjectKindCircle,
            .x0 = 0,
            .y0 = 0,
            .circle = {
                .radius = 5
            }
        });
        render_draw_queue(draw_queue, time);

        return true;
    }

    void SimulationView::on_realize() {
        GLArea::on_realize();

        const auto clock = get_frame_clock();
        clock->signal_update().connect([this] {
           queue_render();
        });
        clock->begin_updating();
    }
}
