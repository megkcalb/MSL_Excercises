#include <stdio.h>
int main()
{
    int digit[10],nwhite=0, nothers=0;
    int i,c;
    for(i=0;i<10;i++){
        digit[i]=0;
    }
    while((c=getchar())!=EOF){
        if(c>='0' && c<= '9'){
            ++digit[c-'0'];
        }
        else if(c==' ' || c=='\t' || c=='\n'){
            ++nwhite;
        }
        else
            ++nothers;
    }
    printf("\n digits \n");
    for(i=0;i<10;i++){
        printf("%d",digit[i]);
    }
    printf("\n no of white spaces : %d\n others : %d",nwhite,nothers);
    return 0;
}
