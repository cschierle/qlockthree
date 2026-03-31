#include "ClockFaceCountdown.h"

#ifdef COUNTDOWN
void ClockFaceCountdown::writeToMatrix(word* matrix) {
    if (*_ctx->countdown >= 60) {
        write4SmallDigits(matrix, *_ctx->countdown / 60, *_ctx->countdown % 60);
        _ctx->ledDriver->setPixelInScreenBuffer(10, 1, matrix);
        _ctx->ledDriver->setPixelInScreenBuffer(10, 3, matrix);
    } else if (*_ctx->countdown >= 0) {
        write2yDigits(matrix, *_ctx->countdown, 1);
    } else if (*_ctx->countdown > -COUNTDOWN_BLINK_DURATION) {
        if (*_ctx->countdown % 2) {
            writeEventSymbol(matrix, *_ctx->eventdaySymbol);
        }
    } else {
        *_ctx->mode = STD_MODE_NORMAL;
        *_ctx->lastMode = *_ctx->mode;
    }
}
#endif
