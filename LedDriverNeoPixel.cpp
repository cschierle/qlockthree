/**
 * LedDriverNeoPixel
 * Implementierung auf der Basis von WS2812B-Streifen wie sie die Adafruit-Neo-Pixel verwenden.
 *
 * Es lohnt sich in jedem Fall, den UeberGuide von Adafruit zu lesen:
 * https://learn.adafruit.com/adafruit-neopixel-uberguide/overview
 *
 * @mc       Arduino/RBBB
 * @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
 * @version  1.2
 * @created  5.1.2015
 *
 * Versionshistorie:
 * V 1.0:  - Erstellt.
 * V 1.1:  - Getter fuer Helligkeit nachgezogen.
 * V 1.2:  - Unterstuetzung fuer die alte Arduino-IDE (bis 1.0.6) entfernt.
 * V 1.3:  - LED_SKIP implementiert und somit dafür georgt das beliebig viele LEDs zwichsndurch ausgelassen werden können um unübliche Größen zu realisieren
 *
 * Verkabelung: Einspeisung oben links, dann schlangenfoermig runter,
 * dann Ecke unten links, oben links, oben rechts, unten rechts.
 *
 */
#include "LedDriverNeoPixel.h"
#include "Configuration.h"

// #define DEBUG
#include "Debug.h"

/*
 * hier wird die Anzahl von LEDS die zu skippen sind eingetragen
 * dabei gilt die Regel: jede X-te LED leuchtet
 */
#define LED_SKIP 2
#define NUM_PIXEL 100*LED_SKIP+14//114


/**
 * Initialisierung.
 *
 * @param data Pin, an dem die Data-Line haengt.
 */
LedDriverNeoPixel::LedDriverNeoPixel(byte dataPin) {
    _dataPin = dataPin;
    _strip = new Adafruit_NeoPixel(NUM_PIXEL, _dataPin, NEO_GRB + NEO_KHZ800);
    _strip->begin();
    setColor(250, 255, 200);
}

/**
 * init() wird im Hauptprogramm in init() aufgerufen.
 * Hier sollten die LED-Treiber in eine definierten
 * Ausgangszustand gebracht werden.
 */
void LedDriverNeoPixel::init() {
    setBrightness(50);
    clearData();
    wakeUp();
}

void LedDriverNeoPixel::printSignature() {
    Serial.println(F("NeoPixel - WS2812B"));
}

/**
 * Den Bildschirm-Puffer auf die LED-Matrix schreiben.
 *
 * @param onChange: TRUE, wenn es Aenderungen in dem Bildschirm-Puffer gab,
 *                  FALSE, wenn es ein Refresh-Aufruf war.
 */
void LedDriverNeoPixel::writeScreenBufferToMatrix(word matrix[16], boolean onChange) {
    if (onChange || _dirty) {
        _dirty = false;
        _strip->clear();

        uint32_t color = _strip->Color(_brightnessScaleColor(getRed()), _brightnessScaleColor(getGreen()), _brightnessScaleColor(getBlue()));

        for (byte y = 0; y < 10; y++) {
            for (byte x = 5; x < 16; x++) {
                word t = 1 << x;
                if ((matrix[y] & t) == t) {
                    _setPixel((15 - x)*LED_SKIP, y, color);
                }
            }
        }

        // wir muessen die Eck-LEDs umsetzten...
        if ((matrix[1] & 0b0000000000011111) == 0b0000000000011111) {
            _setPixel(NUM_PIXEL-4, color); // 1
        }
        if ((matrix[0] & 0b0000000000011111) == 0b0000000000011111) {
            _setPixel(NUM_PIXEL-3, color); // 2
        }
        if ((matrix[3] & 0b0000000000011111) == 0b0000000000011111) {
            _setPixel(NUM_PIXEL-2, color); // 3
        }
        if ((matrix[2] & 0b0000000000011111) == 0b0000000000011111) {
            _setPixel(NUM_PIXEL-1, color); // 4
        }

        _strip->show();
    }
}

/**
 * Die Helligkeit des Displays anpassen.
 *
 * @param brightnessInPercent Die Helligkeit.
 */
void LedDriverNeoPixel::setBrightness(byte brightnessInPercent) {
    if (brightnessInPercent != _brightnessInPercent) {
        _brightnessInPercent = brightnessInPercent;
        _dirty = true;
    }
}

/**
 * Die aktuelle Helligkeit bekommen.
 */
byte LedDriverNeoPixel::getBrightness() {
    return _brightnessInPercent;
}

/**
 * Anpassung der Groesse des Bildspeichers.
 *
 * @param linesToWrite Wieviel Zeilen aus dem Bildspeicher sollen
 *                     geschrieben werden?
 */
void LedDriverNeoPixel::setLinesToWrite(byte linesToWrite) {
}

/**
 * Das Display ausschalten.
 */
void LedDriverNeoPixel::shutDown() {
    _strip->clear();
    _strip->show();
}

/**
 * Das Display einschalten.
 */
void LedDriverNeoPixel::wakeUp() {
}

/**
 * Den Dateninhalt des LED-Treibers loeschen.
 */
void LedDriverNeoPixel::clearData() {
    _strip->clear();
    _strip->show();
}

/**
 * Einen X/Y-koordinierten Pixel in der Matrix setzen.
 */
void LedDriverNeoPixel::_setPixel(byte x, byte y, uint32_t c) {
    _setPixel(x + y *(10*LED_SKIP+1), c);
}

/**
 * Einen Pixel im Streifen setzten (die Eck-LEDs sind am Ende).
 */
void LedDriverNeoPixel::_setPixel(byte num, uint32_t c) {
    if (num < NUM_PIXEL-4) {
        if ((num / (10*LED_SKIP+1)) % 2 == 0) {
            _strip->setPixelColor(num, c);
        } else {
            _strip->setPixelColor(((num / (10*LED_SKIP+1)) * (10*LED_SKIP+1)) + 10*LED_SKIP - (num % (10*LED_SKIP+1)), c);
        }
    } else {
        switch (num) {
            case NUM_PIXEL-4:
                _strip->setPixelColor(NUM_PIXEL-3, c);
                break;
            case NUM_PIXEL-3:
                _strip->setPixelColor(NUM_PIXEL-2, c);
                break;
            case NUM_PIXEL-2:
                _strip->setPixelColor(NUM_PIXEL-1, c);
                break;
            case NUM_PIXEL-1:
                _strip->setPixelColor(NUM_PIXEL-4, c);
                break;
        }
    }
}

/**
 * Funktion fuer saubere 'Regenbogen'-Farben.
 * Kopiert aus den Adafruit-Beispielen (strand).
 */
uint32_t LedDriverNeoPixel::_wheel(byte wheelPos) {
    if (wheelPos < 85) {
        return _strip->Color(wheelPos * 3, 255 - wheelPos * 3, 0);
    } else if (wheelPos < 170) {
        wheelPos -= 85;
        return _strip->Color(255 - wheelPos * 3, 0, wheelPos * 3);
    } else {
        wheelPos -= 170;
        return _strip->Color(0, wheelPos * 3, 255 - wheelPos * 3);
    }
}

/**
 * Hilfsfunktion fuer das Skalieren der Farben.
 */
byte LedDriverNeoPixel::_brightnessScaleColor(byte colorPart) {
    return map(_brightnessInPercent, 0, 100, 0, colorPart);
}
