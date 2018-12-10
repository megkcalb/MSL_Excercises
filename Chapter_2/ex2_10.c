#include <stdio.h>
#include<string.h>
int toLowerCase(char c);
int main()
{
   toLowerCase('a');
   toLowerCase('b');
   return 0;
}
int toLowerCase(char c){
     printf("inside ");
     printf("inside ");
     (c >='a' && c <='z')? printf("%c",c-32):printf("%c",c);
}
