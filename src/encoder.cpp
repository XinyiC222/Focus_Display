#include "encoder.h"

Encoder::Encoder(uint8_t clkPin, uint8_t dtPin, uint8_t swPin)
    : _clk(clkPin), _dt(dtPin), _sw(swPin),
      _lastClk(HIGH), _delta(0), _clicked(false), _lastDebounce(0) {}

void Encoder::begin()
{
    pinMode(_clk, INPUT_PULLUP);
    pinMode(_dt, INPUT_PULLUP);
    pinMode(_sw, INPUT_PULLUP);
    _lastClk = digitalRead(_clk);
}

// It detects both rotation and button clicks
void Encoder::update()
{
    int currentClk = digitalRead(_clk);
    if (currentClk != _lastClk && currentClk == LOW)
    {
        if (digitalRead(_dt) != currentClk)
        {
            _delta++; // clockwise
        }
        else
        {
            _delta--; // counter-clockwise
        }
    }
    _lastClk = currentClk;

    // Button click with debouncing, prevents it from interpreting 1 click as multiples
    unsigned long now = millis();
    if (digitalRead(_sw) == LOW && (now - _lastDebounce) > 200)
    {
        _clicked = true;
        _lastDebounce = now;
    }
}

int Encoder::getDelta()
{
}
bool Encoder::wasClicked()
{
}