#include "DCC.h"
#include "DIAG.h"
#include "JMRIParser.h"

/* this code is here to test the waveforwe generator and reveal the issues involved in programming track operations.
 *  
 *  It tests the Waveform genartor and demonstrates how a DCC  API function can be simply written  
 *  to transmit and receive DCC data on the programming track.
 *  
 *  Important... DCCWaveform.h contains hardware specific confioguration settings 
 *  that you will need to check.  
 *  
 *  Notes: the waveform generator sends reset packets on progTrack when it has nothing better to do, this means that
 *  the decoder does not step out of service mode. (The main track sends idles).
 *  It also means that the API functions dont have to mess with reset packets. 
 *  
 */



const int cvnums[]={1,2,3,4,5,17,18,19,21,22,29};

void setup() {
  Serial.begin(115200);
  DCC::begin();
  
  DIAG(F("\n===== CVReader begin ==============================\n"));
  
  for (byte x=0;x<sizeof(cvnums)/sizeof(cvnums[0]);x++) {
    int value=DCC::readCV(cvnums[x]);
    DIAG(F("\nCV %d = %d  0x%x  %s\n"),cvnums[x],value,value, value>=0?" VERIFIED OK":"FAILED VERIFICATION"); 
  }
  DIAG(F("\n===== CVReader done ==============================\n"));  
  DIAG(F("\nReady for JMRI commands\n"));
}

void loop() {
  DCC::loop(); // required to keep locos running and check powwer
 
  // This line passes input on Serial to the JMRIparser 
  StringParser::loop(Serial, JMRIParser::parse);
}
  
