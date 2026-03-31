#pragma once
#include "ClockFace.h"
#include "MatrixWriter.h"

#ifdef DCF77_SHOW_TIME_SINCE_LAST_SYNC
class ClockFaceDcfSync : public ClockFace {
public:
    explicit ClockFaceDcfSync(ClockContext* ctx) : ClockFace(ctx) {}
    void writeToMatrix(word* matrix) override;
};
#endif
