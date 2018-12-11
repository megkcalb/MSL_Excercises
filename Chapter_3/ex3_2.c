#include <stdio.h>
int main(){
	int i=0,j=0;
	char str1[40]= "\t indrajith\b";
	char str2[40];
	while(str1[i]!=EOF){
		switch(i){
			case '\n':
			str2[j++] = '\\';
            str2[j] = 'n';
            break;
            case '\t':
			str2[j++] = '\\';
            str2[j] = 't';
            break;
            case '\a':
			str2[j++] = '\\';
            str2[j] = 'a';
            break;
            case '\b':
			str2[j++] = '\\';
            str2[j] = 'b';
            break;
            default:
            str2[j]=str1[i];
            break;
		}
		++i;
		++j;
	}    
 str2[j] = str1[i];			
 return 0;
}
