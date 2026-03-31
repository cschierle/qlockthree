#pragma once
#include "ClockFace.h"

class ClockFaceAlarmMode : public ClockFace {
public:
    explicit ClockFaceAlarmMode(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
    void onEnter() override;
};
