#include "ClockFaceNormal.h"

void ClockFaceNormal::writeToMatrix(word* matrix) {
    _ctx->renderer->setMinutes(_ctx->rtc->getHours() + _ctx->settings->getTimeShift(), _ctx->rtc->getMinutes(), _ctx->settings->getLanguage(), matrix);
    _ctx->renderer->setCorners(_ctx->rtc->getMinutes(), _ctx->settings->getRenderCornersCw(), matrix);
    if (_ctx->settings->getRandomizeColors()) {
        if (*_ctx->helperSeconds == 0) {
            _ctx->currentColor->R = random(0, 255);
            _ctx->currentColor->G = random(0, 255);
            _ctx->currentColor->B = random(0, 255);
        }
        _ctx->ledDriver->setColor(_ctx->currentColor->R, _ctx->currentColor->G, _ctx->currentColor->B);
    }
}
