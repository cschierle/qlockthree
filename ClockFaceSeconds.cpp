#include "ClockFaceSeconds.h"

void ClockFaceSeconds::writeToMatrix(word* matrix) {
    write2yDigits(matrix, _ctx->rtc->getSeconds(), 1);
}
