#include<stdio.h>
#define MAXLINE 1000
int getline(char line[], int lim);
int removeExtra(char chararr[]);
int main(){
    int len;
    char line[MAXLINE];
    while((len=getline(line,MAXLINE))>0){
        if(removeExtra(line) > 0){
            printf("%s", line);
        }
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
int removeExtra(char s[]){
    int i;
    i=0;
    while(s[i]!='\n')
        ++i;
        
    --i;
    while(i>0 && ((s[i]==' ') || (s[i]=='\t')))
      --i;
    //for(i>0;((s[i]==' ') || (s[i]=='\t'));--i)
       
       //printf("%d",i);
    if(i>=0){
        ++i;
        s[i]=='\n';
        ++i;
        s[i]=='\0';
    }
    
    return i;       
     
}
