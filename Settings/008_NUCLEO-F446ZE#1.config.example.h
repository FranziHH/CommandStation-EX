// NUCLEO-F446ZE #1

#define IP_PORT 2560
#define SCROLLMODE 1
// #define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD
#define MOTOR_SHIELD_TYPE EX8874_SHIELD
#define MOTOR_SHIELD_DC

// SSD1306: 0.96'' OLED: 128,64 OR SSD1309: 2.4'' 128,64
#define OLED_DRIVER 128,64
// max 8 Lines - default are 7
#define MAX_CHARACTER_ROWS 9 

// Alternative View Power
#define LCD_ADVANCED_POWER

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
// GPIO pins on MCP23017 address 0x20 are accessed using pin numbers 164 to 179
#define EMERGENCY_BUTTON 168

#define POWER_BUTTON_A 164
#define POWER_BUTTON_B 165
#define POWER_BUTTON_C 166
#define POWER_BUTTON_D 167


#define SELECT_BUTTON_A 172
/*
#define SELECT_BUTTON_B 173
#define SELECT_BUTTON_C 174
#define SELECT_BUTTON_D 175
*/