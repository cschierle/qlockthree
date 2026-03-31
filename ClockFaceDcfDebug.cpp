#include "ClockFaceDcfDebug.h"

void ClockFaceDcfDebug::writeToMatrix(word* matrix) {
    *_ctx->needsUpdateFromRtc = true;
    _ctx->renderer->setCorners(_ctx->dcf77->getDcf77ErrorCorner(_ctx->settings->getDcfSignalIsInverted()), _ctx->settings->getRenderCornersCw(), matrix);
}
