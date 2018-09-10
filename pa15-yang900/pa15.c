#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

/* count the occurrences in a file */

long *countLetters(FILE *fp)
{
   long *asciiCount = (long *)malloc(sizeof(long)*ASCII_SIZE);
   if (asciiCount == NULL) {
      return NULL;
   }
   int ch;
   for (ch = 0; ch < ASCII_SIZE; ch++) {
      asciiCount[ch] = 0;
   }
   fseek(fp, 0, SEEK_SET);
   while ((ch = fgetc(fp)) != EOF) {
      asciiCount[ch] += 1;
   }
   return asciiCount;
}


int main(int argc, char **argv)
{
   if (argc != 5) {
    printf("Not enough arguments");
    return EXIT_FAILURE;
   }
   FILE * inFile = fopen(argv[1], "r");
   if (inFile == NULL) {
      fprintf(stderr, "can't open the input file.  Quit.\n");
      return EXIT_FAILURE;
   }

   /* read and count the occurrences of characters */
   long *asciiCount = countLetters(inFile);
   fclose(inFile);

   if (asciiCount == NULL) {
      fprintf(stderr, "cannot allocate memory to count the characters in input file.  Quit.\n");
      return EXIT_FAILURE;
   }


   // Your code should go here
   FILE * sortedList = fopen(argv[2], "w");
   
   //create a sorted list
   ListNode * head = sortedNodeList(asciiCount);
   printLinkedList(sortedList, head);
   fclose(sortedList);

   //huffmam encoding
   FILE * huffman = fopen(argv[3], "w");
   createTree(&head);
   char * content = malloc(sizeof(char) * ASCII_SIZE);
   int i = 0;
   printTree(huffman, head->ptr, i, content);
   fclose(huffman);

   //header
   FILE * header = fopen(argv[4],"w");
   uint8_t * eight = malloc(sizeof(uint8_t));
   *eight = 0x00;
   int *cur = malloc(sizeof(int));
   *cur = 0;
   printHeader(header,head->ptr,eight,cur);

   if(*cur > 0){
     fwrite(eight,sizeof(uint8_t),1,header);
   }
   
   //memory free
   fclose(header);
   free(asciiCount);
   free(cur);
   free(content);
   free(eight);
   freeNode(head -> ptr);
   free(head);
   
   return EXIT_SUCCESS;
}

//------------------------------create a sorted linked list-----------------------------
//compare
int compare(const void * char1, const void * char2){
  
  Array * char_compar1 = (Array*)char1;
  Array * char_compar2 = (Array*)char2;

  return ((char_compar1 -> freq) - (char_compar2 -> freq));
}

//create new list node
TreeNode * buildNode(long count, int label){
  TreeNode * newNode = malloc(sizeof(TreeNode));
  newNode -> label = label;
  newNode -> count = count;
  newNode -> left = NULL;
  newNode -> right = NULL;
  
  return newNode;
}

//convert 
ListNode * sortedNodeList(long *asciiCount){
  int size = 0;
  int i = 0;
  //count number of letters
  while(i< ASCII_SIZE){
    if(asciiCount[i] > 0){
      size++;
    }
    i++;
  }
  //an array containning existing letters and frequencies
  Array *tempArr = malloc(sizeof(Array) * size);
  int countArray = 0;
  int j = 0;
  
  //create the array contains every existing letter and frequency
  while((j < ASCII_SIZE) && (countArray < size)){
    if(asciiCount[j] > 0){
      tempArr[countArray].freq = asciiCount[j];
      tempArr[countArray].label = j;
      countArray++;
    }
    j++;
  }
  
  //create head
  ListNode * head = malloc(sizeof(ListNode));
  head -> ptr = NULL;
  head -> next = NULL;

  qsort(tempArr, size, sizeof(Array),compare);

  for(int k = 0;k < size; k++){
    TreeNode * node = buildNode(tempArr[k].freq, tempArr[k].label);
    addListNode(head,node);
  }
  
  free(tempArr);
  return head;
}

