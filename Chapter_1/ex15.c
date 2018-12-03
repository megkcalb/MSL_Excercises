#include <stdio.h>
double ToFarenheit(double);
int main()
{
    double celcius;
    printf("Temperature conversion\n");
    printf("Enter the celcius value : \n");
    scanf("%lf",&celcius);
    printf("Farenheit value of %.2f's celcius  : %.2f",celcius,ToFarenheit(celcius));
    return 0;
}
double ToFarenheit(double celcius){
    double FarenheitValue;
    FarenheitValue = (celcius * 9 / 5) + 32;
    return FarenheitValue;
}
