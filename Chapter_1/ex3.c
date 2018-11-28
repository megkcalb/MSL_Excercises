#include<stdio.h>

int main()
{
   float celcius,fahr;
   int lower =0,upper=300,step=20;
   fahr = lower;
    printf("FahrenHeit\tCelcius\n");
   while(fahr<=upper){
       celcius = 5.0/9.0 * (fahr - 32) ;
       printf("%3.0f\t\t%6.1f\n",fahr,celcius);
       fahr = fahr + step;
   }
   return 0;
 }
