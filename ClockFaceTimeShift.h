#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceTimeShift : public ClockFace {
public:
    explicit ClockFaceTimeShift(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
