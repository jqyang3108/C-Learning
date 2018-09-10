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


  fclose(fp);
  fclose(fp1);
  fclose(fp2);

  free(box);
  freeImage(image);
  freeImage(newblur);
  return 0;
}
