#include "ROBOT.H"

/* Example 2, Looks for a pellet anywhere on the perimeter Nov 1994. */

/* Subroutines must precede main program */
/*subroutine returns a true if a pellet is anywhere around*/
DEFINE(NEAR_PELLET)
  FOR(4)
    BEGIN
    R
    IF PELLET
	  RETURN_TRUE
    END
  RETURN_FALSE
END_DEFINE

/* subroutine to turn robot 180 degrees */

DEFINE(TURN_AROUND)
 R
 R
END_DEFINE


START_PROGRAM

LOAD("MAZEDAN.C")

SPEED(3)

WHILE NOT PELLET
   BEGIN
   OPEN_HATCH
   IF BLOCKED
	 L             /*FORWARD*/

   IF PELLET
	L
F
END
WAIT
END_PROGRAM
