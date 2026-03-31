#include "ClockFaceMenuLabel.h"

void ClockFaceMenuLabel::writeToMatrix(word* matrix) {
    write4Staben(matrix, _c1, _c2, _c3, _c4);
}

void ClockFaceMenuLabel::onMinutePlus() {
    *_ctx->mode = _nextMode;
}

void ClockFaceMenuLabel::onHourPlus() {
    *_ctx->mode = _nextMode;
}
