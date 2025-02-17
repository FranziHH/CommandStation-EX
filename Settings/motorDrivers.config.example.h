/* Own MotorShield Definitions */

/* 
max Current Standard Arduino Motor Shield: 1500 mA
                           DIY MORE Shield: 2000 mA
*/

/* DIY MORE Standard Shield*/
#define DIYMORE_MOTOR_SHIELD F("DIYMORE_MOTOR_SHIELD"),               \
                            new MotorDriver(3, 12, UNUSED_PIN, 9, A0, 0.488, 2000, UNUSED_PIN), \
                            new MotorDriver(11, 13, UNUSED_PIN, 8, A1, 0.488, 2000, UNUSED_PIN)

/* DIY MORE Standard Shield - only one shield to test the converted MotorShield */
#define DIYMORE_MOTOR_SHIELD_ONLY_STACKED F("DIYMORE_MOTOR_SHIELD_ONLY_STACKED"),               \
                            new MotorDriver(2, 10, UNUSED_PIN, 7, A2, 0.488, 2000, UNUSED_PIN), \
                            new MotorDriver(5, 4, UNUSED_PIN, 6, A3, 0.488, 2000, UNUSED_PIN)

/* DIY MORE 2 Shields: 1 Standard, 1 converted */
#define DIYMORE_MOTOR_SHIELD_STACKED F("DIYMORE_MOTOR_SHIELD_STACKED"),               \
                            new MotorDriver(3, 12, UNUSED_PIN, 9, A0, 0.488, 2000, UNUSED_PIN), \
                            new MotorDriver(11, 13, UNUSED_PIN, 8, A1, 0.488, 2000, UNUSED_PIN), \
                            new MotorDriver(2, 10, UNUSED_PIN, 7, A2, 0.488, 2000, UNUSED_PIN), \
                            new MotorDriver(5, 4, UNUSED_PIN, 6, A3, 0.488, 2000, UNUSED_PIN)

/* EX8874 for USE DC / DC - second Brake converted to PB4
   EX 8874 based shield connected to a 3V3 system with 12-bit (4096) ADC */
#define EX8874_DC_SHIELD F("EX8874_DC_SHIELD"),               \
                            new MotorDriver( 3, 12, UNUSED_PIN, 9, A0, 1.27, 5000, A4), \
                            new MotorDriver(11, 13, UNUSED_PIN, PB4, A1, 1.27, 5000, A5)
