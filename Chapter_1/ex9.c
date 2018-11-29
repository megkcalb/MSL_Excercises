
#include <stdio.h>
#define nb 'a'
int main()
{
   int c=0,j=0,k=0,l=0;
   char strarr1[400],strarr2[400];
   gets(strarr1);
   puts(strarr1);
   while(strarr1[c]!='\0'){
       if(strarr1[c]==' '){
           int temp=c+1;
           if(strarr1[temp]!='\0'){
               while(strarr1[temp]==' '&& strarr1='\0'){
                if(strarr1[temp]=' '){
                    c++;
                }   
                temp++;
               }
           }
              
       }
       strarr2[l]=strarr1[c];
       c++;
       l++;
   }
    return 0;
}
