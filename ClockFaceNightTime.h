#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

class ClockFaceNightTime : public ClockFace {
public:
    ClockFaceNightTime(ClockContext* ctx, byte nightTimeStampIndex)
        : ClockFace(ctx), _nightTimeStampIndex(nightTimeStampIndex) {}
    void writeToMatrix(word* matrix) override;
    void onMinutePlus() override;
    void onHourPlus() override;
private:
    byte _nightTimeStampIndex;
    bool isOffTime() const { return (_nightTimeStampIndex % 2) == 0; }
};
