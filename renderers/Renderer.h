/**
 * Renders words on the clock.
 * Cannot be instantiated directly. Use language-specific implementations instead.
 */
#ifndef RENDERER_H
#define RENDERER_H

#include "Arduino.h"
#include "../Configuration.h"

class Renderer {
public:
    virtual void setMinutes(char hours, byte minutes, word matrix[16]) = 0;
    virtual void cleanWordsForAlarmSettingMode(word matrix[16]) = 0;

    void scrambleScreenBuffer(word matrix[16]);
    void clearScreenBuffer(word matrix[16]);
    void setAllScreenBuffer(word matrix[16]);
    void activateAlarmLed(word matrix[16]);
    void setCorners(byte minutes, boolean cw, word matrix[16]);
protected:
    Renderer();

    virtual void setHours(char hours, boolean glatt, word matrix[16]) = 0;
};

#endif
