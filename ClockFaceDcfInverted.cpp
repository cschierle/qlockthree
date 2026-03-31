#include "ClockFaceDcfInverted.h"

void ClockFaceDcfInverted::writeToMatrix(word* matrix) {
    if (_ctx->settings->getDcfSignalIsInverted()) {
        write4Staben(matrix, 'R', 'S', 'I', 'N');
    } else {
        write4Staben(matrix, 'R', 'S', 'N', 'O');
    }
}

void ClockFaceDcfInverted::onMinutePlus() {
    _ctx->settings->setDcfSignalIsInverted(!_ctx->settings->getDcfSignalIsInverted());
}

void ClockFaceDcfInverted::onHourPlus() {
    _ctx->settings->setDcfSignalIsInverted(!_ctx->settings->getDcfSignalIsInverted());
}
