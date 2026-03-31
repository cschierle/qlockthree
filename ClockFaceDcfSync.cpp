#include "ClockFaceDcfSync.h"

#ifdef DCF77_SHOW_TIME_SINCE_LAST_SYNC
void ClockFaceDcfSync::writeToMatrix(word* matrix) {
    unsigned int ui_min = _ctx->dcf77->getDcf77LastSuccessSyncMinutes();
    write4SmallDigits(matrix, ui_min / 60, ui_min % 60);
    _ctx->ledDriver->setPixelInScreenBuffer(10, 1, matrix);
    _ctx->ledDriver->setPixelInScreenBuffer(10, 3, matrix);
}
#endif
