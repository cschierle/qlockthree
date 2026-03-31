#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceMenuLabel : public ClockFace {
public:
    ClockFaceMenuLabel(ClockContext* ctx, char c1, char c2, char c3, char c4, byte nextMode)
        : ClockFace(ctx), _c1(c1), _c2(c2), _c3(c3), _c4(c4), _nextMode(nextMode) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
private:
    char _c1, _c2, _c3, _c4;
    byte _nextMode;
};
