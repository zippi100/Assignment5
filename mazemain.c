//Program: "Mouse Maze"

//Program purpose:  This assignment is a mouse game that uses the tools we've used the entire semester to route a mouse in a maze to try to find a space with cheeze and having the mouse only being able to hug the wall to the right. We use the cursor positioning function to place the position of the mouse.
  
//Academic purpose: Using all tools of class to create a mouse maze game

//                  enrolled in CPSC223c need to study and understand.

//Author:	Jeffrey Roe
//Email:	jroe3@csu.fullerton.edu
//Course:	CPSC223C-01
//Assignment:	#5
//Due date:	May 13, 2017 before midnight
//Program title:Mouse Maze
//File name:	mazemain.c 
//Purpose:	This main function controls the calling of other functions.

//Program information:  This program contains four modules (separate files) as follows:/
//    Main function:                 mazemain.c
//    Search function:               blockonright.c
//    Change Posisition function:    turnleft.c 
//    Change Posisition function:    turnright.c 

//This program will have a mouse which is marked 'M' go through a maze with walls marked 'X' to try to find a cheese marked 'C'. The mouse will hug the right wall and travel throught the maze. If the mouse cannot reach the cheese. It will return to the begining of the maze and terminate the program. If the mouse indeed does get the cheese, the program will also terminate. In both cases, The program will output the total number of steps the mouse took in the maze and if the it was a success that the mouse had gotten the cheese.

//To compile this main module (on a 64-bit computer) use the following command in the bash shell:
//    gcc -m64 -c -std=c99 -Wall -o mazemain.o mazemain.c

//To link all the compiled modules use the following command in the bash shell:
//    gcc -m64 -std=c99 -o maze.out mazemain.o blockonright.o turnleft.o turnright.o

//To execute this program enter the following command in the bash shell:
//    ./maze.out

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

