#pragma once
#include <Arduino.h>

struct WeatherData
{
    float temperature;
    float humidity;
    String descirption;
    String cityName;
    bool valid;
};

class Weather
{
public:
    Weather();

    void begin();
    void fetch();
    WeatherData getData();
    bool isConnected();

private:
    WeatherData _data;
    void connnectWifi();
};