#pragma once
#include <Arduino.h>

class Buzzer {
    public:
        Buzzer(uint8_t pin);
        
        void begin();
        void beep();
        void alarmDone();
        void alarmStart();

    private:
        uint8_t _pin;
        void tone(uint16_t frequency, uint32_t duration);
};