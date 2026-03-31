#pragma once
#include "ClockFace.h"

class ClockFaceNormal : public ClockFace {
public:
    explicit ClockFaceNormal(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
