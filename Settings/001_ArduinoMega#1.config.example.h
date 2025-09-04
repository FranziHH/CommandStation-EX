// Arduino Mega #1

#define IP_PORT 2560
#define SCROLLMODE 1
#define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD

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
