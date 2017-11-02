//Program: "Mouse Maze"

//This module "Checks for block or wall on the right"


//Author:   Jeffrey Roe
//Email:    jroe3@csu.fullerton.edu
//Course:   CPSC223c-01
//Semester: 2017 Spring
//Due date: 13 May 2017

//This module will check to see if there is a block or wall on the right of the mouse, if there is a block then the function will return a flag to the main.

//To compile this module (on a 64-bit computer) use the following command in the bash shell:
//    gcc -m64 -c -std=c99 -Wall -o blockonright.o blockonright.c

//Refer to the main function for instructions on linking.
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int thereisablokconright(int row, int col , int max, char theMaze[][max], char direction)
{

int result = 0;

switch (direction)
{
	case 'N': if(theMaze[row][col + 1] == 'X')
		  {
		  	result = 1;	
                  }
	          break;
	
        case 'E': if(theMaze[row + 1][col] == 'X')
		  {
			
						  	
			result = 1;	
                  }
	   	  break; 

	case 'S': if(theMaze[row][col - 1] == 'X')
		  {
		  	result = 1;	
                  }
	   	  break;
	
	case 'W': if(theMaze[row - 1][col] == 'X')
		  {
		  	result = 1;	
                  }
	   	  break;
}

return result;
	
}

