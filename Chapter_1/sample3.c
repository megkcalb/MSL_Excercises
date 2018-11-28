#include <stdio.h>

int main()
{
    double cc;
    for(cc=0;getchar()!=EOF;cc++)
    ;
    printf("Character count : %f",cc);
    return 0;
}
