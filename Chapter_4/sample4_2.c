#include<stdio.h>
#include<ctype.h>
double atof(char[]);
int main(){

    char str[] = " simplified";
    printf("double precision value : %lf",atof(str));
    return 0;
}
double atof(char str[]){
    double val,power;
    int i,sign;
    for(i=0;isspace(str[i]);++i)
        ;
    sign = (str[i] == '-')? -1: 1;

    if(str[i]=='-' || str[i] == '+')
        ++i;
    for(val = 0.0;isdigit(str[i]);++i)
        val = 10.0 * val + (str[i] - 0);

    for(power = 0.0;isdigit(str[i]);++i){
        val  = 10.0 * val + (str[i] - 0);
        power *= 10.0;
    }
    return sign * val / power;

}


