#pragma once
#include "ClockFace.h"

class ClockFaceTest : public ClockFace {
public:
    explicit ClockFaceTest(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
