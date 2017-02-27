#include "life.h"
#include <time.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <math.h>

using namespace std;

//Generate the life matrix any way you want. We would highly recommend that you print the generated
//matrix into a file, so that you can share it with other teams for checking correctness.
void genlife(int *a, unsigned int n)
{
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){      
      a[i + i*j] = rand()%2;
    }
  }
}

//Read the life matrix from a file
void readlife(int *a, unsigned int n, char *filename)
{
  //ARRAY HAS SIZE N*N
  ifstream infile(filename);
   /* parse file */
   int i = 0;

   for(string line; getline(infile, line);)
   {
      stringstream ss(line);
      int l_len = n;

      for(int j = 0; j < l_len; j++)
      {
         ss >> a[l_len * i + j];
         cout << a[l_len * i + j] << " ";
      }

      cout << endl;

      //     cout << "incrementing i to " << i << endl;
      i++;
      
   }

   cout << "finished reading file" << endl;;
}

//Life function
void life(int *a, unsigned int n, unsigned int iter, int *livecount)
{
  //ARRAY HAS SIZE N*N
  
  cout << "life function running" << endl;
  int livecounter = 0;
 
  //loop iters out here
  for (int iteration = 0; iteration < iter; iteration++){
    cout << "iteration is " << iteration +1<< endl;;

    //copy array into a temp array for modification
      int temp[n*n];
      a[0:n:1] = temp[0:n:1];
     
    
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
	int counter = 0;
	int north = (i-1) % n;
	int south = (i+1) % n;
	int west = (j-1) % n;
	int east = (j+1) % n;
      
	//count the neighbors counterclockwise from north
	counter = a[north + north*j] + a[north + north*west] + a[i + i*west] + a[south + south*west]
	  + a[south + south*j] + a[south + south*east] + a[i + i*east] + a[north+ north*east];

	if(counter > 3 || counter < 2){
	  temp[i + i*j] = 0;
	} //dies
	if(counter == 2){
	  temp[i + i*j] = a[i + i*j];
	} //nothing
	if(counter == 3){
	  temp[i + i*j] = 1;
	} //birth
      }
    }

  //array is now updated
    temp[0:n:1] = a[0:n:1];
    //copy(temp, a);

    #if DEBUG == 1
    if (iteration % (iter/10) == 0){
      int total_lives = countlive(a, n);
      livecount[livecounter] = total_lives;
      livecounter++;
    }
    #endif
      
  }

}
