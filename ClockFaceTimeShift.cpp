#include "ClockFaceTimeShift.h"

void ClockFaceTimeShift::writeToMatrix(word* matrix) {
    char c_TimeShift = _ctx->settings->getTimeShift();
    if (c_TimeShift < 0) {
        for (byte x = 0; x < 3; x++) {
            _ctx->ledDriver->setPixelInScreenBuffer(x, 1, matrix);
        }
    } else if (c_TimeShift > 0) {
        for (byte x = 0; x < 3; x++) {
            _ctx->ledDriver->setPixelInScreenBuffer(x, 1, matrix);
        }
        for (byte y = 0; y < 3; y++) {
            _ctx->ledDriver->setPixelInScreenBuffer(1, y, matrix);
        }
    }
    c_TimeShift = abs(c_TimeShift);
    write1xyDigit(matrix, c_TimeShift % 10, 5, 3);
    if (c_TimeShift > 9) {
        write1xyDigit(matrix, 1, 10, 3);
    }
}

void ClockFaceTimeShift::onMinutePlus() {
    if (_ctx->settings->getTimeShift() < 13) {
        _ctx->settings->setTimeShift(_ctx->settings->getTimeShift() + 1);
    }
}

void ClockFaceTimeShift::onHourPlus() {
    if (_ctx->settings->getTimeShift() > -13) {
        _ctx->settings->setTimeShift(_ctx->settings->getTimeShift() - 1);
    }
}
