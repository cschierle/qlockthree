#pragma once
#include "ClockFace.h"

class ClockFaceBlank : public ClockFace {
public:
    explicit ClockFaceBlank(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
