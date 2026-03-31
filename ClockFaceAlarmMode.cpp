#include "ClockFaceAlarmMode.h"

void ClockFaceAlarmMode::writeToMatrix(word* matrix) {
    if (_ctx->alarm->getShowAlarmTimeTimer() == 0) {
        _ctx->renderer->setMinutes(_ctx->rtc->getHours() + _ctx->settings->getTimeShift(), _ctx->rtc->getMinutes(), _ctx->settings->getLanguage(), matrix);
        _ctx->renderer->setCorners(_ctx->rtc->getMinutes(), _ctx->settings->getRenderCornersCw(), matrix);
        _ctx->renderer->activateAlarmLed(matrix);
    } else {
        _ctx->renderer->setMinutes(_ctx->alarm->getHours() + _ctx->settings->getTimeShift(), _ctx->alarm->getMinutes(), _ctx->settings->getLanguage(), matrix);
        _ctx->renderer->setCorners(_ctx->alarm->getMinutes(), _ctx->settings->getRenderCornersCw(), matrix);
        _ctx->renderer->cleanWordsForAlarmSettingMode(_ctx->settings->getLanguage(), matrix);
        if (_ctx->alarm->getShowAlarmTimeTimer() % 2 == 0) {
            _ctx->renderer->activateAlarmLed(matrix);
        }
        _ctx->alarm->decShowAlarmTimeTimer();
    }
}

void ClockFaceAlarmMode::onMinutePlus() {
    _ctx->alarm->incMinutes();
    _ctx->alarm->setShowAlarmTimeTimer(10);
}

void ClockFaceAlarmMode::onHourPlus() {
    _ctx->alarm->incHours();
    _ctx->alarm->setShowAlarmTimeTimer(10);
}

void ClockFaceAlarmMode::onEnter() {
    _ctx->alarm->setShowAlarmTimeTimer(10);
}
