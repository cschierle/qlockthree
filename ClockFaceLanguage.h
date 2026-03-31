#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"
#include "Renderer.h"

class ClockFaceLanguage : public ClockFace {
public:
    explicit ClockFaceLanguage(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
};