// main function
int main()
{

const int maxRow = 48; // max row size for array
const int maxCol = 160;// max column size for array
const int stepOut = 50; // position of where to output steps

char maze[maxRow][maxCol]; // array used to display mouse maze
int i; // x coordinates for mouse position
int j; // y coordinates fot mouse position
int density; // The thckness of walls in the mouse maze
int steps = 0; // steps the mouse takes in the maze
int millisec; // the number of millisecond the mouse takes before taking another step 

char mouse = 'M';     // The mouse
char direction = 'E'; // The direction in which the mouse is traveling
srand(time(NULL));    // used to get density of maze


// Output and Input - user input of density of maze and how many milliseconds the mouse will take before it takes its next step
printf("\n\nWelcome to the Mickey Mouse Maze by Jeffrey Roe");
printf("\n\nEnter percent of density: ");
scanf("%d", &density);
printf("Enter the mouse delay in milliseconds: ");
scanf("%d", &millisec);

// Time delay before the mouse enters the maze

printf("\nThank you. Here is the maze. Mickey will begin his travel in 10 seconds.");

sleep(0);

// clearing the screen for space for the maze
printf("\033[2J");
printf("\033[1;1H");



// Making the maze with outerwalls
for (i = 0; i < maxCol; i = i + 1)
{
	for(j = 0; j < maxRow; j = j + 1)
	{	
		if ((i == 0 && j == 23) || ((i == maxCol - 1 && j == 23)))
		{
			maze[j][i] = ' ';
		}
		else if (i == 0 || j == 0 || j == maxRow - 1 || i == maxCol - 1)
		{
			maze[j][i] = 'X';
		}
		else
		{
			maze[j][i] = ' ';
		}
	}
} 

// Making the maze with walls inside the maze
for (j = 1; j < maxRow - 1; j = j + 1)
{
	
	for (i = 1; i < maxCol - 1; i = i + 1)
	{
		int r = rand() % 100;
		if((i < 5 && j == 23) || ((i > 155 && i < maxCol) && j == 23))
		{			
		}
	        else if (r < density)
		{
			maze[j][i] = 'X'; 
		}
			
	} 
	
} 

// making the cheese and the end of the maze
maze[23][maxCol - 1] = 'C';


// Outputs the maze to the screen
for (j = 0; j < maxRow; j = j + 1)
{
	
	for (i = 0; i < maxCol; i = i + 1)
	{
		if (j == 23 && i == maxCol - 1)
		{
			printf("\x1b[32m%c\x1b[0m", maze[j][i]);
		}
		else
		{

			printf("%c", maze[j][i]);
		}

		
		
	
	} 
	printf("\n");
} 


printf("\n\nTotal steps: %-5d                  Conclusion:", steps);

// Giving the mouse at least two steps into the maze to ensure it actaully can enter the maze
printf("\033[1;1H");
printf("\033[23B");
printf("\x1b[31m%c\x1b[0m", mouse);
printf("\033[1D");
fflush(stdout);
sleep(10);
fflush(stdout);

fflush(stdout);

usleep(millisec * 1000);
printf("\x1b[34m%c\x1b[0m", mouse);
fflush(stdout);

// the first space of the maze
i = 1;
j = 23; 

usleep(millisec * 1000);
printf("\x1b[31m%c\x1b[0m", mouse);
printf("\033[1D");
steps++;
fflush(stdout);

printf("\x1b[34m%c\x1b[0m", mouse);

printf("\033[%dD", i);
printf("\033[%dB", stepOut - j);
printf("Total steps: %-5d                  Conclusion:", steps);
printf("\033[200D");
printf("\033[%dC", i + 1);
printf("\033[%dA", stepOut - j);


// Loop to check if the mouse is still in the maze and routes the mouse through the maze
while (i != 0 && i != maxCol - 1)
{
	printf("\033[1D");
	
	// checks to see if a block or wall is on the right
	if (thereisablokconright(j, i, maxCol, maze, direction) == 1)
	{
		
		switch(direction)
		{
			case 'N': if (maze[j - 1][i] == 'X')
				  {
					direction = turn90degreesleft(direction);
					
                                  }
				  else
				  {
					j = j - 1;
					
					printf("\033[1A");
					steps++;
					printf("\033[%dD", i);
					printf("\033[%dB", stepOut - j);
					printf("Total steps: %-5d                  Conclusion:", steps);
					printf("\033[200D");
					printf("\033[%dC", i);
					printf("\033[%dA", stepOut - j);

				  }
			break;
			case 'E': if (maze[j][i + 1] == 'X')
				  {
					direction = turn90degreesleft(direction);
					
                                  }
				  else
				  {
					i = i + 1;
					
					printf("\033[1C");
					steps++;
					printf("\033[%dD", i);
					printf("\033[%dB", stepOut - j);
					printf("Total steps: %-5d                  Conclusion:", steps);
					printf("\033[200D");
					printf("\033[%dC", i);
					printf("\033[%dA", stepOut - j);

				  }
			break;
			case 'S': if (maze[j + 1][i] == 'X')
				  {
					direction = turn90degreesleft(direction);
					
                                  }
				  else
				  {
					j = j + 1;
					
					printf("\033[1B");
					steps++;

					printf("\033[%dD", i);
					printf("\033[%dB", stepOut - j);
					printf("Total steps: %-5d                  Conclusion:", steps);
					printf("\033[200D");
					printf("\033[%dC", i);
					printf("\033[%dA", stepOut - j);

				  }
			break;
			case 'W': if (maze[j][i - 1] == 'X')
				  {
					direction = turn90degreesleft(direction);
					
                                  }
				  else
				  {
					i = i - 1;
					printf("\033[1D");
					steps++;
					printf("\033[%dD", i);
					printf("\033[%dB", stepOut - j);
					printf("Total steps: %-5d                  Conclusion:", steps);
					printf("\033[200D");
					printf("\033[%dC", i);
					printf("\033[%dA", stepOut - j);

				  }
			break;
		}
	}
	else 
	{
			
		direction = turn90degreesright(direction);
		steps++;
		
		switch(direction)
		{
			case 'N': j = j - 1;
				  
				  printf("\033[1A");
			break;
			case 'E': i = i + 1;
				  
				  printf("\033[1C");
			break;
			case 'S': j = j + 1;
				 
				  printf("\033[1B");
			break;
			case 'W': i = i - 1;
				  printf("\033[1D");
			break;
		}
		printf("\033[%dD", i);
		printf("\033[%dB", stepOut - j);
		printf("Total steps: %-5d                  Conclusion:", steps);
		printf("\033[200D");
		printf("\033[%dC", i);
		printf("\033[%dA", stepOut - j);

	}

// Output of mouse and shows its position when red and leaves trail in blue
usleep(millisec * 1000);
printf("\x1b[31m%c\x1b[0m", mouse);
printf("\033[1D");

fflush(stdout);

printf("\x1b[34m%c\x1b[0m", mouse);

	
}

printf("\033[200D");
printf("\033[27B");

// Output the total steps of mouse and if it made it to the cheese

if (i == maxCol - 1)
{
	
	printf("Total steps: %-5d                  Conclusion:Success", steps);
}
else
{
	printf("Total steps: %-5d                   Conclusion:Failure", steps);
}


printf("\033[200D");
printf("\033[40B");

return 0;
}
