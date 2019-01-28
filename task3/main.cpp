#include "clStr.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(){

      stringop obj;
      char str1[100] = "market" ;
      char str2[100] = "getup" ;
      char str3[100] = "simplified";

      cout << " appended string : " << obj.strapp(str1,str3) << endl;
      cout << " index : of g is :  " <<  obj.indexof(str2,'u') << endl;
      cout << " length of the string is : " << obj.len(str3) << endl;
      cout << " sub string : " << obj.substr1(str3,1,4) << endl;
      return 0;
}

