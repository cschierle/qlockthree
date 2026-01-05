#ifndef RENDERER_DE_SW_H
#define RENDERER_DE_SW_H

#include "Renderer.h"

class Renderer_DE_SW: public Renderer {
    public:
        Renderer_DE_SW();
        void setMinutes(char hours, byte minutes, word matrix[16]);
        void cleanWordsForAlarmSettingMode(word matrix[16]);
    protected:
        void setHours(char hours, boolean glatt, word matrix[16]);
}

#endif