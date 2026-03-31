#pragma once
#include "ClockFaceNormal.h"

class ClockFaceTimeSet : public ClockFaceNormal {
public:
    explicit ClockFaceTimeSet(ClockContext* ctx) : ClockFaceNormal(ctx) {}
    void onMinutePlus() override;
    void onHourPlus() override;
};
