#include "life.h"
#include <time.h>
//Generate the life matrix any way you want. We would highly recommend that you print the generated
//matrix into a file, so that you can share it with other teams for checking correctness.
void genlife(int *a, unsigned int n)
{
  
}

//Read the life matrix from a file
void readlife(int *a, unsigned int n, char *filename)
{
  
}

//Life function
void life(int *a, unsigned int n, unsigned int iter, int *livecount)
{

  //loop iters out here
  for (int iterations = 0; iterations < iter; iterations++){
      int temp[n*n];
      copy(a, temp);
      int livecounter = 0;
      
    if (iterations % (iter/10) == 0) {
      livecount[livecounter] = countlive(a, n);
      livecounter++;
    }
    
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
	int counter = 0;
	int north = (i-1) % n;
	int south = (i+1) % n;
	int west = (j-1) % sqrt(n);
	int east = (j+1) % sqrt(n);
      
	//count the neighbors counterclockwise from north
	count = a[north + north*j] + a[north + north*west] + a[i + i*west] + a[south + south*west]
	  + a[south + south*j] + a[south + south*east] + a[i + i*east] + a[north+ north*east];

	if(counter > 3 || counter < 2) temp[i + i*j] = 0;    //dies
	if(counter == 2) temp[i + i*j] = a[i + i*j];    //nothing
	if(counter == 3) temp[i + i*j] = 1;    //birth
      }
    }

  //array is now updated
    copy(temp, a);

  }
  
    // You need to store the total number of livecounts for every 1/0th of the total iterations into the livecount array.
	// For example, if there are 50 iterations in your code, you need to store the livecount for iteration number 5 10 15
	// 20 ... 50. The countlive function is defined in life.cpp, which you can use. Note that you can
	// do the debugging only if the number of iterations is a multiple of 10.
	// Furthermore, you will need to wrap your counting code inside the wrapper #if DEBUG == 1 .. #endif to remove
	// it during performance evaluation.
	// For example, your code in this function could look like -
	//
	//
	//	for(each iteration)
	//      {
	//
	//		Calculate_next_life();
	//
	//		#if DEBUG == 1
	//		  if_current_iteration == debug_iteration
	//		  total_lives = countlive();
	//		  Store_into_livecount(total_lives);
	//		#ENDIF
	//
	//	}
}
