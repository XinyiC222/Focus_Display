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

void Weather::connectWifi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to WiFi");
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20)
    {
        delay(500);
        Serial.print("."); // print a dot so we can see progress
        attempts++;
    }
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\nWiFi connected!");
        Serial.println(WiFi.localIP()); // prints something like 192.168.1.5
    }
    else
    {
        Serial.println("\nWiFi connection failed!");
    }
}

bool Weather::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

// fetch() - the main function that calls the OpenWeatherMap API
bool Weather::fetch()
{
    if (!isConnected())
    {
        connectWifi(); // try reconnecting if we lost connection
        if (!isConnected())
            return false;
    }
    // Build the API URL
    String url = "http://api.openweathermap.org/data/2.5/weather?q=";
    url += OWM_CITY;
    url += ",";
    url += OWM_COUNTRY;
    url += "&appid=";
    url += OWM_API_KEY;
    url += "&units=metric"; // gives us celsius, change to imperial for fahrenheit

    // HTTPClient handles making the web request
    HTTPClient http;
    http.begin(url);

    int httpCode = http.GET();

    // HTTP 200 means success, anything else is an error
    if (httpCode != 200)
    {
        Serial.println("Weather fetch failed. HTTP code: " + String(httpCode));
        http.end();
        return false;
    }
    String payload = http.getString();
    http.end();

    // parsed data
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (error)
    {
        Serial.println("JSON parsing failed!");
        return false;
    }

    // extract data from the JSON
    _data.temperature = doc["main"]["temp"];
    _data.humidity = doc["main"]["humidity"];
    _data.description = doc["weather"][0]["description"].as<String>();
    _data.cityName = doc["name"].as<String>();
    _data.valid = true;

    Serial.println("Weather fetched successfully!");
    Serial.println("Temp: " + String(_data.temperature) + "°C");
    Serial.println("Description: " + _data.description);

    return true;
}

// getData() - returns the last fetched weather data
WeatherData Weather::getData()
{
    return _data;
}