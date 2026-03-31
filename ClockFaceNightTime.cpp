#include "ClockFaceNightTime.h"

void ClockFaceNightTime::writeToMatrix(word* matrix) {
    if (isOffTime()) {
        _ctx->ledDriver->setPixelInScreenBuffer(10, 7, matrix);
    }
    byte b_hour = _ctx->settings->getNightTimeStamp(_nightTimeStampIndex)->getHours();
    byte b_min  = _ctx->settings->getNightTimeStamp(_nightTimeStampIndex)->getMinutes();
    write4SmallDigits(matrix, b_hour, b_min);
    _ctx->ledDriver->setPixelInScreenBuffer(10, 1, matrix);
    _ctx->ledDriver->setPixelInScreenBuffer(10, 3, matrix);
}

void ClockFaceNightTime::onMinutePlus() {
    _ctx->settings->getNightTimeStamp(_nightTimeStampIndex)->incMinutes();
}

void ClockFaceNightTime::onHourPlus() {
    _ctx->settings->getNightTimeStamp(_nightTimeStampIndex)->incHours();
}
