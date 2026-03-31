#include "ClockFaceCorners.h"

void ClockFaceCorners::writeToMatrix(word* matrix) {
    if (_ctx->settings->getRenderCornersCw()) {
        write2Staben(matrix, 'C', 'W');
    } else {
        write1xyStab(matrix, 'C', 8, 0);
        write2yStaben(matrix, 'C', 'W', 5);
    }
}

void ClockFaceCorners::onMinutePlus() {
    _ctx->settings->setRenderCornersCw(!_ctx->settings->getRenderCornersCw());
}

void ClockFaceCorners::onHourPlus() {
    _ctx->settings->setRenderCornersCw(!_ctx->settings->getRenderCornersCw());
}
