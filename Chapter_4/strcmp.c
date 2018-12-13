#include<stdio.h>
int strcmp1(char*,char*);
int main(){

 char *str1 = "hayati";
 char *str2 = "hayati";

  printf("%d",strcmp1(str1,str2));
 return 0;
}
int strcmp1(char *str1,char *str2){

 for(; *str1 == *str2;str1++,str2++)
      if ( *str1=='\0')
      return 0;
  return *str1 - *str2;


}

