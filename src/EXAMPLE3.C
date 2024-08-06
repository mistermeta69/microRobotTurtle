#include "ROBOT.H"

/* Example 3, Tries to find the exit to the maze by looking for a pellet */
/* November 1994. */

START_PROGRAM

LOAD("MAZE5")
SPEED(10)

WHILE NOT BLOCKED	/*keep going til you find the pellet*/
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
    F
    END

F
TAKE			/*found it !*/

WAIT			/*pause for all to see */
END_PROGRAM
