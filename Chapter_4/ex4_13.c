#include<stdio.h>
int reverse(char[],int,int);
int main(){
      char str[] = "simplified";
      reverse(str ,0, strlen(str)-1);
      printf("%s",str);
      return 0;
}
int reverse ( char v[],int i, int j){

  if(2 * i > j)	return 	0;
	char temp;
	temp = v[i];
	v[i] = v[j - i];
	v[j - i] = temp;

	reverse(v, ++i, j);
}
