Robot Control Language                         Sept. 1994
Version 1.1                                    Rev01 Nov. 1994
	
	
Introduction 
	What it is:
	The robot control language is a small programming environment that 
	can be used to teach procedural programming. The programs control 
	the movement of a virtual robot through a user defined maze. 
	Robot and maze are displayed in two dimensions on any VGA screen.

What you need to run robot programs:
	The programs must be saved in a text file with the file 
	extension ".C", for example "assign1.c" is a valid file name.

	You need a Turbo C or C++ DOS version compiler to compile and run 
	the programs you write. Source code can be entered using any text 
	editor, but you can also use the Turbo C editor and compiler 
	integrated environment to enter code. You must use Turbo C to 
	compile, syntax check, and run programs. This environment is 
	a menu driven, text window system, that uses the mouse. On-line 
	help is available. 

	To use Turbo C, type "TC" from the DOS prompt.

	You also need the file ROBOT.H, included in this package, 
	which contains the code for the robot interpreter. Include 
	this file in all your programs, as described below.


Copyright
	This code and documentation are copyright and may be used only 
	if left unmodified. It should not be distributed, unless written 
	permission is obtained from the author.



Syntax & Command Summary

General Syntactic Rules:

	Words show below in capital letters are elements of the language 
	and must appear exactly as shown. All other words are either 
	descriptive or can be expanded to commands. 

	Words or commands enclosed in square braces "[" & "]" are optional 
	and may be omitted as desired. Three dots "..." means that 
	the previous word or command can be repeated as desired.

	All commands must be separated by at least one blank space, tab 
	or a carriage return. 

	The left parenthesis "(" must never be separated from the word 
	that includes it, for example 

		"SPEED(10)"     is valid 
		"SPEED( 10 )"   is valid 
		"SPEED (10)"    is not valid and will cause an error 

	Descriptive comments can be positioned anywhere in the program 
	except inside command words, and must always be enclosed by 
	the following characters:

	"/*" and "*/"

	Example:         /* This is a valid comment */
			 / * this is not * /


Detailed Language Description

	program:
		function_def[s]
		START_PROGRAM
			statement [statement] [statement] ...
		END_PROGRAM

	function_def:
		DEFINE(function_name)      /*function_name can be any name*/
		statement                  /*without blanks in it*/ 
		[statement] 
		... 
		[return]                  /*terminate, return true or false*/
		END_DEFINE

	return:
		RETURN_TRUE or RETURN_FALSE   /*if omitted, function value*/
					      /*returned is unpredictable*/
					      /*and should not be tested for*/
					   
	statement can be:

		LOAD("fname")      /*loads robot environment from file fname*/

		BEGIN              /*create a block of statements to be            statement                       /*handled as one command*/
		[statement]
		...
		END

		WHILE cond         /*repeats statement while cond is true*/
			statement

		FOR(num)          /*repeats statement num times, 1<=num<=256*/
			statement  

		IF cond            /*does statement only if cond is true*/
			statement

		IF cond            /*same as above except that statement*/
			statement     /*after the ELSE is performed if cond*/
		ELSE                  /*is false*/
			statement

		STOP              /*immediately stops the program*/

		OPEN_HATCH        /*tells robot to leave a trail of*/
				  /* crumbs wherever it goes*/
		CLOSE_HATCH       /*tells robot not to drop crumbs*/

		R                 /*turns robot to the right - quarter turn*/

		L                 /*turns robot to the left - quarter turn*/

		F                 /*move robot one step forward*/

		WAIT              /*pauses robot movement until a key is*/
				  /*pressed on the keyboard*/
		TAKE              /*picks up a pellet or a bread crumb */
				  /*if the robot is on it, else does nothing*/
		SPEED(num)        /*set robot speed, 1 is slowest 1<=num<=10*/

		MAXSTEPS(num)     /*limits the number of steps that the*/
				  /*robot will take. Good for debugging loops*/
				  /*1<=num<=10000*/

		CALL(function_name)
				  /*executes the user subroutine or function named*/
				  /*this function must have been previously*/
				  /*defined using the DEFINE command*/
	cond can be:
		[NOT] BLOCKED     /*true or if path is blocked by wall*/

		[NOT] PELLET      /*true if pellet is directly in front*/

		[NOT] BREAD       /*true if crumb is directly in front*/

		[NOT] TRUE(function_name)  /*true if function returns TRUE*/



Program Creation and Editing

Use a text editor or the Turbo C development environment 
to create your source program. The first line of your program MUST be:

	#include "ROBOT.H" 

and must not be preceded by blanks. ROBOT.H must be in the current directory.

The maze files are text files that you can create, as described below. 
Some examples are included with this package. You can create 
your own maze files using a text editor if you follow the following format:

The maze format is an ASCII file, one line per maze row, and each row 
must contain 16 printable characters and must terminate with a 
carriage return.

Capital O's represent wall blocks and capital P's represent power pellets.
The robot's x,y coordinates follow the maze, and the robot's direction 
as an x and y increment (-1,0, or +1) follow.

Example:
```
OOOOOOOOOOOOOOOO
O              O
O              O
O              O
O              O
O     OOO O    O
O     O   O    O
P     O   O    P
O     O   O    O
O     O   OO   O
OOOOOOO        O
O              O
O     OOOOOOO  O
O              O
O              O
OOOOOOOOPOOOOOOO
 1
 1
 1
 0

```
Means position robot at upper left corner and make it point in the 
positive x direction (to the right).

Sample maze files included with this package are called MAZE1, MAZE2, etc...

There are also sample source code files called EXAMPLE1.C, EXAMPLE2.C, etc...

Try compiling and running these to see what they do.