void addListNode(ListNode *head, TreeNode * tree){
  ListNode * newNode = malloc(sizeof(ListNode));

  newNode -> ptr = tree;
  newNode -> next = NULL;
  if(head -> ptr == NULL){
    head -> next = NULL;
    head -> ptr = tree;
    free(newNode);
    return;
  }
  else{
    ListNode * current = head;
    while(current -> next != NULL){
      current = current -> next;
    }
    current -> next = newNode;
  }

  return;
}

//-------------------------------create huffman tree ----------------------------
void createTree(ListNode ** head){
  if(*head == NULL){
    return;
  }
  else if((*head) -> next == NULL){
    return;
  }
  else{
    ListNode * newNode = malloc(sizeof(ListNode));
    newNode = buildTreeNode(head, newNode);
    ListNode ** current;
    current = sort((&(*head)-> next -> next),newNode -> ptr->count);
    removeNode(current, head,newNode);
  }
  createTree(head);
  return;
}

ListNode * buildTreeNode(ListNode ** head, ListNode * newNode){

  newNode -> ptr = malloc(sizeof(TreeNode));
  newNode -> ptr -> count = (*head) -> ptr -> count +  (*head)-> next -> ptr -> count;
  newNode -> ptr -> left = (*head) -> ptr;
  newNode -> ptr -> right = (*head) -> next -> ptr;
  
  return newNode;
}

void removeNode(ListNode ** current, ListNode ** head, ListNode * newNode){  
  ListNode * tempArr = *current;
  *current = newNode;
  (*current) -> next = tempArr;
  ListNode * tempArr2 = *head;
  *head = (*head) -> next -> next;
  free(tempArr2 -> next);
  free(tempArr2);
  
  return;
}

ListNode ** sort(ListNode ** current, long asciiCount){
  if((*current) == NULL){
    return(current);
  }
  else if((*current) -> ptr -> count > asciiCount){
    return(current);
  }
  else{
    ListNode ** tempArr = sort(&((*current) -> next),asciiCount); 
    return(tempArr); 
   }
}

//free tree
void freeNode(TreeNode * node){
  if(node == NULL){
    return;
  }
  freeNode(node -> left);
  freeNode(node -> right);
  free(node);
  return;
}

//-----------print tree, header, linked list---------------
void printHeader(FILE * header, TreeNode * head, uint8_t * eightBit, int * cur){

  if(head -> left != NULL){
    bit(header, 0x00, eightBit, cur, 1);
  }
  if(head -> left == NULL){
    bit(header, 0x80, eightBit, cur, 1);
    bit(header, (uint8_t)head->label, eightBit, cur, 8);
    return;
  }
  printHeader(header, head -> left, eightBit, cur);
  printHeader(header, head -> right, eightBit, cur);
  return;
}

void printTree(FILE * huffman, TreeNode * head, int i, char * content){
  if(head -> left == NULL){
    content[i] = '\0';
    fprintf(huffman, "%c:%s\n",(char)head->label, content);
    return;
  }
  content[i] = '0';
  printTree(huffman, head->left, i + 1, content);
  content[i] = '1';
  printTree(huffman, head->right, i + 1, content);
  return;
}

void printLinkedList(FILE * sorted, ListNode * head){
  ListNode * cur = head;
  while(cur != NULL){
    fprintf(sorted, "%c:%ld\n", (char)cur->ptr->label, cur->ptr->count);
    cur = cur -> next;
  }
  return;
}

//write bit
void bit(FILE * header, uint8_t write, uint8_t * eight, int * current, int add){
  if((*current) + add <= 8){
    *eight = (*eight) + (write >> (*current));
    (*current) = (*current) + add;
  }
  else{
    *eight = (*eight) + (write >> (*current));
    fwrite(eight, sizeof(uint8_t), 1, header);
    *eight = write << (add - *current);
    *current = 8 - (add - *current);
  }
  if(*current == 8){
    *current = 0;
    fwrite(eight, sizeof(uint8_t), 1, header);
    *eight = 0x00;
  }
  return;
}
