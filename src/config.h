// pragma means to read this once, so if there is another config.h, they would not read it
#pragma once

// define means to find these words everywhere and replace it with this value
//  wifi
#define WIFI_SSID "ATT511 Tim"
#define WIFI_PASSWORD "ming8236299"

// openWeatherMap
#define OWM_API_KEY "19c5c93aa101cd089a27c8e57f89d9a4"
#define OWM_CITY "San Francisco"
#define OWM_COUNTRY "US"
#define WEATHER_REFRESH_MS 600000

// pins
#define EPD_CS 5
#define EPD_DC 17
#define EPD_RST 16
#define EPD_BUSY 4
#define EPD_CLK 18
#define EPD_MOSI 23

// rotary encoder
#define ENC_CLK 34
#define ENC_DT 35
#define ENC_SW 32

// pomodoro settings
#define POMODORO_DEFAULT_MINUTES 25
#define POMODORO_MIN_MINUTES 1
#define POMODORO_MAX_MINUTES 60
