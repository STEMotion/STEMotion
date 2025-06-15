//
// Created by mdgaziur001 on 3/29/25.
//

#ifndef METRICS_H
#define METRICS_H

/*
 * Metrics in STEMotion is represented internally as MKS.
 * Only when displaying or showing output is the quantity
 * converted to desired mertic.
 */

#define UNIVERSAL_CONSTANT 6.67408e-11
#define GRAVITY 9.81

namespace STEMotion {
    enum Metric {
        MKS,
        CGS,
        FPS,
        InvalidMetric
    };
}

#endif //METRICS_H
