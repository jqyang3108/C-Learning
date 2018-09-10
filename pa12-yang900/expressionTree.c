#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) {

  Token cur = nextToken(s);

  if(cur.type == T_VAL){
    TreeNode * node = buildTreeNode(cur);
    node -> t = cur;

    return node;
  }

  if(cur.type == T_LPAREN){
    TreeNode * left = buildExpressionTree(s);
    //move to next token
    cur = nextToken(s);
    if((cur.type == T_ADD) || (cur.type == T_SUB) || (cur.type == T_MUL) || (cur.type == T_DIV)){
      Token operator = cur;
      TreeNode * right = buildExpressionTree(s);
      TreeNode * node = buildTreeNode(operator);
      node -> left = left;
      node -> right = right;
      cur = nextToken(s);
   
      if(cur.type == T_RPAREN){
	return node;
      }
      else{
	return NULL;
      }     
    }
  }
  
  return NULL;
}

#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {
  if(t == NULL){
    return;
  }
  makePostFix(t -> left, fptr);
  makePostFix(t -> right, fptr);
  if(t -> t.type == T_VAL){
    fprintf(fptr, "%f ", t -> t.value);
  }
  else{
    fprintf(fptr,"%c ", t -> t.type);
  }
}
#endif
