#include "d:\lang\c\robot\ROBOT.H"

/* Program to solve complicated mazes, finds the pellet*/
/* T.B. November 1994 */

START_PROGRAM

LOAD("d:/lang/c/robot/MAZE5")
SPEED(10)

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
F
TAKE

END_PROGRAM
