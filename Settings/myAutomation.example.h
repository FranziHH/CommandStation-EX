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

#ifdef MOTOR_SHIELD_DC
/* Set Default A:DCC Main, B:PROG */
AUTOMATION(500, "1: A Main, B Prog")
    SET_TRACK(A,MAIN)
    SET_TRACK(B,PROG)
    LCD (7,"A Main, B Prog")
DONE

/* Set A:PROG, B:DCC Main*/
AUTOMATION(501, "2: A Prog, B Main")
    SET_TRACK(A,PROG)
    SET_TRACK(B,MAIN)
    LCD (7,"A Prog, B Main")
DONE

/* Set A:DC, B:NONE */
AUTOMATION(502, "3: A DC (99)")
    SETLOCO(99)
    SET_TRACK(A,DC)
    SET_TRACK(B,NONE)
    LCD (7,"A DC (99), B None")
DONE 

/* Set A:NONE, B:DC */
AUTOMATION(503, "4: B DC (99)")
    SETLOCO(99)
    SET_TRACK(A,NONE)
    SET_TRACK(B,DC)
    LCD (7,"A None, B DC (99)")
DONE 
#endif

/* Set Default at Start A:DCC Main, B:PROG */
AUTOSTART SEQUENCE(100)
    SET_TRACK(A, MAIN)
    SET_TRACK(B, PROG)
    LCD (7,"A Main, B Prog")
    LCD (8, WIFI_HOSTNAME)
DONE
