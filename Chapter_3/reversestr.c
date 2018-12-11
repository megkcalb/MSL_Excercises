#include<stdio.h>
void reverse(char[]);
int main(){
	char str[]="simplified";
    reverse(str);
    printf("%s",str);
    return 0;
}
void reverse(char str[]){
	int i,temp=0,j;
	for(i=0,j=strlen(str)-1;i<j;++i,--j){
		temp=str[i];
		str[i]=str[j];
		str[j] = temp;
		}
 
}
