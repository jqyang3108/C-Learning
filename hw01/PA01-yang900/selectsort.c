#ifdef SELECTION_SORT
#include "pa01.h"
void selectSort(int * arr, int size)
//arr : the array to be sorted
//size : the number of elements in the array

// In each iteration, the number of elements to be sorted shrinks by one
// i.e., one element is at the correct position.
//
// Among the remaining elements, find the smallest value and put it 
// before the other unsorted elements
{

	//TODO: Fill this in to complete PA01.
  int cursor;                                       //Declearation of variables
  int swap_val;
  int smallest_index;
  int count;
  for (cursor = 0; cursor < size; cursor++)         //sort the list
    {                                                      
     smallest_index = cursor;                      
     for (count = cursor; count < size; count++)    //search the rest of value to
       {                                            //find the smallest value
	 if (arr[count] < arr[smallest_index])     
	    smallest_index = count;
       }
     swap_val = arr[cursor];                       //swap the smallest value with
     arr[cursor] = arr[smallest_index];            //the cursor value
     arr[smallest_index] = swap_val;
    }	
}
#endif

