#pragma once
#include "Settings.h"
#include "Renderer.h"
#include "LedDriver.h"
#include "MyRTC.h"
#include "MyDCF77.h"
#include "Alarm.h"
#include "Configuration.h"
#include "ClockModes.h"

struct RgbColor {
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

struct ClockContext {
    Settings*  settings;
    Renderer*  renderer;
    LedDriver* ledDriver;
    MyRTC*     rtc;
    MyDCF77*   dcf77;
    Alarm*     alarm;
    byte*      mode;
    byte*      lastMode;
    volatile byte* helperSeconds;
    volatile boolean* needsUpdateFromRtc;
    byte*      x;
    RgbColor*  currentColor;
#ifdef AUTO_JUMP_TO_TIME
    byte*      jumpToTime;
#endif
#ifdef COUNTDOWN
    int*       countdown;
    char*      eventdaySymbol;
#endif
    byte*      brightnessToDisplay;
};
