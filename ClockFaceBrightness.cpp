#include "ClockFaceBrightness.h"

void ClockFaceBrightness::writeToMatrix(word* matrix) {
    *_ctx->brightnessToDisplay = map(_ctx->settings->getBrightness(), 1, 100, 0, 9);
    for (byte xb = 0; xb < *_ctx->brightnessToDisplay; xb++) {
        for (byte yb = 0; yb <= xb; yb++) {
            matrix[9 - yb] |= 1 << (14 - xb);
        }
    }
}

void ClockFaceBrightness::onMinutePlus() {
#ifdef AUTO_JUMP_TO_TIME
    *_ctx->jumpToTime = _ctx->settings->getJumpToTime();
#endif
    byte b = _ctx->settings->getBrightness();
    if ((!_ctx->settings->getUseLdr()) && (b < 100)) {
        b += 10;
        if (b > 100) b = 100;
        _ctx->settings->setBrightness(b);
        _ctx->settings->saveToEEPROM();
        _ctx->ledDriver->setBrightness(b);
    }
}

void ClockFaceBrightness::onHourPlus() {
#ifdef AUTO_JUMP_TO_TIME
    *_ctx->jumpToTime = _ctx->settings->getJumpToTime();
#endif
    int i = _ctx->settings->getBrightness();
    if ((!_ctx->settings->getUseLdr()) && (i > 1)) {
        i -= 10;
        if (i < 1) i = 1;
        _ctx->settings->setBrightness((byte)i);
        _ctx->settings->saveToEEPROM();
        _ctx->ledDriver->setBrightness((byte)i);
    }
}
