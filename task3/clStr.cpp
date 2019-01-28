#include "clStr.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

char* stringop::strapp(char *str1, char *str2)
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
      for(int i = 0; str[i] != '\0'; i++){

           if( str[i] == ch )
                   return i ;
          }
      return -1;
}


int stringop::len(char *str){

      int i = 0;
      for(i=0;str[i] != '\0'; i++);
            return i;
}

char* stringop::substr1(char *str,int start, int end ){

        char* op1 = (char*) malloc( (end - start +2)*sizeof(char)) ;
        //char* op1 = (char*) malloc(end) ;
        int i , j ;
        for( i = start ,  j = 0; i <= end ; i++,j++){

                  op1[j] = str[i];
         }
        op1[j] = '\0';

        return op1;
}


