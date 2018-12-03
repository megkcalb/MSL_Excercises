#include<stdio.h>
#define MAXLINE 1000
int getline(char line[], int lim);
void reverseString(char chararr[]);
int main(){
    int len;
    char line[MAXLINE];
    while((len=getline(line,MAXLINE))>0){
        reverseString(line);
    //printf("%s", line);
    }
    
    return 0;
}
int getline(char s[],int lim){
    int c,i;
    for(i=0; i< lim - 1 && (c = getchar())!= EOF && c!= '\n'; ++i)
        s[i]=c;
        if(c=='\n'){
         s[i]=c;
         ++i;
    }
    s[i]='\0';    
    return i;
} 
void reverseString(char s[]){
    int temp=0,i,j;
    i=0;
    j=0;
    char rev[400];
    while(s[i]!='\n')
        ++i;
    //--i;
   // printf("%d",i);
    while(s[i]!='\0'){
        rev[j]=s[i];
        --i;
        ++j;
    }
    printf("%s",rev);
}
