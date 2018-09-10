#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"

char * solveMaze(Maze * m) {
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {

	//FILL IN

  //cursor
  int posX = curpos.xpos;
  int posY = curpos.ypos;

  printf("Current position %d %d\n",posX,posY);

  //-------------------------base case----------------------------------------------------------

  //determine if the cursor is out of the boundry
  if(((posX < 0) || (posX  == (m -> width)))  ||  ((posY < 0) || (posY == (m -> height))))
    {
      printf("\nOut of boundary\n");
      return false;
    }
  
  //determine if the cursor hits the wall
  else if((((*m).maze[posY][posX]).type == WALL))
    {
      printf("\nHit the wall\n");
      return false; 
    }
  
  // determine if the cursor returned to the previous position;
  else if(((*m).maze[posY][posX]).visited == true)
    {
      printf("\nHave visited!\n");
      return false;
    }
  
  // mark current position as visted

  else if((((*m).maze[posY][posX]).type) == END)
    {
      path[step] = '\0';
      return true;
    }
  else
    {
      ((*m).maze[posY][posX]).visited = true;  
    }
  //--------------------------------------------------------------------------------------------

  //update cursor
  MazePos north = curpos;
  north.ypos--;
  MazePos south = curpos;
  south.ypos++;
  MazePos east = curpos;
  east.xpos++;
  MazePos west = curpos;
  west.xpos--;


  //check go north
  if(depthFirstSolve(m, north, path, step + 1) )
    {
      path[step] = NORTH;
      return true;
    }

  //check go south
  else if(depthFirstSolve(m, south , path, step + 1) )
    {
      path[step] = SOUTH;
      return true;
    }

  //check go east
  else if(depthFirstSolve(m, east, path, step + 1) )
    {
      path[step] = EAST;
      return true;
    }
  
  //check go west
  else if(depthFirstSolve(m, west, path, step + 1) )
    {
      path[step] = WEST;
      return true;
    }

  //if going all the directions returns false, then false
  else
    {
      return false;
    }
}
