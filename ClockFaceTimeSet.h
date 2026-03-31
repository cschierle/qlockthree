#pragma once
#include "ClockFace.h"

class ClockFaceTimeSet : public ClockFace {
public:
    explicit ClockFaceTimeSet(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
