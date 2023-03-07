/* Calculate FV of the compound interest acumulated by a given principal value after the passage of N time periods
the discrete compounded interest rate: V = P(1+R)^N. P: present value; V:future value; R: interest rate;
N: the number of periods.FV of the continuous interest rate: V = Pe^(RN) which is the limit of V = P(1+R/t)^(Nt),t->0
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
  double rate, pv,fv_d,fv_c;
  int np;
  char c;
  rate = pv = 0.0;
  np = 0;
  
 printf("Enter the interest rate R of the period = ");
 scanf("%lf",&rate); //"l" is for conversion to double
 printf("Enter the present value P = ");
 scanf("%lf",&pv);
 printf("Enter the number of periods = ");
 scanf("%d",&np);

  fv_d = pv * pow((1 + rate), np);
  fv_c = pv * exp(rate * np);

  printf("future value for multiple period compounding is %.2f\n",fv_d);
  printf("future value for continous compounding is %.2f\n",fv_c);
  return 0;
}
