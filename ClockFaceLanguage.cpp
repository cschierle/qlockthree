#include "ClockFaceLanguage.h"

void ClockFaceLanguage::writeToMatrix(word* matrix) {
    for (byte i = 0; i < 5; i++) {
        switch (_ctx->settings->getLanguage()) {
            case LANGUAGE_DE_DE:
                write2Staben(matrix, 'D', 'E');
                break;
            /*case LANGUAGE_DE_SW: ... (commented out in original) */
        }
    }
}

void ClockFaceLanguage::onMinutePlus() {
    _ctx->settings->setLanguage(_ctx->settings->getLanguage() + 1);
    if (_ctx->settings->getLanguage() > LANGUAGE_COUNT) {
        _ctx->settings->setLanguage(0);
    }
}

void ClockFaceLanguage::onHourPlus() {
    if (_ctx->settings->getLanguage() == 0) {
        _ctx->settings->setLanguage(LANGUAGE_COUNT);
    } else {
        _ctx->settings->setLanguage(_ctx->settings->getLanguage() - 1);
    }
}
