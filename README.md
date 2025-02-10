# ! Fork From DCC++ EX
This is Forked From https://github.com/DCC-EX/CommandStation-EX

### Supported Motor Drivers
To make it easier to find the documentation:
Links to DCC-EX:
* [Supported Motor Drivers](https://dcc-ex.com/reference/hardware/motor-boards.html)
* [Current list of boards](https://dcc-ex.com/reference/hardware/motor-boards.html#current-list-of-boards)
* [TrackManager DC compatible boards](https://dcc-ex.com/reference/hardware/motor-boards.html#trackmanager-dc-compatible-boards)


### Work in Progress

Be Patient ...
I am in the process of setting up a NUCLEO-F446ZE. WiFi works with ESP8266 or ESP32. However, mDNS does not work with the ESP32. 
The IP address must be used there at the moment.
I have adjusted the power display on the screen. Due to the new functions in the TrackManager, the old display no longer worked properly.
I have also started to integrate various definitions for the config.h. But this still needs to be adjusted, it is not yet optimal.


### NUCLEO - F1446ZE

<img src="/Images/IMG_20250210_183817.jpg" height="400px" title="Nucleo Case with Arduino Holder">

I designed a case for Nucleo 144 boards.
The 3D printing files can be found on Thingiverse:  
https://www.thingiverse.com/thing:6944788  


### Information about NUCLEO Boards 

Affects the following boards - at the current time (February 2025) :
- NUCLEO F413ZH
- NUCLEO F429ZI
- NUCLEO F446ZE
- NUCLEO F412ZG
- NUCLEO F439ZI
- NUCLEO F4X9ZI

Serial ports 6 and 2 are available for use with external WiFi
from the source code:
```
#define SERIAL1 Serial6
#define SERIAL3 Serial2
```


### 2.4'' I2C OLED Display (128 x 64 LCD-Display SSD1309)
eg: https://de.aliexpress.com/item/1005006357395269.html  

The 2.4'' display works without changes with the SSD1306 settings
```
 // SSD1306: 0.96'' OLED: 128,64 OR SSD1309: 2.4'' 128,64
  #define OLED_DRIVER 128,64
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 
```

### All I2C OLED 128 x 64 Displays
The default setting for the number of lines is max:7
This display can show 8 lines.
This setting must be set for this:
```
  // max 8 Lines - default are 7
  #define MAX_CHARACTER_ROWS 9 
```

### My Changes Are:
* Display IP address and port on the same line
* Show Fastclock in readable form on the display
* new ExRail Commands
* new Power Presentation on Display
    for the new options (DC) in the track manager the display no longer works

<img src="/Images/IMG_20250202_113133.jpg" height="400px" title="2.4'' Display">
<img src="/Images/IMG_20250203_191242.jpg" height="400px" title="2.4'' Display - DC Track">

##### Configuration files moved to the “Settings” subfolder
To make the settings easier to find, the files config.h and myAutomation.h have been moved to the 'Settings' folder.

##### New ExRail Commands:
* GET_POWER(TRACK) - is Track powerd on/off 
* GET_TRACK(TRACK) - is Track available

##### Example of an emergency stop
define your button in config.h:
```
  // Hardware Button, used with EX-RAIL
  #define EMERGENCY_BUTTON 26 // Arduino Pin #2
```
put in myAutomation.h
```
/* Emergency Stop */
#ifdef EMERGENCY_BUTTON
AUTOSTART SEQUENCE(102)
    IF(EMERGENCY_BUTTON)
        AT(-EMERGENCY_BUTTON)
            SET_POWER(ALL,OFF)
    ENDIF
    FOLLOW(102)
DONE
#endif
```

##### Example of an toggle PowerButton eg Track A
define your button in config.h:
```
  // Hardware Button, used with EX-RAIL
  #define POWER_BUTTON_A 26 // Arduino Pin #2
```
put in myAutomation.h
```
/* Toggle Power Button A */
#ifdef POWER_BUTTON_A
AUTOSTART SEQUENCE(101)
    IF(POWER_BUTTON_A)
        AT(-POWER_BUTTON_A)
            // 'ALL' cannot be used here
            GET_POWER(A)
                SET_POWER(A,OFF)
            ELSE
                SET_POWER(A,ON)
            ENDIF
    ENDIF
    FOLLOW(101)
DONE
#endif
```

#### Display
New display format for the power display:
Due to the new functions in the Track Manager, the conventional power display no longer works.
If DC is selected, the display is no longer correct. 

##### Activate the new display: define in config.h
```
  // Alternative View Power
  #define LCD_ADVANCED_POWER
```

##### Display IP address and port on the same line: define in config.h
```
  // Shows IP and Port on Display in a single line
  #define PRINT_IP_PORT_SINGLE_LINE
```

##### Show Fastclock in readable form on the display: define in config.h
```
  // FastClock in HH:MM on Display
  #define FASTCLOCK_READABLE
```


# What is DCC-EX?
DCC-EX is a team of dedicated enthusiasts producing open source DCC & DC solutions for you to run your complete model railroad layout. Our easy to use, do-it-yourself, and free open source products run on off-the-shelf Arduino technology and are supported by numerous third party hardware and apps like JMRI, Engine Driver, wiThrottle, Rocrail and more. 

Currently, our products include the following:

* [EX-CommandStation](https://github.com/DCC-EX/CommandStation-EX/releases)
* [EX-WebThrottle](https://github.com/DCC-EX/exWebThrottle)
* [EX-Installer](https://github.com/DCC-EX/EX-Installer)
* [EX-MotoShield8874](https://dcc-ex.com/reference/hardware/motorboards/ex-motor-shield-8874.html#gsc.tab=0)
* [EX-DCCInspector](https://github.com/DCC-EX/DCCInspector-EX)
* [EX-Toolbox](https://github.com/DCC-EX/EX-Toolbox)
* [EX-Turntable](https://github.com/DCC-EX/EX-Turntable)
* [EX-IOExpander](https://github.com/DCC-EX/EX-IOExpander)
* [EX-FastClock](https://github.com/DCC-EX/EX-FastClock)
* [DCCEXProtocol](https://github.com/DCC-EX/DCCEXProtocol)

# What is DCC-EX?
DCC-EX is a team of dedicated enthusiasts producing open source DCC & DC solutions for you to run your complete model railroad layout. Our easy to use, do-it-yourself, and free open source products run on off-the-shelf Arduino technology and are supported by numerous third party hardware and apps like JMRI, Engine Driver, wiThrottle, Rocrail and more. 

Currently, our products include the following:

* [EX-CommandStation](https://github.com/DCC-EX/CommandStation-EX/releases)
* [EX-WebThrottle](https://github.com/DCC-EX/exWebThrottle)
* [EX-Installer](https://github.com/DCC-EX/EX-Installer)
* [EX-MotoShield8874](https://dcc-ex.com/reference/hardware/motorboards/ex-motor-shield-8874.html#gsc.tab=0)
* [EX-DCCInspector](https://github.com/DCC-EX/DCCInspector-EX)
* [EX-Toolbox](https://github.com/DCC-EX/EX-Toolbox)
* [EX-Turntable](https://github.com/DCC-EX/EX-Turntable)
* [EX-IOExpander](https://github.com/DCC-EX/EX-IOExpander)
* [EX-FastClock](https://github.com/DCC-EX/EX-FastClock)
* [DCCEXProtocol](https://github.com/DCC-EX/DCCEXProtocol)

Details of these projects can be found on [our web site](https://dcc-ex.com/).

# What’s in this Repository?

This repository, CommandStation-EX, contains a complete DCC-EX *EX-CommmandStation* sketch designed for compiling and uploading into an Arduino Uno, Mega, or Nano.

To utilize this sketch, you can use the following: 

1. (recommended for all levels of user) our [automated installer](https://github.com/DCC-EX/EX-Installer)
2. (intermediate) download the latest version from the [releases page](https://github.com/DCC-EX/CommandStation-EX/releases)
3. (advanced) use git clone on this repository 

Refer to [our web site](https://https://dcc-ex.com/ex-commandstation/get-started/index.html#/) for the hardware required for this project.

**We seriously recommend using the EX-Installer**, however if you choose not to use the installer... 

* Open the file ``CommandStation-EX.ino`` in the Arduino IDE or Visual Studio Code (VSC). Please do not rename the folder containing the sketch code, nor add any files in that folder. The Arduino IDE relies on the structure and name of the folder to properly display and compile the code. 
* Rename or copy ``config.example.h`` to ``config.h``. 
* You must edit ``config.h`` according to the help texts in ``config.h``.

# More information
You can learn more at the [DCC-EX website](https://dcc-ex.com/)

