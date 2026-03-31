#include "ClockFaceTimeSet.h"

void ClockFaceTimeSet::onMinutePlus() {
    _ctx->rtc->incMinutes();
    _ctx->rtc->setSeconds(0);
    _ctx->rtc->writeTime();
    _ctx->rtc->readTime();
    *_ctx->helperSeconds = 0;
}

void ClockFaceTimeSet::onHourPlus() {
    _ctx->rtc->incHours();
    _ctx->rtc->setSeconds(0);
    _ctx->rtc->writeTime();
    _ctx->rtc->readTime();
    *_ctx->helperSeconds = 0;
}
