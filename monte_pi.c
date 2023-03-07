/* Program to compute Pi using Monte Carlo methods */
/* points in Quarter Circle / points in Unit Rectangle = Area1/Area2 =(pi/4)/1 */
/* y(1.0)
   ************************
   *     *                *
   *         *            *
   *              *       *
   *                      *
   *                 *    *
   *                      *
   *                    * *
   *                     **
   *                      *   
   ************************x(1.0)
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define SEED 35791246

void main(int argc, char* argv)
{
  int inCirc, inRect, i;
  double x, y, r, pi;

  inCirc = 0; /* # of points in the 1st quadrant of unit circle */
  inRect = 0; /* # of points in the 1st quadrant of unit rectangle */
  x = y = r = pi = 0.0;
   
  printf("Enter the number of iterations used to estimate pi: ");
  scanf("%d",&inRect);

  srand(SEED);  /* initialize random numbers */
 
  for (i = 0; i < inRect; i++) {
    x = (double) rand() / RAND_MAX;
    y = (double) rand() / RAND_MAX;
    r = x * x + y * y; //r^2 <= 1
    if (r <= 1) //points in Quarter Circle
      inCirc++;
  }
  pi=(double) inCirc / inRect * 4;
  printf("# of trials= %d , estimate of pi is %g \n",inRect,pi);
}
