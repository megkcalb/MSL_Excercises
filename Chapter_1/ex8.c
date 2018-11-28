#include <stdio.h>

int main()
{
    int bc=0,tc=0,lc=0;
    int cc;
    while((cc=getchar())!=EOF){
        if(cc == 32) //blank space's ASCII code : 32
           bc++;
        else if(cc == 9) // ASCII for tab
           tc++;
        else if(cc == '\n') // new line 
           lc++;
    }
        printf("Line count : %d\n Blank Space : %d\nTab count : %d\n",lc,bc,tc);
    return 0;
    
}
