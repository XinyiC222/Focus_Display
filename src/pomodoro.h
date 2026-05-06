#pragma once
#include <Arduino.h>

// An enum is a list of named values, istead of tracking with 0, 1, 2, 3, you can track with the names
enum class PomodoroState
{
    IDLE,
    RUNNING,
    PAUSED,
    DONE
};

class Pomodoro
{
public:
    Pomodoro();
    void begin();
    void update();
    void start();
    void pause();
    void reset();
    void setDuration(int minutes);

    int getMinutesLeft();
    int getSecondsLeft();
    int getDuration();
    PomodoroState getState();
    bool justFinished();

private:
    PomodoroState _state;
    int _durationMinutes;
    unsigned long _startTime; // use insigned becuase time tracking can be very large
    unsigned long _pausedTime;
    unsigned long _elapsedTime;
    bool _justFinished;
};