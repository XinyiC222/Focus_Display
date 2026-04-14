#pragma once
#include <Arduino.h>

struct WeatherData
{
    float temperature;
    float humidity;
    String description;
    String cityName;
    bool valid;
};

class Weather
{
public:
    Weather();

    void begin();
    bool fetch();
    WeatherData getData();
    bool isConnected();

private:
    WeatherData _data;
    void connectWifi();
};