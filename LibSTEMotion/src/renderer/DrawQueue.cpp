//
// Created by mdgaziur001 on 4/1/25.
//

#include <LibSTEMotion/renderer/DrawQueue.h>

namespace STEMotion {
    void DrawQueue::enqueue_command(const Object &command) { draw_queue.push(command); }

    Object DrawQueue::pop_command() {
        const Object command = draw_queue.front();
        draw_queue.pop();
        return command;
    }
} // namespace STEMotion
