#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceDate : public ClockFace {
public:
    explicit ClockFaceDate(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
