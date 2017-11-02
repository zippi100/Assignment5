//Program: "Mouse Maze"

//This module "Changes the direction of the mouse to the left"


//Author:   Jeffrey Roe
//Email:    jroe3@csu.fullerton.edu
//Course:   CPSC223c-01
//Semester: 2017 Spring
//Due date: 13 May 2017

//This module will change the direction of the mouse to the left, so if north mouse turn west, west mouse turns south, south mouse turns east, and east mouse turn north

//To compile this module (on a 64-bit computer) use the following command in the bash shell:
//    gcc -m64 -c -std=c99 -Wall -o turnleft.o turnleft.c

//Refer to the main function for instructions on linking.
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char turn90degreesleft(char direction)
{

char newdirection;

switch(direction)
{	
	case 'N': newdirection = 'W';
		  break;
	case 'E': newdirection = 'N';
		  break;
	case 'S': newdirection = 'E';
		  break;
	case 'W': newdirection = 'S';
		  break;
}
return newdirection;
	  
}
