#include<stdio.h>
#define max 128
int main(void)
{
    int c,i,j;
    int chararr[max];
    
    for(i=0;i<max;++i)
        chararr[i] = 0;
    
    while((c=getchar())!=EOF)
        ++chararr[c];

    for(i=0;i<max;++i)
    {
        putchar(i);
                for(j=0;j<chararr[i];++j)
            putchar('*');
                putchar('\n');
    }
return 0;
}
