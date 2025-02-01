#ifdef POWER_BUTTON
/* Toggle Power Button */
/*
AUTOSTART SEQUENCE(101)
    IF(POWER_BUTTON)
        AT(-POWER_BUTTON)
            // 'ALL' cannot be used here
            GET_POWER(A)
                SET_POWER(A,OFF)
            ELSE
                SET_POWER(A,ON)
            ENDIF
    ENDIF
    FOLLOW(101)
DONE
*/

/* ---- OR ---- */

/* Emergency Stop */
AUTOSTART SEQUENCE(101)
    IF(POWER_BUTTON)
        AT(-POWER_BUTTON)
            SET_POWER(ALL,OFF)
    ENDIF
    FOLLOW(101)
DONE
#endif

// Reset Default back to DCC Main & PROG
AUTOMATION(500, "1: A Main, B Prog")
    SET_TRACK(A,MAIN)
    SET_TRACK(B,PROG)
    LCD (7,"A Main, B Prog")
DONE

AUTOMATION(501, "2: A Prog, B Main")
    SET_TRACK(A,PROG)
    SET_TRACK(B,MAIN)
    LCD (7,"A Prog, B Main")
DONE

// Set Channel A to DC
AUTOMATION(502, "3: A DC (99)")
    SETLOCO(99)
    SET_TRACK(A,DC)
    SET_TRACK(B,NONE)
    LCD (7,"A DC (99), B None")
DONE 

// Set Channel B to DC
AUTOMATION(503, "4: B DC (99)")
    SETLOCO(99)
    SET_TRACK(A,NONE)
    SET_TRACK(B,DC)
    LCD (7,"A None, B DC (99)")
DONE

AUTOSTART SEQUENCE(102)
    SET_TRACK(A, MAIN)
    SET_TRACK(B, PROG)
    LCD (7,"A Main, B Prog")
DONE
