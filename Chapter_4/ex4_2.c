#include<stdio.h>
#include<ctype.h>
double atof(char[]);
int main(){

    char str[] = " 123.45e-6";
    printf("double precision value : %g",atof(str));
    return 0;
}
double atof(char str[]){
    double val,power;
    int exp,i,sign;
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
    val =  sign * val / power;

    if(str[i] == 'e ' || str[i] == 'E'){
        sign = (str[++i])? -1: 1;
        if (str[i] == ' - ' || str[i] == '+')
            ++i;
        for(exp = 0.0;isdigit(str[i]);++i)
            exp = 10.0 * val + (str[i] - 0);
        if(sign == 1)
            while(exp > 0)
             val *=10;
        else
            while(exp > 0)
             val /=10;
    }
    return val;

}


