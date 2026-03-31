#include "ClockFaceTest.h"

void ClockFaceTest::writeToMatrix(word* matrix) {
    _ctx->renderer->setCorners(*_ctx->helperSeconds % 5, _ctx->settings->getRenderCornersCw(), matrix);
    if (_ctx->settings->getEnableAlarm()) {
        _ctx->renderer->activateAlarmLed(matrix);
    }
    for (byte i = 0; i < 11; i++) {
        _ctx->ledDriver->setPixelInScreenBuffer(*_ctx->x, i, matrix);
    }
    (*_ctx->x)++;
    if (*_ctx->x > 10) {
        *_ctx->x = 0;
    }
}
