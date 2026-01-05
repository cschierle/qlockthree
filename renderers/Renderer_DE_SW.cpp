#include "Renderer_DE_SW.h"

Renderer_DE_SW::Renderer_DE_SW() {}

void Renderer_DE_SW::setMinutes(char hours, byte minutes, word matrix[16]) override {
    while (hours < 0) {
        hours += 24;
    }
    while (hours >= 24) {
        hours -= 24;
    }

    byte minutes_5 = minutes / 5;

    DE_SISCH;

    switch (minutes_5) {
        case 0:
            // glatte Stunde
            setHours(hours, true, matrix);
            break;
        case 1:
            // 5 nach
            DE_FUENF;
            DE_NACH;
            setHours(hours, false, matrix);
            break;
        case 2:
            // 10 nach
            DE_ZEHN;
            DE_NACH;
            setHours(hours, false, matrix);
            break;
        case 3:
            // viertel nach
            DE_VIERTEL;
            setHours(hours + 1, false, language, matrix);
            break;
        case 4:
            // 20 nach
            DE_ZEHN;
            DE_VOR;
            DE_HALB;
            setHours(hours + 1, false, language, matrix);
            break;
        case 5:
            // 5 vor halb
            DE_FUENF;
            DE_VOR;
            DE_HALB;
            setHours(hours + 1, false, language, matrix);
            break;
        case 6:
            // halb
            DE_HALB;
            setHours(hours + 1, false, language, matrix);
            break;
        case 7:
            // 5 nach halb
            DE_FUENF;
            DE_NACH;
            DE_HALB;
            setHours(hours + 1, false, language, matrix);
            break;
        case 8:
            // 20 vor
            DE_ZEHN;
            DE_NACH;
            DE_HALB;
            setHours(hours + 1, false, language, matrix);
            break;
        case 9:
            // viertel vor
            DE_DREIVIERTEL;
            setHours(hours + 1, false, language, matrix);
            break;
        case 10:
            // 10 vor
            DE_ZEHN;
            DE_VOR;
            setHours(hours + 1, false, language, matrix);
            break;
        case 11:
            // 5 vor
            DE_FUENF;
            DE_VOR;
            setHours(hours + 1, false, language, matrix);
            break;
    }
}

void Renderer_DE_SW::setHours(char hours, boolean glatt, word matrix[16]) override {
    switch (hours) {
        case 0:
        case 12:
        case 24:
            DE_H_ZWOELFE;
            break;
        case 1:
        case 13:
            DE_H_OISE;
            break;
        case 2:
        case 14:
            DE_H_ZWOIE;
            break;
        case 3:
        case 15:
            DE_H_DREIE;
            break;
        case 4:
        case 16:
            DE_H_VIERE;
            break;
        case 5:
        case 17:
            DE_H_FUENFE;
            break;
        case 6:
        case 18:
            DE_H_SECHSE;
            break;
        case 7:
        case 19:
            DE_H_SIEBNE;
            break;
        case 8:
        case 20:
            DE_H_ACHDE;
            break;
        case 9:
        case 21:
            DE_H_NEUNE;
            break;
        case 10:
        case 22:
            DE_H_ZEHNE;
            break;
        case 11:
        case 23:
            DE_H_ELFE;
            break;
    }
}

void Renderer_DE_SW::cleanWordsForAlarmSettingMode(word matrix[16]) override {
    matrix[0] &= 0b0100001111111111; // S'ISCH weg
}