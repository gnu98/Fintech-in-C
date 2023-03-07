/* Calculate the PV for a series of future cash payment
   PV = FV / (1 + R)^N */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
  int i, N, AN;
  double rate, *cf, *ccf, pv,rr;

  if (argc == 3) {
    rate = atof(argv[1]);
    N = atoi(argv[2]);
  }
  else {
    printf("Warning: command argument has some problem, both 1) interest rate and \
            2) number of period of payment are needed, try again\n");
    return -1;
  }

  if ((cf = malloc(N *sizeof(double))) == NULL) {
   printf("FatalError: Insufficient memory\n");
    return -2;
  }

  /* i = 0, it refers to the present */
  for (i = 0, ccf = cf; i < N && (scanf("%lf",ccf)) != EOF; i++, ccf++) //put 'scanf()' behind '&&',so that no more read
    ;
  AN = i;
  pv = 0;
  rr = 1 + rate;
  for (i = 0; i < AN; i++)
  pv += cf[i] / pow(rr,i);

  printf("The present value is %.2f\n", pv);
  free(cf);
  return 0;
}

  
  
