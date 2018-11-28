#include<stdio.h>

int main()
{
   int celcius,fahr,lower =0,upper=300,step=20;
   fahr = lower;
   while(fahr<=upper){
       celcius = 5 * (fahr - 32) / 9;
       printf("%d\t%d\n",fahr,cel);
       fahr = fahr + step;
   }
   return 0;
}
