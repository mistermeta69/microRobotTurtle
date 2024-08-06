	/* A demonstration program
        Will go around the perimeter of an empty maze once
        while dropping a trail.
        Version 1.0
        Written by T.B.             Nov. 21/1994
     */


     #include "ROBOT.H"       /*Robot header file, contains code to operate*/

     START_PROGRAM                      /*program execution begins here*/

	LOAD("MAZEDEMO")                   /*get the maze file from current dir*/

	SPEED(9)                           /*set the speed to medium*/

						/*drop a trail of crumbs*/

	WHILE NOT BLOCKED                  /*go forward until blocked*/
	   F

	L
	OPEN_HATCH                                  /*turn */
	SPEED(3)                           /*set the speed to medium*/

	WHILE NOT BLOCKED
	   F                               /*go forward 10 steps*/

	L
	SPEED(9)                           /*set the speed to medium*/
	CLOSE_HATCH

	WHILE NOT BLOCKED                  /*third side of maze*/
	   F

	L
	WHILE NOT BLOCKED
	   F

	WAIT                               /*wait for key press*/
	END_PROGRAM
