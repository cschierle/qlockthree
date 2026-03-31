#pragma once
#include "ClockFace.h"

class ClockFaceBrightness : public ClockFace {
public:
    explicit ClockFaceBrightness(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
