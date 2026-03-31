#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceLdrMode : public ClockFace {
public:
    explicit ClockFaceLdrMode(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
private:
    void toggleLdrMode();
};
