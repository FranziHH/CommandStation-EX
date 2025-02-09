// Use Multiple Configs
// --------------------
// 1 - Arduino Mega #1
// 2 - Arduino Mega #2
// 3 - Arduino Mega #3
// 4 - ESP32 #1
// 5 - ESP32 #2
// 6 - ESP32 #1 with 2,4'' Display SSD1309
// 7 - Arduino Mega TEST #4
// 8 - NUCLEO-F446ZE
// --------------------
#define USE_CONFIG 8
// --------------------

// include wifi config
#include "config.wifi.h"

// include Own MotorShield Definitions
#include "motorDrivers.config.h"

// Arduino Mega #1
#if USE_CONFIG == 1
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  #define MOTOR_SHIELD_DC

  // SSD1306: 0.96'' OLED: 128,64
  // SSH1106: 1.13'' OLED: 132,64 
  #define OLED_DRIVER 132,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 

  // Alternative View Power
  #define LCD_ADVANCED_POWER

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE

  #define WIFI_HOSTNAME "dccex-1"
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

  // Hardware Button, used with EX-RAIL
  #define EMERGENCY_BUTTON 49 // Arduino Mega Pin #49
  // #define POWER_BUTTON_A 49 
#endif

// Arduino Mega #2
#if USE_CONFIG == 2
  #define IP_PORT 2560
  #define SCROLLMODE 1

  #define MOTOR_SHIELD_TYPE DIYMORE_MOTOR_SHIELD_STACKED
  #define MOTOR_SHIELD_DC

  // SSD1306: 0.96'' OLED: 128,64
  // SSH1106: 1.13'' OLED: 132,64 
  #define OLED_DRIVER 132,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 

  // Alternative View Power
  #define LCD_ADVANCED_POWER

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE

  #define WIFI_HOSTNAME "dccex-2"
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

  // Hardware Button, used with EX-RAIL
  #define EMERGENCY_BUTTON 49 // Arduino Mega Pin #49
  // #define POWER_BUTTON_A 49 
#endif

// Arduino Mega #3
#if USE_CONFIG == 3
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  #define MOTOR_SHIELD_DC

  // SSD1306: 0.96'' OLED: 128,64
  // SSH1106: 1.13'' OLED: 132,64 
  #define OLED_DRIVER 132,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 
  
  // Alternative View Power
  #define LCD_ADVANCED_POWER

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE

  #define WIFI_HOSTNAME "dccex-3"
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
  #define FAST_CLOCK_I2C 0x55

  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE

  // Hardware Button, used with EX-RAIL
  #define EMERGENCY_BUTTON 4 // Arduino Pin #4 -> Pin2 doesn't work
  // #define POWER_BUTTON_A 4
#endif

// ESP32
#if USE_CONFIG == 4
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  #define MOTOR_SHIELD_DC

  // SSD1306: 0.96'' OLED: 128,64
  // #define OLED_DRIVER 128,64

  // SSH1106: 1.13'' OLED: 132,64 
  #define OLED_DRIVER 132,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 
  
  // Alternative View Power
  #define LCD_ADVANCED_POWER

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE

  #define WIFI_HOSTNAME "dccex-esp32-1"
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

  // Hardware Button, used with EX-RAIL
  #define EMERGENCY_BUTTON 26 // Arduino Pin #2
  // #define POWER_BUTTON_A 26
#endif

// ESP32
#if USE_CONFIG == 5
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  #define MOTOR_SHIELD_DC

  // SSD1306: 0.96'' OLED: 128,64
  // #define OLED_DRIVER 128,64

  // SSH1106: 1.13'' OLED: 132,64 
  #define OLED_DRIVER 132,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 

  // Alternative View Power
  #define LCD_ADVANCED_POWER
    
  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE

  #define WIFI_HOSTNAME "dccex-esp32-2"
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

  // Hardware Button, used with EX-RAIL
  #define EMERGENCY_BUTTON 26 // Arduino Pin #2
  // #define POWER_BUTTON_A 26
#endif

// otherwise does fastclock nothing
#ifdef FAST_CLOCK_I2C
  #ifndef EXRAIL_ACTIVE
    #define EXRAIL_ACTIVE
  #endif
#endif

// ESP32
#if USE_CONFIG == 6
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  #define MOTOR_SHIELD_DC

  // SSD1306: 0.96'' OLED: 128,64 OR SSD1309: 2.4'' 128,64
  #define OLED_DRIVER 128,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 

  // SSH1106: 1.13'' OLED: 132,64 
  // #define OLED_DRIVER 132,64
  
  // Alternative View Power
  #define LCD_ADVANCED_POWER

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE
  
  #define WIFI_HOSTNAME "dccex-esp32-1"
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

  // Hardware Button, used with EX-RAIL
  #define EMERGENCY_BUTTON 26 // Arduino Pin #2
  // #define POWER_BUTTON_A 26
#endif

// Arduino Mega #4
#if USE_CONFIG == 7
  #define IP_PORT 2560
  #define SCROLLMODE 1
  #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  // #define MOTOR_SHIELD_TYPE EX8874_SHIELD
  #define MOTOR_SHIELD_DC 2

  // SSD1306: 0.96'' OLED: 128,64 OR SSD1309: 2.4'' 128,64
  #define OLED_DRIVER 128,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 
  
  // Alternative View Power
  #define LCD_ADVANCED_POWER 0

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE

  #define WIFI_HOSTNAME "dccex-4"

  #define ENABLE_WIFI true
  #define WIFI_CHANNEL 1

  // #define ENABLE_ETHERNET true

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
  // #define FAST_CLOCK_I2C 0x55

  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE

  // Hardware Button, used with EX-RAIL
  // #define EMERGENCY_BUTTON 4 // Arduino Pin #4 -> Pin2 doesn't work
  // #define POWER_BUTTON_A 4
#endif

// NUCLEO-F446ZE
#if USE_CONFIG == 8
  #define IP_PORT 2560
  #define SCROLLMODE 1
  // #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
  #define MOTOR_SHIELD_TYPE EX8874_SHIELD
  #define MOTOR_SHIELD_DC 1

  // SSD1306: 0.96'' OLED: 128,64 OR SSD1309: 2.4'' 128,64
  #define OLED_DRIVER 128,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 
  
  // Alternative View Power
  #define LCD_ADVANCED_POWER 0

  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE

  #define WIFI_HOSTNAME "dccex-nucleo"

  #define ENABLE_WIFI true
  #define WIFI_CHANNEL 1

  // #define ENABLE_ETHERNET true

  // FastClock serial1
  //#define SERIAL1_COMMANDS
  // HC-05 or HC-12 serial2 Bluetooth or Wireless Serial
  //#define SERIAL2_COMMANDS
  // WiFi serial is connected on serial2 -> can't use for others
  //#define SERIAL3_COMMANDS
  //#define SERIAL4_COMMANDS
  //#define SERIAL5_COMMANDS
  //#define SERIAL6_COMMANDS

  // FastClock I2C
  #define FAST_CLOCK_I2C 0x55

  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE

  // Hardware Button, used with EX-RAIL
  // #define EMERGENCY_BUTTON 4 // Arduino Pin #4 -> Pin2 doesn't work
  // #define POWER_BUTTON_A 4
#endif

// otherwise does fastclock nothing
#ifdef FAST_CLOCK_I2C
  #ifndef EXRAIL_ACTIVE
    #define EXRAIL_ACTIVE
  #endif
#endif
