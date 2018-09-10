#include <stdio.h>
#include <stdlib.h>
#include "path.h"

#ifndef READPATH_OFF
char * readPath(char * pathFilename) {

	//FILL IN

  //open file
  FILE * pathFile = fopen(pathFilename, "r");

  //check file
  if(pathFile == NULL)
    return NULL;
  
  //count the number of elements
  int step = 0;
  char count;
  do
    {
      count = fgetc(pathFile);
      step++;
    }
  while(count != EOF);
  
  //return to the begining of file
  fclose(pathFile);
  pathFile = fopen(pathFilename, "r");
  if(pathFile == NULL)
    {
      return NULL;
    }

  //allocate memory
  char * path = malloc((step+1) * sizeof(char));

  //create the string of path
  for(int i = 0; i < step; i++)
    {
      path[i] = fgetc(pathFile);
    }


  //assign NULL to the ending of path string
  path[step-1] = '\0';
  
  //close file
  fclose(pathFile);

  //return the string of path
  return path;
}
#endif //#ifndef READPATH_OFF

#ifndef CHECKPATH_OFF
bool checkPath(Maze * m, char * path) {

	//FILL IN
 
  //create cursors of the location of start and end point
  int startX = m -> start.xpos;
  int startY = m -> start.ypos;
  int endX = m -> end.xpos;
  int endY = m -> end.ypos;


  printf("\n  dimenstion is %dX%d path is %s" ,(m -> width), (m -> height), path );
  printf("\nSta at x%d y%d",startX, startY);

  //move the cursor
  while(path[i])
    {
      //move 
      if((path[i] == NORTH))
	{
	  startY--;
	}
      else if((path[i] == SOUTH))
	{
	  startY++;
	}
      else if((path[i] == EAST))
	 {
	   startX++;
	 }
      else if((path[i] == WEST))
	 {
	   startX--;
	 }
      
      //show current position
      printf("\nNow at x%d y%d",startX, startY);

      // determine if the cursor is out of the boundary 
      if(((startX < 0) || (startX == (m -> width)))  ||  ((startY < 0) || (startY == (m -> height))))
      	{
	   printf("\nOut of boundary\n");
	  return false;
	}

      //determine if the cursor hits the wall
      else if((((*m).maze[startY][startX]).type == WALL))
	 {
	   printf("\nHit the wall\n");
	   return false; 
	 }
 
      // determine if the cursor returned to the previous position;
      else if(((*m).maze[startY][startX]).visited == true)
      	{
	   printf("\nHave visited!\n");
	  return false;
      	}
	
      // mark current position as visted
      else
	{
	  //if cursor moves to the end point before the path ends, return true
	  if( (((*m).maze[startY][startX]).type == END))
	    {
	      return true; 
	    }
	  else
	    {
	      ((*m).maze[startY][startX]).visited = true;
	    }
	}

      i++;
      }

  //determine if the cursor move to the end point at the end of path
  printf("\nstart and end position:%d %d %d %d\n---------end----------\n The result is: ", startX, startY, endX, endY);	 

  if(startX == endX && startY == endY)
    {
      return true;
    }
  else
    {
      return false;
    }
}
#endif //#ifndef CHECKPATH_OFF
