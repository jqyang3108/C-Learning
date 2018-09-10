#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/


//compare
int compare(const void * char1, const void * char2){
  
  Array * char_compar1 = (Array*)char1;
  Array * char_compar2 = (Array*)char2;

  return ((char_compar1 -> freq) - (char_compar2 -> freq));
}

//convert 
Array sortedTempNodeList(long *asciiCount){
  int size = 0;

  //count number of letters
  for(int i = 0; i< ASCII_SIZE;i++){
    if(asciiCount[i] != 0){
      size++;
    }
  }
  //an array containning existing letters and frequencies
  Array *tempArr = malloc(sizeof(Array * size));
   
  int countArray = 0;
  int j = 0;

  //create the array contains every existing letter and frequency
  for((j < ASCII_SIZE) && (countArray < size)){
    if(asciiCount[j] > 0){
      tempArr[j].freq = asciiCount[i];
      tempArr[j].label = j;
      countArray++;
    }
    j++;
  }

  //create head
  ListNode * head = malloc(sizeof(ListNode));
  head -> ptr = NULL;
  head -> next = NULL;

  qsort(tempArr, size, sizeof(Array),compare);

  for(int k = 0;k < size, k++){
    TreeNode * node = buildNode(tempArr[k].label, tempArr[k].freq);
    addNode(head,node);
  }

  return head; 
}










TreeNode * buildNode(long count, int label) {

  //allocate memory
  TreeNode * build = malloc(sizeof(TreeNode));     

  build -> count = count;   
  build -> label = label;                   
  build -> right = NULL;               
  build -> left = NULL;

  return build;
}


void  addNode(PathLL * paths, char * path) {

  return;	   
}

/*-------------
bool removeNode(PathLL * paths, char * path) {

}
---------------*/
