#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom();

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}

float mc_pi(int n){
  int inside=0, count=0;
 for(int i=0;i<n;i++)
 {
  float x = rand()%(10000-0+1);
  x/=10000;
  float y= rand()%(10000-0+1);
  y/=10000;
  float z = x*x+y*y;
  z= pow(z,0.5);
  //printf("%f %f %f\n",x,y,z);
  if(z<=1)
  { 
    inside++;
    }
    
    count++;
  }
  //printf("%d %d\n",inside ,count);
  float pi = (float)(4*inside)/count;
  return pi;
  
  
}




    
