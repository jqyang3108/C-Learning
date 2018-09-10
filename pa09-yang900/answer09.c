#include "answer09.h"

bool isCircular(const node_t * head)
{
  //initialization of two pointers
 const node_t *slowptr = head;
 const node_t *fastptr = head;


 //test loop only if the current is not NULL
 while(fastptr != NULL)
   {
     fastptr = fastptr -> next;
     //move fast pointer to the next two
     if(fastptr != NULL && fastptr -> next != NULL)
	{
	  fastptr = fastptr -> next;
	}
     else
       {
	 return false;
       }

     //move the slow pointer to the next
     slowptr = slowptr -> next;
     
     //determine if slow matches slow
     if(fastptr == slowptr)
       {
	 return true;
       }
   }
 return false;
}

