#ifndef _CALC_H_
#define _CALC_H_

//Linked list node
typedef struct PathNode {
	float  operand;
	struct PathNode * next;
} PathNode;

//Structure to hold head pointer of linked list
typedef struct PathLL {
	PathNode * head;
} PathLL;

void push(PathLL * list, float num);
float pop(PathLL * list);
float calc(float nodeA, float  nodeB, char * string);

void freePaths(PathLL * p);
void freeNode(PathNode * p);

#endif
