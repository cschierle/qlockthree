#include "ClockFaceEnableAlarm.h"

void ClockFaceEnableAlarm::writeToMatrix(word* matrix) {
    if (_ctx->settings->getEnableAlarm()) {
        write4Staben(matrix, 'A', 'L', 'E', 'N');
    } else {
        write4Staben(matrix, 'A', 'L', 'D', 'A');
    }
}

void ClockFaceEnableAlarm::onMinutePlus() {
    _ctx->settings->setEnableAlarm(!_ctx->settings->getEnableAlarm());
}

void ClockFaceEnableAlarm::onHourPlus() {
    _ctx->settings->setEnableAlarm(!_ctx->settings->getEnableAlarm());
}
