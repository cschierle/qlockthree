#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceDcfInverted : public ClockFace {
public:
    explicit ClockFaceDcfInverted(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
