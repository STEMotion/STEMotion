//
// Created by mdgaziur001 on 3/31/25.
//

#ifndef DRAWQUEUE_H
#define DRAWQUEUE_H

#include <queue>

#include "objects/Object.h"

namespace STEMotion {
    class DrawQueue {
        std::queue<Object> draw_queue;

    public:
        DrawQueue() = default;
        void enqueue_command(Object command);
        [[nodiscard]] size_t size() const {
            return draw_queue.size();
        }
        [[nodiscard]] Object pop_command();
        ~DrawQueue() = default;
    };
}

#endif //DRAWQUEUE_H
