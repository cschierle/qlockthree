#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceEnableAlarm : public ClockFace {
public:
    explicit ClockFaceEnableAlarm(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
