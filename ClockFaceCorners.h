#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceCorners : public ClockFace {
public:
    explicit ClockFaceCorners(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
