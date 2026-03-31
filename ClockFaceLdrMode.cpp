#include "ClockFaceLdrMode.h"

void ClockFaceLdrMode::writeToMatrix(word* matrix) {
    if (_ctx->settings->getUseLdr()) {
        write1xyStab(matrix, 'A', 8, 2);
    } else {
        write1xyStab(matrix, 'M', 8, 2);
    }
}

void ClockFaceLdrMode::onMinutePlus() {
    _ctx->settings->setUseLdr(!_ctx->settings->getUseLdr());
    if (!_ctx->settings->getUseLdr()) {
        _ctx->ledDriver->setBrightness(50);
    }
}

void ClockFaceLdrMode::onHourPlus() {
    _ctx->settings->setUseLdr(!_ctx->settings->getUseLdr());
    if (!_ctx->settings->getUseLdr()) {
        _ctx->ledDriver->setBrightness(50);
    }
}
