#include "ClockFaceJumpTimeout.h"

void ClockFaceJumpTimeout::writeToMatrix(word* matrix) {
    write2yDigits(matrix, _ctx->settings->getJumpToTime(), 3);
}

void ClockFaceJumpTimeout::onMinutePlus() {
    if (_ctx->settings->getJumpToTime() < 99) {
        _ctx->settings->setJumpToTime(_ctx->settings->getJumpToTime() + 1);
    }
}

void ClockFaceJumpTimeout::onHourPlus() {
    if (_ctx->settings->getJumpToTime() > 0) {
        _ctx->settings->setJumpToTime(_ctx->settings->getJumpToTime() - 1);
    }
}
