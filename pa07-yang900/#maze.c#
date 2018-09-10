#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

#ifndef READMAZE_OFF
Maze * readMaze(char * mazeFilename) {

	//FILL IN
 
  Maze * mazeStruct = malloc(sizeof(Maze));
  
  //read file
  FILE * mazeFile = fopen(mazeFilename, "r");
  fscanf(mazeFile,"%d %d\n", &(mazeStruct -> height), &(mazeStruct -> width));

  //allocat the memory for the 2d array
  mazeStruct -> maze = malloc((mazeStruct -> height) * sizeof(MazeSquare*));
  char square;
  
  for(int i = 0; i< (mazeStruct -> height); i++)
    {
      mazeStruct -> maze[i] = malloc((mazeStruct -> width) * sizeof(MazeSquare));
      
      for(int j =0; j < (mazeStruct -> width);j++)
	{
	  //read maze
	  square = fgetc(mazeFile);
	  if(square != EOF)
	    {
	      if(square == '\n')
		{
		  square = fgetc(mazeFile);
		}

	      //assign this position to be not visited
	      mazeStruct -> maze[i][j].visited = false;

	      //determine the content of mazeFile
	      if(square == START)
		{
		  ((*mazeStruct).maze[i][j]).type = square;
		  (*mazeStruct).start.xpos = j;
		  (*mazeStruct).start.ypos = i;
		}
	      else if(square == END)
		{
		  ((*mazeStruct).maze[i][j]).type = square;
		  (*mazeStruct).end.xpos = j;
		  (*mazeStruct).end.ypos = i;
		}
	      else
		((*mazeStruct).maze[i][j]).type = square;
	    }
	}
    }

  printf("\n\n-------start---------");
  //close file
  fclose(mazeFile);		      
  //return pointer of maze
  return (mazeStruct); 

}
#endif //#ifndef READMAZE_OFF

#ifndef FREEMAZE_OFF
void freeMaze(Maze * m) {
	//1. Free each of the "rows" of the maze
  for(int i = 0; i < (m -> height); i++)
    {
      free(m -> maze[i]) ;
    }
	
	//2. Free the "spine" of the array
  free(m -> maze);
}
#endif //#ifndef FREEMAZE_OFF
