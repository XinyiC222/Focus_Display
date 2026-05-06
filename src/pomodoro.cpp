#include "pomodoro.h"
#include "config.h"

Pomodoro::Pomodoro()
    : _state(PomodoroState::IDLE),
      _durationMinutes(POMODORO_DEFAULT_MINUTES),
      _startTime(0),
      _pausedTime(0),
      _elapsedTime(0),
      _justFinished(false) {}

void Pomodoro::begin()
{
    reset();
}

void Pomodoro::setDuration(int minutes)
{
    if (minutes >= POMODORO_MIN_MINUTES && minutes <= POMODORO_MAX_MINUTES)
    {
        _durationMinutes = minutes;
    }
}

int Pomodoro::getDuration()
{
    return _durationMinutes;
}

void Pomodoro::start()
{
    if (_state == PomodoroState::IDLE || _state == PomodoroState::PAUSED)
    {
        _state = PomodoroState::RUNNING;
        _startTime = millis();
    }
}

void Pomodoro::pause()
{
    if (_state == PomodoroState::RUNNING)
    {
        _state = PomodoroState::PAUSED;
    }
}
void Pomodoro::reset()
{
    _state = PomodoroState::IDLE;
    _durationMinutes = POMODORO_DEFAULT_MINUTES;
    _startTime = 0;
    _pausedTime = 0;
    _elapsedTime = 0;
    _justFinished = false;
}

void Pomodoro::update()
{

    if (_state != PomodoroState::RUNNING)
        return;

    _elapsedTime = millis() - _startTime;

    // converts durations from minutes to milli
    unsigned long totalMs = (unsigned long)_durationMinutes * 60 * 1000;

    if (_elapsedTime >= totalMs)
    {
        _state = PomodoroState::DONE;
        _justFinished = true;
        _elapsedTime = totalMs; // so we dont get negatives
    }
}

int Pomodoro::getMinutesLeft()
{
    unsigned long totalMs = (unsigned long)_durationMinutes * 60 * 1000;
    unsigned long remaingingMs = totalMs - _elapsedTime;
    // convert milli back to minutes
    return remaingingMs / 60000;
}

int Pomodoro::getSecondsLeft()
{
    unsigned long totalMs = (unsigned long)_durationMinutes * 60 * 1000;
    unsigned long remaingingMs = totalMs - _elapsedTime;
    // convert milli to sec
    return remaingingMs / 60000 * 1000;
}

PomodoroState Pomodoro::getState()
{
    return _state;
}

bool Pomodoro::justFinished()
{
    // same patterna s was Clicked() and get Delta()
    bool val = _justFinished;
    _justFinished = false;
    return val;
}