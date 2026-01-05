#include "Renderer.h"
#include "../Debug.h"

/**
 * Ein Zufallsmuster erzeugen (zum Testen der LEDs)
 */
void Renderer::scrambleScreenBuffer(word matrix[16]) {
    for (byte i = 0; i < 16; i++) {
        matrix[i] = random(65536);
    }
}

/**
 * Die Matrix loeschen (zum Stromsparen, DCF77-Empfang
 * verbessern etc.)
 */
void Renderer::clearScreenBuffer(word matrix[16]) {
    for (byte i = 0; i < 16; i++) {
        matrix[i] = 0;
    }
}

/**
 * Die Matrix komplett einschalten (zum Testen der LEDs)
 */
void Renderer::setAllScreenBuffer(word matrix[16]) {
    for (byte i = 0; i < 16; i++) {
        matrix[i] = 65535;
    }
}

/**
 * Setzt die vier Punkte in den Ecken, je nach minutes % 5 (Rest).
 *
 * @param ccw: TRUE -> clock wise -> im Uhrzeigersinn.
 *             FALSE -> counter clock wise -> gegen den Uhrzeigersinn.
 */
void Renderer::setCorners(byte minutes, boolean cw, word matrix[16]) {
    byte b_minutes = minutes % 5;
    for (byte i = 0; i < b_minutes; i++) {
        byte j;
    if (cw) {
          // j: 1, 0, 3, 2
          j = (1 - i + 4) % 4;
    } else {
          // j: 0, 1, 2, 3
          j = i;
        }
        #ifdef USE_INDIVIDUAL_CATHODES
            matrix[j] |= (0b0000000000010000 >> j);
        #else
            matrix[j] |= 0b0000000000011111;
        #endif
    }
}

/**
 * Schalte die Alarm-LED ein
 */
void Renderer::activateAlarmLed(word matrix[16]) {
    #ifdef USE_INDIVIDUAL_CATHODES
        matrix[4] |= 0b0000000000000001;
    #else
        matrix[4] |= 0b0000000000011111;
    #endif 
}
