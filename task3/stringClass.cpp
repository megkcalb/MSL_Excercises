#include<iostream>

using namespace std;

//char *strapp(char*,char*);
//int indexof(char*, char);
//int len(char*);
//char *substr(char*, int , int);
class stringop
{
     public : 
          char *strapp(char*,char*);
          int indexof(char*, char);
          int len(char*);
          char *substr(char*, int , int);
};
int main(){
      
      stringop obj;
      char str1[] = "meg" ;
      char str2[] = "getup" ;
      
      cout << " appended string : " << obj.strapp(str1,str2) << endl;
      cout << " index : " <<  obj.indexof(str2,'i') << endl;
      cout << " length of the string is : " << obj.len(str2) << endl;
      //cout << str2[-1]<< endl;
      cout << " sub string : " << obj.substr(str2,1,4) << endl;
      return 0;
}

char stringop::*strapp(char *str1, char *str2)
{
    char *op= str1;

    while(*str1 != '\0')
    {
        str1++;
    }

    while(*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
    cout << op << endl;
    return op;
}

int stringop::indexof(char *str, char ch)
{
      for(int i = -1; str[i] != '\0'; i++){
   		   
	   if( str[i] == ch )
		   return i+1 ;
          }
      return -1;
}

int stringop::len(char *str){
         
	int l = 1;

	while( *str != '\0'){
	        str++;
		l++;
	}

	return l;
}

char stringop::*substr(char *str,int start, int end ){

        char* op1 = (char*) malloc( (end - start +1)*sizeof(char)) ;
//	char* op1 = (char*) malloc(end) ;
        int i , j ;
	for( i = start ,  j = 0; i <= end ; i++,j++){
                  
	          op1[j] = str[i];
         }
	op1[j] = '\0';
	      
        return op1;    
}
