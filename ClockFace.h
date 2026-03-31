#pragma once
#include <Arduino.h>
#include "ClockContext.h"

class ClockFace {
public:
    explicit ClockFace(ClockContext* ctx) : _ctx(ctx) {}
    virtual ~ClockFace() {}
    virtual void writeToMatrix(word* matrix) = 0;
    virtual void onMinutePlus() {}
    virtual void onHourPlus() {}
    virtual void onEnter() {}
protected:
    ClockContext* _ctx;
};
