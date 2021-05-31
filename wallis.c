#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    //printf("wallis called %f %f\n",M_PI,pi) ;
    if (!(fabs(pi - M_PI) > 0.15)) {
      //printf("wallis g %f\n",pi) ;
  printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
          abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
  
} 


float wallis_pi(int n)
{
float pi=1.0;
   int i;
    for(i=1;i<=n;i++) 
     {
      // printf("%d ",i);
       
        pi *=(4.0*i*i)/(4.0*i*i-1);
       }
if(n!=0)
 pi*=2.0; 
 else pi=0.0;
// printf("%f..\n",pi);
 
  return (pi);
}
    
    
