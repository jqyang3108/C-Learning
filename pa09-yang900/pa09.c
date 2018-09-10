#include "linkedlist.h"
#include "answer09.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * * argv)
{

  //THIS IS JUST SAMPLE CODE FOR TESTING. YOU WILL HAVE TO BUILD YOUR OWN
  //TEST CASES
  
  //Build one or more linked lists here
  node_t * head = NULL;
  printf("\ncreated head");
  for (int i = 0; i < 10; i++)
    {
      insert(&head, 0, 50 + i); //insert at "index 0" with respect to the head the number 50 + i
    }
  printlist(head);
  
  
  //Check to see if the lists you have built are circular
  bool result = isCircular(head);
  if(result == false)
    {
      printf("\nthe list is good");
    }
  else
    {
      printf("\nthe list is loop");
    }

  /* More testing ... */
  return 1;
}
