/**********************************************************************

Config.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman
COPYRIGHT (c) 2020 Fred Decker

The configuration file for DCC++ EX Command Station

**********************************************************************/

/////////////////////////////////////////////////////////////////////////////////////
//
// Hardware Emergency Button: Power off Tracks
//
#define EMERGENCY_BUTTON A5    // Pin for Emergency OFF

/////////////////////////////////////////////////////////////////////////////////////
//  NOTE: Before connecting these boards and selecting one in this software
//        check the quick install guides!!! Some of these boards require a voltage
//        generating resitor on the current sense pin of the device. Failure to select
//        the correct resistor could damage the sense pin on your Arduino or destroy
//        the device.
//
// DEFINE MOTOR_SHIELD_TYPE BELOW ACCORDING TO THE FOLLOWING TABLE:
//
//  STANDARD_MOTOR_SHIELD : Arduino Motor shield Rev3 based on the L298 with 18V 2A per channel
//  POLOLU_MOTOR_SHIELD   : Pololu MC33926 Motor Driver (not recommended for prog track)
//  FUNDUMOTO_SHIELD      : Fundumoto Shield, no current sensing (not recommended, no short protection)
//  FIREBOX_MK1           : The Firebox MK1                    
//  FIREBOX_MK1S          : The Firebox MK1S    
//   |
//   +-----------------------v
//
#define MOTOR_SHIELD_TYPE STANDARD_MOTOR_SHIELD

/////////////////////////////////////////////////////////////////////////////////////
//
// The IP port to talk to a WIFI or Ethernet shield.
//
#define IP_PORT 3532                      //2560

/////////////////////////////////////////////////////////////////////////////////////
//
// NOTE: Only supported on Arduino Mega
// Set to false if you not even want it on the Arduino Mega
//
#define ENABLE_WIFI true

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE WiFi Parameters (only in effect if WIFI is on)
//
// If DONT_TOUCH_WIFI_CONF is set, all WIFI config will be done with
// the <+> commands and this sketch will not change anything over
// AT commands and the other WIFI_* defines below do not have any effect.
//#define DONT_TOUCH_WIFI_CONF
//
// WIFI_SSID is the network name IF you want to use your existing home network.
// Do NOT change this if you want to use the WiFi in Access Point (AP) mode. 
//
// If you do NOT set the WIFI_SSID, the WiFi chip will first try
// to connect to the previously configured network and if that fails
// fall back to Access Point mode. The SSID of the AP will be
// automatically set to DCCEX_*.
//
// Your SSID may not conain ``"'' (double quote, ASCII 0x22).
#define WIFI_SSID "Your network name"
//
// WIFI_PASSWORD is the network password for your home network or if
// you want to change the password from default AP mode password
// to the AP password you want. 
// Your password may not conain ``"'' (double quote, ASCII 0x22).
#define WIFI_PASSWORD "Your network passwd"
//
// WIFI_HOSTNAME: You probably don't need to change this
#define WIFI_HOSTNAME "dccex"
//
/////////////////////////////////////////////////////////////////////////////////////
//
// Wifi connect timeout in milliseconds. Default is 14000 (14 seconds). You only need
// to set this if you have an extremely slow Wifi router.
//
//#define WIFI_CONNECT_TIMEOUT 14000

/////////////////////////////////////////////////////////////////////////////////////
//
// Force to set Wifi serial manually
// disable search for port
//
#define WIFI_SERIAL Serial3

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE STATIC IP ADDRESS *OR* COMMENT OUT TO USE DHCP
//
//#define IP_ADDRESS { 192, 168, 1, 200 }

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE MAC ADDRESS ARRAY FOR ETHERNET COMMUNICATIONS INTERFACE
//
// Uncomment to use with Ethernet Shields
//
// NOTE: This is not used with ESP8266 WiFi modules.
// 
// Self Created:
// 0x6C, 0x77, 0xFD, 0xA2, 0x3F, 0x76
// 0xFF, 0xD4, 0xB0, 0x40, 0xE9, 0xA9
// 0x76, 0x77, 0x90, 0x53, 0xD4, 0xAF
// 0x9C, 0x74, 0x23, 0x63, 0x66, 0xB0
// 0x31, 0x39, 0xA6, 0xB6, 0x34, 0x0A
//
// #define MAC_ADDRESS {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF }
#define MAC_ADDRESS {  0x9C, 0x74, 0x23, 0x63, 0x66, 0xB0 }
#define ENABLE_ETHERNET true

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE SERIAL INTERFACE FOR HARDWARE SERIAL THROTTLE
//
#define THROTTLE_ENABLE
#define THROTTLE_SERIAL Serial1

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE LCD SCREEN USAGE BY THE BASE STATION
//
// Note: This feature requires an I2C enabled LCD screen using a PCF8574 based chipset.
//       or one using a Hitachi  HD44780.
//       OR an I2C Oled screen.
// To enable, uncomment one of the lines below

// define LCD_DRIVER for I2C LCD address 0x3f,16 cols, 2 rows
// #define LCD_DRIVER  0x3F,16,2

//OR define OLED_DRIVER width,height in pixels (address auto detected) 
// This will not work on a UNO due to memory constraints
// #define OLED_DRIVER 128,32

//OR define OLED_DRIVER width,height in pixels (address auto detected) 
// This will not work on a UNO due to memory constraints
// OLED aktivieren
#define OLED_DRIVER 128,64
#define OLED_I2C 0x3C   // 0x3C/0x3D -> 0x3D for original Adafruit products
#define OLED_128x64     // Set Display Size

// overwrite default display size
#define CONF_LCD_ROWS 8  // default 8
#define CONF_LCD_COLS 21 // default 16


/////////////////////////////////////////////////////////////////////////////////////
//
// Enable warning as memory gets depleted
#define ENABLE_FREE_MEM_WARNING false
