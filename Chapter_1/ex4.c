#include<stdio.h>

int main()
{
   float celcius,fahr;
   int lower =0,upper=300,step=20;
   fahr = lower;
    printf("Celcius\tFarenHeit\n");
   while(celcius<=upper){
       fahr = (9.0/5.0 * celcius) + 32 ;
       printf("%3.0f\t\t%6.1f\n",celcius,fahr);
       celcius = celcius + step;
   }
   
 
   return 0;
}
