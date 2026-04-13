#pragma once
#include <Arduino.h>

class Encoder
{
public:
    Encoder(uint8_t clkPin, uint8_t dtPin, uint8_t swPin);

    void begin();
    void update();
    int getDelta();
    bool wasClicked();

private:
    uint8_t _clk, _dt, _sw;
    int _lastClk;                // checks the last state of the clk pin
    int _delta;                  // accumulated rotation since last getDelta() call fron above
    bool _clicked;               // has the button been clicked?
    unsigned long _lastDebounce; // unsigned long can store long numbers since we are dealing with milisec
};