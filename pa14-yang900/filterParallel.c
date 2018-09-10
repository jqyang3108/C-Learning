#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "filterParallel.h"

void applyThread(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int tid, int numThreads) {

  int startOfRow = 0;
  int endOfRow = 0;

  startOfRow = (imageIn -> norm_height / numThreads) * tid;
  endOfRow =  (imageIn -> norm_height / numThreads) * (tid + 1);
  
  for(int i = startOfRow; i < endOfRow; i++){
    for(int j = 0; j < imageIn -> header.width_px;j++){
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
	  }else if(a > imageIn -> norm_height - 1){
	    a = imageIn -> norm_height -1; 
	  }
	  if(b < 0){
	    b = 0;
	  }else if(b > imageIn -> header.width_px -1){
	    b = imageIn -> header.width_px -1; 
	  }
	  blue += imageIn -> pixels[a][b].blue * f.filter[q][w];  
	  red += imageIn -> pixels[a][b].red * f.filter[q][w]; 
	  green += imageIn -> pixels[a][b].green * f.filter[q][w]; 
	  alpha += imageIn -> pixels[a][b].alpha * f.filter[q][w]; 	 
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
      imageOut -> pixels[i][j].blue = blue;
      imageOut -> pixels[i][j].red = red;
      imageOut -> pixels[i][j].green = green;
      imageOut -> pixels[i][j].alpha = alpha;  
    } 
  }
  
  
  return;
}

void * applyThreadWrapper(void * args) {
	ApplyArgs * applyArgs = (ApplyArgs *) args;
	fprintf(stdout, "calling thread %d\n", applyArgs->tid);
	
	applyThread(applyArgs->in, applyArgs->out, applyArgs->filter, applyArgs->tid, applyArgs->numThreads);
	
	fprintf(stdout, "finished with thread %d\n", applyArgs->tid);
	
	return NULL;
}

void apply(BMPImage * imageIn, BMPImage * imageOut, BoxFilter f, int numThreads) {


	pthread_t * threads = malloc(sizeof(pthread_t) * numThreads);
	ApplyArgs * args = malloc(sizeof(ApplyArgs) * numThreads);
	
	for (int i = 0; i < numThreads; i++) {
	  args[i].tid = i;
	  args[i].numThreads = numThreads;
	  args[i].in = imageIn;
	  args[i].out = imageOut;
	  args[i].filter = f;
	  pthread_create(&threads[i], NULL, applyThreadWrapper, &args[i]);

	}

	for (int i = 0; i < numThreads; i++) {
	  pthread_join(threads[i], NULL);
	}
	
	free(args);
	free(threads);

	return;	
}
