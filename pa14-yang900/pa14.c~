#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"
#include "bmp.h"

int main (int argc, char * argv[]) {

  FILE *fp = fopen("test.bmp","rb");
  BMPImage *image = readImage(fp);
  FILE * fp1 = fopen("output_test.bmp","wb");
  writeImage(image,fp1);

  FILE * fp2 = fopen("blurtest.bmp","wb");
  BMPImage * newblur = blur(image);
  writeImage(newblur,fp2);

  FILE * fp3 = fopen("sharpen.filter","r");
  BoxFilter * box = readFilter(fp3);
 
  FILE * fp4 = fopen("sharpen_output","wb");
  BMPImage * sharp = apply(image, *box);
  writeImage(sharp,fp4);


  fclose(fp);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  free(box);
  freeImage(image);
  freeImage(newblur);
  freeImage(sharp);
  return 0;
}
