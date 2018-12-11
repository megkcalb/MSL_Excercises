#include<stdio.h>
int main(){
	char str[100];
	int i=0,c;
	while((c=getchar())!=EOF)
		str[i++] = c;
	str[i] = "\n";
	printf("%d\t",atoi(str));
	return 0;
}
int a_toi(char s[])
{
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if ((s[i] == '-') || (s[i] == '+'))   // skip sign
    i++;
  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}
