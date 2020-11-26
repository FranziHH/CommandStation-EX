////////////////////////////////////////////////////////////////////////////////////
//  © 2020, Chris Harlow. All rights reserved.
//
//  This file is a demonstattion of setting up a DCC-EX
// Command station with optional support for direct connection of WiThrottle devices
// such as "Engine Driver". If you contriol your layout through JMRI
// then DON'T connect throttles to this wifi, connect them to JMRI.
//
//  THE WIFI FEATURE IS NOT SUPPORTED ON ARDUINO DEVICES WITH ONLY 2KB RAM.
////////////////////////////////////////////////////////////////////////////////////

#include "config.h"
#include "DCCEX.h"
#include "DCCWaveform.h"

// Create a serial command parser for the USB connection, 
// This supports JMRI or manual diagnostics and commands
// to be issued from the USB serial console.
DCCEXParser serialParser;

#ifdef OLED_128x64
  bool lastMainPowerState;
  bool lastProgPowerState;
#endif

#ifdef THROTTLE_ENABLE
  DCCEXParser  throttleParser;
#endif

void setup()
{
  // The main sketch has responsibilities during setup()

  #ifdef EMERGENCY_BUTTON
    pinMode(EMERGENCY_BUTTON, INPUT_PULLUP);
  #endif
  
  // Responsibility 1: Start the usb connection for diagnostics
  // This is normally Serial but uses SerialUSB on a SAMD processor
  Serial.begin(115200);
  DIAG(F("DCC++ EX v%S"),F(VERSION));
   
  CONDITIONAL_LCD_START {
    // This block is ignored if LCD not in use 
    LCD(0,F("DCC++ EX v%S"),F(VERSION));
    #ifdef OLED_128x64
      LCD(1,F("---------------------"));
    #else
      LCD(1,F("Starting"));
    #endif
    } 

  // serial throttle
  #ifdef THROTTLE_ENABLE
    THROTTLE_SERIAL.begin(115200);
  #endif
  
#if ETHERNET_ON
  EthernetInterface::setup();
#endif // ETHERNET_ON

//  Start the WiFi interface on a MEGA, Uno cannot currently handle WiFi
#if WIFI_ON
  WifiInterface::setup(WIFI_SERIAL_LINK_SPEED, F(WIFI_SSID), F(WIFI_PASSWORD), F(WIFI_HOSTNAME), IP_PORT);
#endif // WIFI_ON

  // Responsibility 3: Start the DCC engine.
  // Note: this provides DCC with two motor drivers, main and prog, which handle the motor shield(s)
  // Standard supported devices have pre-configured macros but custome hardware installations require
  //  detailed pin mappings and may also require modified subclasses of the MotorDriver to implement specialist logic.

  // STANDARD_MOTOR_SHIELD, POLOLU_MOTOR_SHIELD, FIREBOX_MK1, FIREBOX_MK1S are pre defined in MotorShields.h

  // Optionally a Timer number (1..4) may be passed to DCC::begin to override the default Timer1 used for the
  // waveform generation.  e.g.  DCC::begin(STANDARD_MOTOR_SHIELD,2); to use timer 2

  DCC::begin(MOTOR_SHIELD_TYPE); 

  #ifdef OLED_128x64
    LCD(0, F("DCC++ EX  M:%s P:%s"), "off", "off");
  #else
    LCD(1,F("Ready"));
  #endif
}

void loop()
{
  // The main sketch has responsibilities during loop()

  // Hardware Button for Emergency OFF
  #ifdef EMERGENCY_BUTTON
    int buttonState = digitalRead(EMERGENCY_BUTTON); // check a 2nd time to be sure
    if (buttonState == LOW) {// check a 2nd time to be sure
      DCCWaveform::mainTrack.setPowerMode(POWERMODE::OFF);
      DCCWaveform::progTrack.setPowerMode(POWERMODE::OFF);
      do {  // routine to stay here till button released
        buttonState = digitalRead(EMERGENCY_BUTTON);
      } while (buttonState == LOW);
    }
  #endif
  
  #ifdef OLED_128x64
    bool currentMainPowerState = (DCCWaveform::mainTrack.getPowerMode()==POWERMODE::ON);
    bool currentProgPowerState = (DCCWaveform::progTrack.getPowerMode()==POWERMODE::ON);

    if ((lastMainPowerState != currentMainPowerState) || (lastProgPowerState != currentProgPowerState)) {
      LCD(0, F("DCC++ EX  M:%s P:%s"), currentMainPowerState ? "on " : "off", currentProgPowerState ? "on " : "off");
      lastMainPowerState = currentMainPowerState;
      lastProgPowerState = currentProgPowerState;
    }
  #endif
  
  // Responsibility 1: Handle DCC background processes
  //                   (loco reminders and power checks)
  DCC::loop();

  // Responsibility 2: handle any incoming commands on USB connection
  serialParser.loop(Serial);

  // Responsibility 2a: Optionally handle any incoming commands on serial connection -> throttle
  #ifdef THROTTLE_ENABLE
    throttleParser.loop(THROTTLE_SERIAL);
  #endif

// Responsibility 3: Optionally handle any incoming WiFi traffic
#if WIFI_ON
  WifiInterface::loop();
#endif
#if ETHERNET_ON
  EthernetInterface::loop();
#endif

#ifndef OLED_128x64
  LCDDisplay::loop();  // ignored if LCD not in use 
#endif
  
// Optionally report any decrease in memory (will automatically trigger on first call)
#if ENABLE_FREE_MEM_WARNING
  static int ramLowWatermark = 32767; // replaced on first loop 

  int freeNow = freeMemory();
  if (freeNow < ramLowWatermark)
  {
    ramLowWatermark = freeNow;
    LCD(2,F("Free RAM=%5db"), ramLowWatermark);
  }
#endif
}
