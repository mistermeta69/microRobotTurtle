	/* A demonstration program
	   Will go around the perimeter of an empty maze once
	   while dropping a trail. Another way to do example 1
	   Version 1.1
	   Written by T.B.             Nov. 21/1994
	*/


	#include "ROBOT.H"       /*Robot header file, contains code to operate*/

	START_PROGRAM                      /*program execution begins here*/

	LOAD("MAZEDEMO")                   /*get the maze file from disk*/

	SPEED(5)                           /*set the speed to medium*/

	OPEN_HATCH                         /*drop a trail of crumbs*/

	FOR(4)                             /*repeat 4 times*/
	    BEGIN
	    WHILE NOT BLOCKED                  /*go forward until blocked*/
		 F

         L                                  /*turn */
         END
     WAIT                               /*wait for key press*/
     END_PROGRAM
