#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceColorful : public ClockFace {
public:
    explicit ClockFaceColorful(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
