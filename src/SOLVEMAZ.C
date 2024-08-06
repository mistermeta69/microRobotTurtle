#include "\lang\c\robot\ROBOT.H"

/* A  program for robot testing */

/*returns a true if a pellet is anywhere around*/

/*
DEFINE(NEAR_PELLET)
  FOR(4)
    BEGIN
    R
    IF PELLET
       RETURN_TRUE
    END
  RETURN_FALSE
END_DEFINE

DEFINE(TURN_AROUND)
 R
 R
END_DEFINE
*/

START_PROGRAM

LOAD("MAZE4")
SPEED(10)

OPEN_HATCH
CLOSE_HATCH
F
WAIT

WHILE NOT PELLET
    BEGIN
    R               /*RIGHT*/
     IF BLOCKED
      BEGIN
      L             /*FORWARD*/
      IF BLOCKED
         BEGIN
         L          /*LEFT*/
         IF BLOCKED
            L       /*BACK*/
         END
      END
    IF PELLET
       BEGIN
       F
       TAKE
       STOP
       END
    F
    END

WAIT

END_PROGRAM
