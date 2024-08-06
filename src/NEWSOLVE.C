#include "ROBOT.H"
/* An alternate way to solve the maze, using subroutines */

/* Subroutines must be defined before they are used */
/* and are located above the start of the main program*/

/* check if a pellet is near, if yes, take it and stop */
DEFINE(CHECK_PELLET)
   IF PELLET
	 BEGIN
	 F
	 TAKE
	 WAIT
	 STOP
	 END
   ELSE
	  F
   END_DEFINE

/*try to turn right, return TRUE if you can,
  otherwise turn back, return FALSE*/
DEFINE(GO_RIGHT)
   R
   IF BLOCKED
	 BEGIN
	 L
	 RETURN_FALSE
	 END
   CALL(CHECK_PELLET)
   F
   RETURN_TRUE
   END_DEFINE

/*try to go straight, return TRUE if you can,
  otherwise  return FALSE*/
DEFINE(GO_FORWARD)
   IF BLOCKED
	 RETURN_FALSE
   CALL(CHECK_PELLET)
   F
   RETURN_TRUE
   END_DEFINE

/*try to turn left, return TRUE if you can,
  otherwise turn back, return FALSE*/

DEFINE(GO_LEFT)
   L
   IF BLOCKED
	 BEGIN
	 R
	 RETURN_FALSE
	 END
   CALL(CHECK_PELLET)
   F
   RETURN_TRUE
   END_DEFINE

/*turn 180 degrees*/

DEFINE(TURN_AROUND)
   R
   R
   F
   END_DEFINE

/*main program*/

START_PROGRAM

LOAD("MAZE5")
SPEED(10)

WHILE NOT PELLET
IF NOT TRUE(GO_RIGHT)		/*can we go right?*/
   IF NOT TRUE(GO_FORWARD)    /*can't so can we go forward?*/
	 IF NOT TRUE (GO_LEFT)   /*can't, so can we go left?*/
	    CALL(TURN_AROUND)    /*can't, so turn back*/
F
TAKE
WAIT
END_PROGRAM
