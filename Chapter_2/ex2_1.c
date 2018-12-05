#include<stdio.h>
#include<limits.h>
int main(){
    printf("signed char : %d to %d\n",SCHAR_MIN,SCHAR_MAX);
    printf("signed short int : %d to %d\n",SHRT_MIN,SHRT_MAX);
    printf("signed int : %d to %d\n",INT_MIN,INT_MAX);
    printf("signed long : %d to %d\n",LONG_MIN,LONG_MAX);
    printf("unsigned char : %d to %d\n",UCHAR_MAX);
    printf("unsigned short int : %d to %d\n",USHRT_MAX);
    printf("unsigned long : %d to %d\n",ULONG_MAX);
      
    return 0;
    
}
