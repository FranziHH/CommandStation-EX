// Use Multiple Configs
// --------------------
// 1 - Arduino Mega #1
// 2 - Arduino Mega #2
// 3 - Arduino Mega #3
// 4 - ESP32
// --------------------
#define USE_CONFIG 4

// Arduino Mega #1
#if USE_CONFIG == 1
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  // SSD1306: 0.96'' OLED: 128,64
  // SSH1106: 1.13'' OLED: 132,64 
  #define OLED_DRIVER 132,64
  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE
  #define WIFI_HOSTNAME "dccex-1"
  #define WIFI_SSID "Your network name"
  #define WIFI_PASSWORD "Your network passwd"
  #define ENABLE_WIFI true
  #define WIFI_CHANNEL 1
  // FastClock serial1
  //#define SERIAL1_COMMANDS
  // HC-05 or HC-12 serial2 Bluetooth or Wireless Serial
  #define SERIAL2_COMMANDS
  // WiFi serial is connected on serial3 -> can't use for others
  //#define SERIAL3_COMMANDS
  //#define SERIAL4_COMMANDS
  //#define SERIAL5_COMMANDS
  //#define SERIAL6_COMMANDS
  // FastClock I2C
  #define FAST_CLOCK_I2C 0x55
  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE
#endif

// Arduino Mega #2
#if USE_CONFIG == 2
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  // SSD1306: 0.96'' OLED: 128,64
  // SSH1106: 1.13'' OLED: 132,64 
  #define OLED_DRIVER 132,64
  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE
  #define WIFI_HOSTNAME "dccex-2"
  #define WIFI_SSID "Your network name"
  #define WIFI_PASSWORD "Your network passwd"
  #define ENABLE_WIFI true
  #define WIFI_CHANNEL 1
  // FastClock serial1
  //#define SERIAL1_COMMANDS
  // HC-05 or HC-12 serial2 Bluetooth or Wireless Serial
  #define SERIAL2_COMMANDS
  // WiFi serial is connected on serial3 -> can't use for others
  //#define SERIAL3_COMMANDS
  //#define SERIAL4_COMMANDS
  //#define SERIAL5_COMMANDS
  //#define SERIAL6_COMMANDS
  // FastClock I2C
  #define FAST_CLOCK_I2C 0x55
  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE
#endif

// Arduino Mega #3
#if USE_CONFIG == 3
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  // SSD1306: 0.96'' OLED: 128,64
  // SSH1106: 1.13'' OLED: 132,64 
  //#define OLED_DRIVER 132,64
  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE
  #define WIFI_HOSTNAME "dccex-3"
  #define WIFI_SSID "Your network name"
  #define WIFI_PASSWORD "Your network passwd"
  #define ENABLE_WIFI true
  #define WIFI_CHANNEL 1
  // FastClock serial1
  //#define SERIAL1_COMMANDS
  // HC-05 or HC-12 serial2 Bluetooth or Wireless Serial
  //#define SERIAL2_COMMANDS
  // WiFi serial is connected on serial3 -> can't use for others
  //#define SERIAL3_COMMANDS
  //#define SERIAL4_COMMANDS
  //#define SERIAL5_COMMANDS
  //#define SERIAL6_COMMANDS
  // FastClock I2C
  //#define FAST_CLOCK_I2C 0x55
  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE
#endif

// ESP32
#if USE_CONFIG == 4
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD

  // SSD1306: 0.96'' OLED: 128,64
  #define OLED_DRIVER 128,64

  // SSH1106: 1.13'' OLED: 132,64 
  // #define OLED_DRIVER 132,64

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE
  #define WIFI_HOSTNAME "dccex-esp32"
  #define WIFI_SSID "Your network name"
  #define WIFI_PASSWORD "Your network passwd"
  #define ENABLE_WIFI true
  #define WIFI_CHANNEL 1
  // FastClock serial1
  //#define SERIAL1_COMMANDS
  // HC-05 or HC-12 serial2 Bluetooth or Wireless Serial
  // #define SERIAL2_COMMANDS
  // WiFi serial is connected on serial3 -> can't use for others
  //#define SERIAL3_COMMANDS
  //#define SERIAL4_COMMANDS
  //#define SERIAL5_COMMANDS
  //#define SERIAL6_COMMANDS

  // https://dcc-ex.com/reference/hardware/bluetooth/esp32-bluetooth.html#gsc.tab=0
  // #define SERIAL_BT_COMMANDS
  
  // FastClock I2C
  #define FAST_CLOCK_I2C 0x55

  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE
#endif


// otherwise does fastclock nothing
#ifdef FAST_CLOCK_I2C
  #ifndef EXRAIL_ACTIVE
    #define EXRAIL_ACTIVE
  #endif
#endif