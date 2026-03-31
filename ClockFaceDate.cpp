#include "ClockFaceDate.h"

void ClockFaceDate::writeToMatrix(word* matrix) {
#ifdef EVENTDAY
    int evSym = -1;
    for (byte i = 0; i < sizeof(eventdayObject)/sizeof(EventdayObject); i++) {
        if ( (pgm_read_byte_near(&eventdayObject[i].day) == _ctx->rtc->getDate()) &&
             (pgm_read_byte_near(&eventdayObject[i].month) == _ctx->rtc->getMonth()) ) {
            evSym = i;
            break;
        }
    }
    if (evSym != -1) {
        writeEventSymbol(matrix, evSym);
    } else
#endif
    {
        write4SmallDigits(matrix, _ctx->rtc->getDate(), _ctx->rtc->getMonth());
        _ctx->ledDriver->setPixelInScreenBuffer(10, 4, matrix);
        _ctx->ledDriver->setPixelInScreenBuffer(10, 9, matrix);
    }
}
