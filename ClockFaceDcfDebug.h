#pragma once
#include "ClockFace.h"

class ClockFaceDcfDebug : public ClockFace {
public:
    explicit ClockFaceDcfDebug(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
