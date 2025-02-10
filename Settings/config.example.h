// Use Multiple Configs
// --------------------
// 1 - Arduino Mega #1
// 2 - Arduino Mega #2
// 3 - Arduino Mega #3
// 4 - ESP32 #1
// 5 - ESP32 #2
// 6 - ESP32 #3 with 2,4'' Display SSD1309
// 7 - Arduino Mega TEST #4
// 8 - NUCLEO-F446ZE
// --------------------
#define USE_CONFIG 8
// --------------------

// include wifi config
#include "config.wifi.h"

// include Own MotorShield Definitions
#include "motorDrivers.config.h"

// include Multiple Configs
#if USE_CONFIG == 1
  #include "001_ArduinoMega#1.config.h"
#endif
#if USE_CONFIG == 2
  #include "002_ArduinoMega#2.config.h"
#endif
#if USE_CONFIG == 3
  #include "003_ArduinoMega#3.config.h"
#endif
#if USE_CONFIG == 4
  #include "004_ESP32#1.config.h"
#endif
#if USE_CONFIG == 5
  #include "005_ESP32#2.config.h"
#endif
#if USE_CONFIG == 6
  #include "006_ESP32#3.config.h"
#endif
#if USE_CONFIG == 7
  #include "007_ArduinoMega#4.config.h"
#endif
#if USE_CONFIG == 8
  #include "008_NUCLEO-F446ZE#1.config.h"
#endif

// otherwise does fastclock nothing
#ifdef FAST_CLOCK_I2C
  #ifndef EXRAIL_ACTIVE
    #define EXRAIL_ACTIVE
  #endif
#endif
