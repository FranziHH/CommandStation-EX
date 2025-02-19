/* Toggle Power Button A */
#ifdef POWER_BUTTON_A
AUTOSTART SEQUENCE(111)
    IF(POWER_BUTTON_A)
        AT(-POWER_BUTTON_A)
            // 'ALL' cannot be used here
            IF_POWER(A)
                SET_POWER(A,OFF)
            ELSE
                SET_POWER(A,ON)
            ENDIF
    ENDIF
    FOLLOW(111)
DONE
#endif

/* Toggle Power Button B */
#ifdef POWER_BUTTON_B
AUTOSTART SEQUENCE(121)
    IF(POWER_BUTTON_B)
        AT(-POWER_BUTTON_B)
            // 'ALL' cannot be used here
            IF_POWER(B)
                SET_POWER(B,OFF)
            ELSE
                SET_POWER(B,ON)
            ENDIF
    ENDIF
    FOLLOW(121)
DONE
#endif

/* Toggle Power Button C */
#ifdef POWER_BUTTON_C
AUTOSTART SEQUENCE(131)
    IF(POWER_BUTTON_C)
        AT(-POWER_BUTTON_C)
            // 'ALL' cannot be used here
            IF_POWER(C)
                SET_POWER(C,OFF)
            ELSE
                SET_POWER(C,ON)
            ENDIF
    ENDIF
    FOLLOW(131)
DONE
#endif

/* Toggle Power Button D */
#ifdef POWER_BUTTON_D
AUTOSTART SEQUENCE(141)
    IF(POWER_BUTTON_D)
        AT(-POWER_BUTTON_D)
            // 'ALL' cannot be used here
            IF_POWER(D)
                SET_POWER(D,OFF)
            ELSE
                SET_POWER(D,ON)
            ENDIF
    ENDIF
    FOLLOW(141)
DONE
#endif

/* Select Button A - DCC */
#ifdef SELECT_BUTTON_A
AUTOSTART SEQUENCE(112)
    IF(SELECT_BUTTON_A)
        AT(-SELECT_BUTTON_A)
            // 'ALL' cannot be used here
            IF_TRACK_MODE(A,MAIN)
                IF_TRACK_MODE(B,PROG)
                    SET_TRACK(A,PROG)
                    SET_TRACK(B,MAIN)
                ELSE 
                    SET_TRACK(A,MAIN)
                    SET_TRACK(B,PROG)
                ENDIF 
            ELSE 
                IF_TRACK_MODE(A,DC)
                    IF_TRACK_MODE(B,DC)
                        SETLOCO(98)
                        SET_TRACK(A,DC)
                        SET_TRACK(B,MAIN)
                    ELSE 
                        IF_TRACK_MODE(B,MAIN)
                            SET_TRACK(A,MAIN)
                            SET_TRACK(B,MAIN)
                        ELSE
                            SETLOCO(98)
                            SET_TRACK(A,DC)
                            SETLOCO(99)
                            SET_TRACK(B,DC)
                        ENDIF
                    ENDIF 
                ELSE 
                    IF_TRACK_MODE(B,MAIN)
                        SET_TRACK(A,PROG)
                        SETLOCO(99)
                        SET_TRACK(B,DC)
                    ELSE 
                        SETLOCO(98)
                        SET_TRACK(A,DC)
                        SET_TRACK(B,PROG)
                    ENDIF 
                ENDIF
            ENDIF
    ENDIF
    FOLLOW(112)
DONE
#endif

/* Select Button B - DC */
#ifdef SELECT_BUTTON_B
AUTOSTART SEQUENCE(122)
    IF(SELECT_BUTTON_B)
        AT(-SELECT_BUTTON_B)
            // 'ALL' cannot be used here
            IF_TRACK_MODE(A,DC)
                IF_TRACK_MODE(B,DC)
                    SETLOCO(98)
                    SET_TRACK(A,DCX)
                    SETLOCO(99)
                    SET_TRACK(B,DC)
                ELSE 
                    SETLOCO(98)
                    SET_TRACK(A,DCX)
                    SETLOCO(99)
                    SET_TRACK(B,DCX)
                ENDIF 
            ELSE
                IF_TRACK_MODE(B,DC)
                    SETLOCO(98)
                    SET_TRACK(A,DC)
                    SETLOCO(99)
                    SET_TRACK(B,DCX)
                ELSE 
                    SETLOCO(98)
                    SET_TRACK(A,DC)
                    SETLOCO(99)
                    SET_TRACK(B,DC)
                ENDIF 
            ENDIF
    ENDIF
    FOLLOW(122)
DONE
#endif


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

/*
AUTOSTART SEQUENCE(100)
    SETLOCO(99)
    SET_TRACK(A, DC)
    SET_TRACK(B, DC)
DONE
*/

AUTOSTART SEQUENCE(100)
    SERIAL2("TEST on SERIAL 2\n")
DONE
