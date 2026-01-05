/**
 * Woerter_DE_SW
 * Definition der schwäbischen Woerter fuer die Zeitansage.
 * Die Woerter sind Bitmasken fuer die Matrix.
 *
 *   0 1 2 3 4 5 6 7 8 9 0
 * 0 S L I S C H S K U R Z
 * 1 D R E I V I E R T E L
 * 2 Z E H N H O D F Ü N F
 * 3 N A C H B I S T V O R
 * 4 H A L B U F Ü N F E R
 * 5 O I S E C H S E L F E
 * 6 Z W O I E A C H D E T
 * 7 D R E I E Z W Ö L F E
 * 8 Z E H N E U N E A L B
 * 9 S I E B N E V I E R E
 */
#ifndef WOERTER_DE_SW_H
#define WOERTER_DE_SW_H

/**
 * Definition der Woerter
 */
#define DE_VOR         matrix[3] |= 0b0000000011100000
#define DE_NACH        matrix[3] |= 0b1111000000000000
#define DE_SISCH       matrix[0] |= 0b1011110000000000
#define DE_BIS         matrix[3] |= 0b0000111000000000
#define DE_KURZ        matrix[0] |= 0b0000000111100000

#define DE_DREIVIERTEL matrix[1] |= 0b1111111111100000
#define DE_VIERTEL     matrix[1] |= 0b0000111111100000
#define DE_ZEHN        matrix[2] |= 0b1111000000000000
#define DE_HOD         matrix[2] |= 0b0000111000000000
#define DE_FUENF       matrix[2] |= 0b0000000111100000
#define DE_HALB        matrix[4] |= 0b1111000000000000


#define DE_H_FUENFE      matrix[4] |= 0b0000011111000000
#define DE_H_OISE        matrix[5] |= 0b1111000000000000
#define DE_H_SECHSE      matrix[5] |= 0b0011111100000000
#define DE_H_ELFE        matrix[5] |= 0b0000000111100000
#define DE_H_ZWOIE       matrix[6] |= 0b1111100000000000
#define DE_H_ACHDE       matrix[6] |= 0b0000011111000000
#define DE_H_DREIE       matrix[7] |= 0b1111100000000000
#define DE_H_ZWOELFE     matrix[7] |= 0b0000011111100000
#define DE_H_ZEHNE       matrix[8] |= 0b1111100000000000
#define DE_H_NEUNE       matrix[8] |= 0b0001111100000000
#define DE_H_SIEBNE      matrix[9] |= 0b1111110000000000
#define DE_H_VIERE       matrix[9] |= 0b0000001111100000
#endif
