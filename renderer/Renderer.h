//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <LibSTEMotion/renderer/DrawQueue.h>
#include <LibSTEMotion/utils/numsize.h>

namespace STEMotion {

// TODO: implement this properly
void render_draw_queue(DrawQueue &draw_queue, const f64 time);

} // STEMotion

#endif //RENDERER_H
