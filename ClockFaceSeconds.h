#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceSeconds : public ClockFace {
public:
    explicit ClockFaceSeconds(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
