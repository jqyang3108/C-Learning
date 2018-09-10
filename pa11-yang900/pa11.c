#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
		return EXIT_FAILURE;
	}

	float result;

	//read input file		
 	FILE * input = fopen(argv[1], "r");

	if(input == NULL) {
	    printf("Empty File!\n");
	    return EXIT_FAILURE;
	  }

	//calculate the result
	char * string = malloc(sizeof(char *));
	PathLL * list = malloc(sizeof(PathLL *));
	list -> head = NULL;
	float num, val1, val2,answer = 0;
	while(fscanf(input, "%s", string) != EOF){
	  if(*string == '+' || (*string == '-' && strlen(string) == 1 )|| *string == '*' ||*string == '/'){
	    //check if the expression is valid
	    if((list -> head  == NULL) ||(list -> head -> next == NULL)){
	      return EXIT_FAILURE;
	    }
	    val1 = pop(list);
	    val2 = pop(list);
	    answer = calc(val1, val2, string);
	    push(list,answer);
	  }
	  else{	    	    
	    num = (float)atof(string);
	    push(list, num);
	  }
	}
	fclose(input);
	//check if the list is empty of contains more than one number
	if(list -> head == NULL || list -> head -> next != NULL){
	  free(string);
	  freePaths(list);
	  return EXIT_FAILURE;
	}

	result = list -> head -> operand;
	printf("%f\n", result);
	
	free(string);
	freePaths(list);
	
	return EXIT_SUCCESS;
}



void push(PathLL * list, float num){
  
  //create new node
  PathNode * newNode = malloc(sizeof(PathNode));  
  newNode -> operand = num;
  newNode -> next = NULL;
 //create head

  if(list -> head == NULL){
    list -> head = newNode;
  }
  else{
    //let the new node be the head of linked list
    newNode -> next = list -> head;
    list -> head = newNode;
  }
  return;
}

float pop(PathLL * list){

  PathNode * temp =  list -> head;
  list -> head = list -> head -> next;
  
  float number = temp -> operand;
  freeNode(temp);
  return number;
}

float calc(float nodeA, float  nodeB, char * string){
  float result;

  if(*string == '+'){
    result  = nodeB + nodeA;
  }
  else if(*string == '-'){
    result  = nodeB - nodeA;
  }
  else if(*string == '*'){
    result  = nodeB * nodeA;
  }
  else if(*string == '/'){
     result  = nodeB / nodeA;
  }

  return result;
}

void freePaths(PathLL * p) {


  if(p -> head != NULL)
    {
      PathNode *temp = p -> head;
      PathNode *temp2 = NULL;

      while(temp != NULL)
	{
	  temp2 = temp -> next;
	  freeNode(temp);
	  temp = temp2;
	}
    }
  free(p);
}

void freeNode(PathNode * p) {

  free(p);
}
