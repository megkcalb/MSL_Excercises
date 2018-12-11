#include <stdio.h>
int main(){
	int nwhite=0,nother=0,ndigit[10];
	int c,i;
	
	for(i=0;i<10;i++)
	  ndigit[i] = 0;
	while((c=getchar())!=EOF){
		switch(c){
			case '0': case '1':	case '2': case '3':	case '4': case '5':	case '6': case '7':
			case '8': case '9': 
			ndigit[c - '0']++;
			break;
			case ' ':
			case '\t':
			case '\n':
			nwhite++;
			break;
			default:
			nother++;
		}
	}
		printf("\n Digits\n");
		for(i=0;i<10;++i)
		   printf("%d\t",ndigit[i]);
		printf("\n nwhite = %d\t nother = %d\n",nwhite,nother);
		
		return 0;

		}
	
