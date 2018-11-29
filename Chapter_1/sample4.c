#include <stdio.h>
#define IN 1
#define OUT 0
int main()
{
    int c=0,nc=0,nw=0,state;
    for(c=0;(c=getchar())!=EOF;c++){
        //++;
        if(c==' '|| c=='\t' || c=='\n')
        state = OUT;
        else if(state == OUT){
            state = IN;
            ++nw;
        }
        nc++;
    }
    printf("\n Number of lines : %d\n Number of words : %d\n",nc,nw);
    return 0;
}
