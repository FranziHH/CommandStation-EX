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

/* Select Button A */
#ifdef SELECT_BUTTON_A
AUTOSTART SEQUENCE(112)
    IF(SELECT_BUTTON_A)
        AT(-SELECT_BUTTON_A)
            // 'ALL' cannot be used here
            IF_TRACK_MODE(A,MAIN)
                SET_TRACK(A,PROG)
                SET_TRACK(B,MAIN)
            ELSE
                IF_TRACK_MODE(A,PROG)
                    SETLOCO(99)
                    SET_TRACK(A,DC)
                    SET_TRACK(B,MAIN)
                ELSE 
                    //SETLOCO(99)
                    SET_TRACK(A,MAIN)
                    SET_TRACK(B,PROG)
                ENDIF
            ENDIF
    ENDIF
    FOLLOW(112)
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
#ifdef MOTOR_SHIELD_DC
/* Set Default A:DCC Main, B:PROG * /
AUTOMATION(500, "1: A Main, B Prog")
    SET_TRACK(A,MAIN)
    SET_TRACK(B,PROG)
DONE

/* Set A:PROG, B:DCC Main* /
AUTOMATION(501, "2: A Prog, B Main")
    SET_TRACK(A,PROG)
    SET_TRACK(B,MAIN)
DONE

/* Set A:DC, B:NONE * /
AUTOMATION(502, "3: A DC (99)")
    SETLOCO(99)
    SET_TRACK(A,DC)
    SET_TRACK(B,NONE)
DONE 

/* Set A:NONE, B:DC * /
AUTOMATION(503, "4: B DC (99)")
    SETLOCO(99)
    SET_TRACK(A,NONE)
    SET_TRACK(B,DC)
DONE 

/* Set Default at Start A:DCC Main, B:PROG * /
AUTOSTART SEQUENCE(100)
    SETLOCO(99)
    SET_TRACK(A, DC)
    SET_TRACK(B, MAIN)
DONE
#else
/* Set Default at Start A:DCC Main, B:PROG * /
AUTOSTART SEQUENCE(100)
    SET_TRACK(A, MAIN)
    SET_TRACK(B, PROG)
DONE
#endif
*/

AUTOSTART SEQUENCE(100)
    SETLOCO(99)
    SET_TRACK(A, DC)
    SET_TRACK(B, DC)