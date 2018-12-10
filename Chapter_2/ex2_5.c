#include<stdio.h>
int main(){
    char str1[]="meg";
    char str2[]="meg";
    int i,j,k;
    for(i=0;str1[i]!='\0';++i)
        for(j=0;str2[j]!='\0';++j)
            if(str1[i]==str2[j])
               printf("%d",i);
    return 0;
}
