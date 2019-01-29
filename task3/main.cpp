#include "clStr.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(){

      stringop obj;
      char str1[100] = "market" ;
      char str3[100] = "control";
      cout << " String 1 : " << str1 << endl << " String 2 : " << str3 << endl;
      cout << " appended string : " << obj.strapp(str1,str3) << endl;
      cout << " index : of c is :  " <<  obj.indexof(str3,'c') << endl;
      cout << " length of the string is : " << obj.len(str3) << endl;
      cout << " sub string : " << obj.substr1(str3,1,4) << endl;
      return 0;
}


