#include <stdlib.h>
#include <stdio.h>
#include "filter.h"

#ifndef BLUR_OFF
BMPImage * blur(BMPImage * image) {

//FILL IN	

  BMPImage * newImage = malloc(sizeof(BMPImage));
  newImage -> header = image -> header;
  newImage -> norm_height = image -> norm_height;
  newImage -> pixels = malloc(sizeof(Pixel *) * image -> norm_height);
  
  for(int i = 0; i < image -> norm_height; i++){
    newImage -> pixels[i] = malloc(sizeof(Pixel) * image -> header.width_px);   
  }

  for(int row = 0; row < newImage -> norm_height; row++){
    for(int col = 0; col < newImage -> header.width_px;col++){
      int red = 0;
      int green = 0;
      int blue = 0;
      int alpha = 0;
      
      newImage -> pixels[row][col].red = red;
      newImage -> pixels[row][col].green = green;
      newImage -> pixels[row][col].blue = blue;
      newImage -> pixels[row][col].alpha = alpha;

      for(int filterRow = -1; filterRow <= 1; filterRow++){
	for(int filterCol = -1; filterCol <= 1; filterCol++){
	  int mRow = filterRow;
	  int mCol = filterCol;
	  if((row + filterRow) < 0 || ((row + filterRow) >= (newImage -> norm_height))){
	    mRow = 0;
	    }
	  if((col + filterCol) < 0 || ((col + filterCol) >= (newImage -> header.width_px))){
	    mCol = 0;
	  }
	  blue += image -> pixels[row + mRow][col + mCol].blue;
	  red += image -> pixels[row + mRow][col + mCol].red;
	  green += image -> pixels[row + mRow][col + mCol].green;
	  alpha += image -> pixels[row + mRow][col + mCol].alpha;
	}	
	newImage -> pixels[row][col].blue = blue / 9;
	newImage -> pixels[row][col].red = red / 9;
	newImage -> pixels[row][col].green = green / 9;
	newImage -> pixels[row][col].alpha = alpha / 9;
      }
    }
  }
  return newImage;
}
#endif

// EXTRA CREDIT START
BMPImage * apply(BMPImage * image, BoxFilter f) {



 BMPImage * newImage = malloc(sizeof(BMPImage));
 newImage -> header = image -> header;
 newImage -> norm_height = image -> norm_height;
 

 Pixel * * new = malloc(sizeof(Pixel *) * image -> norm_height);
 for(int i = 0; i < image -> norm_height; i++){
   new[i] = malloc(sizeof(Pixel) * image -> header.width_px);   
   for(int j = 0; j < image -> header.width_px;j++){
     int blue = 0;
     int red = 0;
     int green = 0;
     int alpha = 0;
     for(int q = 0; q < 3; q++){
       for(int w = 0; w < 3; w++){
	 int a = i + q - 1;
	 int b = j + w - 1;
	 if(a < 0){
	   a = 0;
	 }else if(a > image -> norm_height -1){
	   a = image -> norm_height -1; 
	 }
	 if(b < 0){
	   b = 0;
	 }else if(b > image -> header.width_px -1){
	   b = image -> header.width_px -1; 
	 }
	 blue += image -> pixels[a][b].blue * f.filter[q][w];  
	 red += image -> pixels[a][b].red * f.filter[q][w]; 
	 green += image -> pixels[a][b].green * f.filter[q][w]; 
	 alpha += image -> pixels[a][b].alpha * f.filter[q][w]; 	 
       }
     }
     blue /= f.norm;
     if(blue > 255){
       blue = 255;
     }else if(blue < 0){
       blue = 0;
     }
     red /= f.norm;
     if(red > 255){
       red = 255;
     }else if(red < 0){
       red = 0;
     }
     green /= f.norm;
     if(green > 255){
       green = 255;
     }else if(green < 0){
       green = 0;
     }
     alpha /= f.norm;
     if(alpha > 255){
       alpha = 255;
     }else if(alpha < 0){
       alpha = 0;
     }
     new[i][j].blue = blue;
     new[i][j].red = red;
     new[i][j].green = green;
     new[i][j].alpha = alpha;  
   }

}
 newImage -> pixels = new;
 return newImage;
}
BoxFilter * readFilter(FILE * infile) {
	
//FILL IN
  if(infile == NULL){
    return NULL;
  }
  
  BoxFilter * box = malloc(sizeof(BoxFilter));
 
 
  for(int row = 0; row < 3; row++){
    for(int col = 0; col < 3; col++){
      fscanf(infile, "%d", &(box -> filter[row][col]));
    }
  }
  
  fscanf(infile, "%f",&(box -> norm));
  return box;
  
}
// EXTRA CREDIT END
