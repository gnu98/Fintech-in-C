/* Calculate the PV for a series of future cash payment
   PV = FV / (1 + R)^N */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
  int i, np;
  double r, g, *cf, pv;

  if (argc == 3) {
    r = atof(argv[1]);
    np = atoi(argv[2]);
  }
  else {
    printf("Warning: command argument has some problem, both 1) interest rate and \
            2) number of period of payment are needed, try again\n");
    return -1;
  }

  if ((cf = malloc(np *sizeof(double))) == NULL) {
   printf("FatalError: Insufficient memory\n");
    return -2;
  }

  /* i = 0, it refers to the present */
  for (i = 0; i < np; i++) 
    if ((scanf("%lf",&cf[i])) == EOF)
      break;

  np = i;
  pv = 0;
  g = 1 + r;
  for (i = 0; i < np; i++)
  pv += cf[i] / pow(g,i);

  printf("The present value is %.2f\n", pv);
  free(cf);
  return 0;
}

  
  
