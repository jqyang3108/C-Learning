// Do not remove #ifdef ... #endif before and after each function.
// 
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  for (int ind = 0; ind < num; ind ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n",
	     stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
    }
}

#ifdef TEST_READ
// return false if anything is wrong 
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: address of the allocated memory
// output: number of students
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
  // open the file to read
  FILE * open = fopen(filename, "r");

  // if fopen fails, return false
  // do not use fclose since fopen already fails
  if(open == NULL)
    {
      return false;
    }

  // count the number of lines to determine the number of students
  int count;
  int line = 0;
  
  do
    {
     count = fgetc(open);
     if(count == '\n')
       {
	 line++;
       }
    }
		   
  while(count != EOF);
  *numelem = line;

  
  // return to the beginning of the file
  // you can use fseek or
  // fclose followed by fopen
  // You need to check whether fseek or fopen fails
  // Do not use rewind because it does not report whether it fails
  fclose(open);
  open = fopen(filename, "r");
  if(open == NULL)
    {
      return false;
    }
  
  // allocate memory for the data
  Student * openr = malloc(sizeof(Student)*(*numelem));
  *stu = openr;

  // check whether memory allocation fails
  if(open == NULL)
    {
      return false;
    }

  // read the data from the file and store the data in the allocated memory
  int readData;
  for (int i = 0; i<(*numelem); i++)
    {
      readData = fscanf(open ,"%d %s %s\n", (&openr[i].ID), (openr[i].firstname), (openr[i].lastname));
      if(readData != 3)
	{
	  return false;
	}
    }
  // close the file
  fclose(open);


  return true;
}
#endif

#ifdef TEST_WRITE
// return false if anything is wrong 
// return true if writing the file successfully
// input: filename, the name of the output file
// input: address of the student array
// input: number of students

bool StudentWrite(char * filename, Student * stu, int numelem)
{
  // open the file to write 
  FILE * open = fopen(filename,"w");
  if(open == NULL)
    {
      return false;
    }

  // if fopen fails, return false
  // do not use fclose since fopen already fails
  for(int i = 0; i < numelem; i++)
    {
      fprintf(open, "%d %s %s\n",(stu[i].ID), (stu[i].firstname), (stu[i].lastname));
    }
  
  fclose(open);
  return true;

  // write the students to the output file


}
#endif 

int compare(const void* arg1, const void * arg2)
{
  const Student * ptr1 = (const Student *)arg1;
  const Student * ptr2 = (const Student *) arg2;
  int val1 = ptr1 -> ID;
  int val2 = ptr2 -> ID;
  if(val1 < val2)
    {
      return -1;
    }
  if(val1 == val2)
    {
      return 0;
    }
  return 1;
}

#ifdef TEST_SORTID
void StudentSortbyID(Student * stu, int numelem)
{
  qsort(stu, numelem, sizeof(Student), compare);

}
#endif

int cmpfirst(const void *arg1, const void * arg2)
{ 
  const Student * ptr1 = (const Student *)arg1;
  const Student * ptr2 = (const Student *)arg2;
  return strcmp(ptr1 -> firstname, ptr2 -> firstname);
}

#ifdef TEST_SORTFIRSTNAME
void StudentSortbyFirstName(Student * stu, int numelem)
{
  qsort(stu, numelem, sizeof(Student), cmpfirst);
}
#endif

int cmplast(const void *arg1, const void * arg2)
{ 
  const Student * ptr1 = (const Student *)arg1;
  const Student * ptr2 = (const Student *)arg2;
  return strcmp(ptr1 -> lastname, ptr2 -> lastname);
}

#ifdef TEST_SORTLASTNAME
void StudentSortbyLastName(Student * stu, int numelem)
{
  qsort(stu, numelem, sizeof(Student), cmplast);

}
#endif
