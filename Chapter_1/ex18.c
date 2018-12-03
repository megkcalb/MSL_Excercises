#include<stdio.h>
#define MAXLINE 1000
int getline(char line[], int max);
int removeExtra(char s[]);
int main(){
    char line[MAXLINE];
    while(getline(line,MAXLINE)>0){
        if(removeExtra(line) > 0){
            printf("%s", line);
        }
    }
    return 0;
}
int getline(char s[],int lim){
    int c,i,j;
    for(i=0; (c = getchar())!= EOF && c!= '\n'; ++i)
        if(i < lim - 2){
        s[j]=c;
        ++j;
        }
        if(c=='\n'){
         s[j]=c;
         ++j;
         ++i;
        }
    s[j]='\0';    
    return i;
} 
int removeExtra(char s[]){
    int i;
    while(s[i]!='\n')
        ++i;
    --i;
    while(i>=0 || ' ' || s[i]=='\t')
       --i;
    if(i>=0){
        ++i;
        s[i]=='\n';
        ++i;
        s[i]=='\0';
    }
    
    return i;       
     
}
