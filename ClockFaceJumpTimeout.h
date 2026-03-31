#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceJumpTimeout : public ClockFace {
public:
    explicit ClockFaceJumpTimeout(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
