#include "ClockFaceColorful.h"

void ClockFaceColorful::writeToMatrix(word* matrix) {
    write2yStaben(matrix, 'C', 'O', 0);
    if (_ctx->settings->getRandomizeColors()) {
        _ctx->ledDriver->setColor(255, 255, 0);
        write2yStaben(matrix, 'O', 'N', 5);
    } else {
        _ctx->ledDriver->setColor(255, 255, 255);
        write2yStaben(matrix, 'O', 'F', 5);
    }
}

void ClockFaceColorful::onMinutePlus() {
    _ctx->settings->setRandomizeColors(!_ctx->settings->getRandomizeColors());
}

void ClockFaceColorful::onHourPlus() {
    _ctx->settings->setRandomizeColors(!_ctx->settings->getRandomizeColors());
}
