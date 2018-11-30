
#include <stdio.h>
#define IN 1
#define OUT 0
int main()
{
    int c,state,nw=0;
    while((c=getchar())!=EOF){
        if(c==' '|| c== '\n' || c=='\t'){
            printf("\n");
            state = OUT;
        }
        else if(state==OUT){
             ++nw;
             putchar(c);
        }
        }
    
    return 0;
}
