#pragma once
#include <avr/pgmspace.h>
#include "Staben.h"
#include "Zahlen.h"
#include "ZahlenKlein.h"
#ifdef EVENTDAY
#  include "Ereignisse.h"
#endif

inline void write1xyStab(word* matrix, char char1, byte posx, byte posy) {
    for (byte i = 0; i < 5; i++) {
        matrix[posy + i] |= pgm_read_byte_near(&(staben[char1 - 'A'][i])) << posx;
    }
}
inline void write2yStaben(word* matrix, char char1, char char2, byte posy) {
    write1xyStab(matrix, char1, 11, posy);
    write1xyStab(matrix, char2,  5, posy);
}
inline void write2Staben(word* matrix, char char1, char char2) {
    write2yStaben(matrix, char1, char2, 2);
}
inline void write4Staben(word* matrix, char char1, char char2, char char3, char char4) {
    write2yStaben(matrix, char1, char2, 0);
    write2yStaben(matrix, char3, char4, 5);
}
inline void write1xyDigit(word* matrix, byte number, byte posx, byte posy) {
    for (byte i = 0; i < 7; i++) {
        matrix[posy + i] |= pgm_read_byte_near(&(ziffern[number][i])) << posx;
    }
}
inline void write2yDigits(word* matrix, byte number, byte posy) {
    write1xyDigit(matrix, number / 10, 11, posy);
    write1xyDigit(matrix, number % 10,  5, posy);
}
inline void write4SmallDigits(word* matrix, byte firstNumber, byte secondNumber) {
    for (byte i = 0; i < 5; i++) {
        matrix[0 + i] |= pgm_read_byte_near(&(ziffernKlein[firstNumber  / 10][i])) << 12;
        matrix[0 + i] |= pgm_read_byte_near(&(ziffernKlein[firstNumber  % 10][i])) << 7;
        matrix[5 + i] |= pgm_read_byte_near(&(ziffernKlein[secondNumber / 10][i])) << 12;
        matrix[5 + i] |= pgm_read_byte_near(&(ziffernKlein[secondNumber % 10][i])) << 7;
    }
}
#ifdef EVENTDAY
inline void writeEventSymbol(word* matrix, char eventdaySymbol) {
    for (byte i = 0; i < 10; i++) {
        matrix[i] |= pgm_read_word_near(&(eventdayObject[eventdaySymbol].symbol[i])) << 5;
    }
}
#endif
