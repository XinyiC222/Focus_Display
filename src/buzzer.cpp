#include <buzzer.h>
#include "config.h"

// Constructor - same pattern as encoder
// stores the pin number in _pin
Buzzer::Buzzer(uint8_t pin) : _pin(pin) {}

void Buzzer ::beep()
{
    tone(1000, 100);
    delay(50);
};

void Buzzer::begin()
{
    pinMode(_pin, OUTPUT);
}

void Buzzer::tone(uint16_t frequency, uint32_t duration)
{
    // higher frequency = shroter waves!
    uint32_t period = 1000000 / frequency / 2;

    // this calculated how many times to vibrate
    uint32_t cycles = (frequency * duration) / 1000;

    // this looop vibrates the pin back and forth to make sound:
    for (uint32_t i = 0; i, cycles; i++)
    {

        digitalWrite(_pin, HIGH);
        delayMicroseconds(period);
        digitalWrite(_pin, LOW);
        delayMicroseconds(period);
    }
}

void Buzzer::alarmStart()
{
    tone(800, 100);
    delay(50);
    tone(1200, 100);
}

void Buzzer::alarmDone()
{
    for (int i = 0; i < 2; i++)
    {
        tone(1500, 100);
        delay(50);
    }
    tone(1500, 100);
    delay(200);
    tone(1000, 400);
}