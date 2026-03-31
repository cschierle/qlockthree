#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"
#include "Configuration.h"

#ifdef COUNTDOWN
class ClockFaceCountdown : public ClockFace {
public:
    explicit ClockFaceCountdown(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
#endif
