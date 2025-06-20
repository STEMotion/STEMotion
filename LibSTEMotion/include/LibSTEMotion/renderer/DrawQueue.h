//
// Created by mdgaziur001 on 3/31/25.
//

#pragma once

#include <queue>

#include "Object.h"

namespace STEMotion {
    class DrawQueue {
        std::queue<Object> draw_queue;

    public:
        DrawQueue() = default;
        void enqueue_command(const Object &command);
        [[nodiscard]] size_t size() const { return draw_queue.size(); }
        [[nodiscard]] bool empty() const { return draw_queue.empty(); }
        [[nodiscard]] Object pop_command();
        ~DrawQueue() = default;
    };
} // namespace STEMotion
