#!/bin/bash
#The statement above is the mandatory first line of all (Bash) script files.

#This is a script file formatted for use by the Bash shell.

#Author:   Jeffrey Roe
#Email:    jeffrey.t.roe@gmail.com
#Course:   CPSC223c-01
#Semester: 2017 Spring
#Due date: 13 May 2017

#Before execution this script file make sure it has "execute permission".  One way to do this is
#to enter the following command:
#          sudo chmod u+x maze.sh
#After permission has been given the permission will remain (until explicitly changed).

#To execute this file send the following command to Bash:
#         ./maze.sh

#First erase any old object files and old executable files, if any exist from past compilations
rm *.o
rm *.out

#Look at the contents of the current directory.
echo "You should see 4 C source files and maze.sh in the list below."
ls -l


#Next compile maze.c
gcc -m64 -c -std=c99 -Wall -o mazemain.o mazemain.c

#Next compile bloackonright.c
gcc -m64 -c -std=c99 -Wall -o blockonright.o blockonright.c

#Next compile turnleft.c
gcc -m64 -c -std=c99 -Wall -o turnleft.o turnleft.c

#Next compile turnright.c
gcc -m64 -c -std=c99 -Wall -o turnright.o turnright.c


#Next link four object files together to create an executable file
gcc -m64 -std=c99 -o maze.out mazemain.o blockonright.o turnleft.o turnright.o

#Execute the executable file.
./maze.out

echo The Mouse Maze program has terminated
