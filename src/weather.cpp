#include "weather.h"
#include "config.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

Weather::Weather()
{
    _data.valid = false;
}

void Weather::begin()
{
    connectWifi();
}
