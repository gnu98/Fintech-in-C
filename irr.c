/* Using Secant method to calculate the IRR for a series of future cash payment
   f(g) = cf0 + cf1/g^(-1) + ... + cfN/g^(-N) = 0 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double g, double c[], int np);
int main(int argc, char* argv[])
{
  int i, np, n;
  double epsilon, r, g, g1, g2, g3, fg1,fg2,fg3, *cf;

  if (argc == 3) {
    epsilon = atof(argv[1]);
    np = atoi(argv[2]);
  }
  else {
    printf("Warning: command argument has some problem,1)tolerance and \
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
  g1 = 1.005;
  g2 = 1.01;
  g3 = 0;
  fg1 = f(g1,cf,np);
  fg2 = f(g2,cf,np);
  printf("Secant-method:(g1,fg1)=(%.4f,%.4f), (g2,fg2)=(%.4f,%.4f), epsilon=%.5f. start iterating ...\n",g1,fg1,g2,fg2,epsilon);
  n = 0;
  do {
    g = g3;
    g3 = ((g1*fg2)-(g2*fg1))/(fg2-fg1);
    fg3 = f(g3,cf,np);
    printf("%d)\t%6.3f | %6.3f | %6.3f | %6.3f\n", n, g1,g2,g3,fg3);
    g1 = g2;
    fg1 = fg2;
    g2 = g3;
    fg2 = fg3;
    n++;	   
  } while (fabs(g - g3) > epsilon || fabs(fg3) > epsilon);
  
	  
  
  r = (g3 -1) * 100;
  printf("The IRR is %.2f%%\n", r);
  free(cf);
  return 0;
}

double f(double g, double c[], int np)
{
  int i;
  double polynomial;

  for (i = 0; i < np; i++)
    polynomial += c[i] / pow(g,i);

  return polynomial;
}

    
  
