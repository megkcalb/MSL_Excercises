#include <stdio.h>

int main()
{
    double cc;
    int lc=0;
    for(cc=0;getchar()!=EOF;cc++)
        if(cc == '\n')
            lc++;
    ;
    printf("Character count : %f\n Line count : %d",cc,lc+1);
    return 0;
    
}
