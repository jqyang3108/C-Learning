#ifndef PA15_H
#define PA15_H
#include <stdint.h>
		 

#define ASCII_SIZE 256


typedef struct TreeNode {
   int label;
   long count;
   struct TreeNode *left;
   struct TreeNode *right;
} TreeNode;

typedef struct ListNode {
   TreeNode *ptr;
   struct ListNode *next;
} ListNode;

typedef struct Array{
  int label;
  long freq;
}Array;

int compare(const void * char1, const void * char2);
TreeNode * buildNode(long count, int label);
ListNode * sortedNodeList(long *asciiCount);
void addListNode(ListNode *head, TreeNode * tree);
void createTree(ListNode ** head);
ListNode * buildTreeNode(ListNode ** head, ListNode * newNode);
void removeNode(ListNode ** current, ListNode ** head, ListNode * newNode);
void freeNode(TreeNode * node);
void printHeader(FILE * header, TreeNode * head, uint8_t *eightBit, int * cur);
void printTree(FILE * huffman, TreeNode * head, int step, char * content);
void printLinkedList(FILE * sorted, ListNode * head);
void bit(FILE * header, uint8_t write, uint8_t *eight, int * current, int add);
ListNode ** sort(ListNode ** current, long asciiCount);

#endif
