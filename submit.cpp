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
   for (int j = 0; j < n; j++)
     a[j + i*n] = 0;
  }
 
  
 int glider[] = {1, 1, 1, 1, 0, 0, 0, 1, 0};
 int size = sizeof(glider)/sizeof(glider[0]);
 
 double dub_j = n/3.0;
 double dub_k = n/5.0;
 
 int i = 0;
 for(int j = round(dub_j); j < round(dub_j) + 3; j++){
   for(int k = round(dub_k); k < round(dub_k) + 3; k++){
     a[k + n*j] = glider[i];
     i++;
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
      temp[0:n*n:1] = a[0:n*n:1];
     
    
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
	int counter = 0;
	int north = (n+i-1) % n;
	int south = (i+1) % n;
	int west = (n+j-1) % n;
	int east = (j+1) % n;
      
	//count the neighbors counterclockwise from north
	counter = a[n*north+j] + a[n*north + west] + a[n*i + west] + a[n*south + west]
	  + a[n*south + j] + a[n*south + east] + a[n*i + east] + a[n*north + east];


	if(a[n*i + j] == 0 && counter == 3){
	  temp[n*i + j] = 1;
	  cout << "empty -> occupied by birth" << endl;
	} //birth
	
	if(a[n*i + j] == 1 && (counter == 2 || counter == 3)){
	  temp[n*i + j] = a[n*i + j];
	  cout << "occupied -> occupied still" << endl;
	} //nothing
		
	if(a[n*i + j] == 1 && counter > 3){
	  temp[n*i + j] = 0;
	  cout << "occupied -> death by overcrowd" << endl;
	} //dies of overcrowd
	
	if(a[n*i + j] == 1 && counter < 2){
	  temp[n*i + j] = 0;
	  cout << "occupied -> death by loneliness" << endl;
	  //dies of loneliness
	}
      }
    }

  //array is now updated
    a[0:n*n:1] = temp[0:n*n:1];

    //  #if DEBUG == 1
    //if (iteration % (iter/10) == 0){
    //  int total_lives = countlive(a, n);
    //  livecount[livecounter] = total_lives;
    //  livecounter++;
    // }
    //#endif
    
    cout << "current iteration's livecount is " << countlive(a,n) << endl;

  }

}
