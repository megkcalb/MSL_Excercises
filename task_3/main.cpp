#include <iostream>
#include "cstr.h"

int main(int argc, const char * argv[]){

    cstr mystring;
    std::cout<<mystring.len();
    cstr mystring1 = "elango";
    std::cout<<std::endl<<mystring1.len();
    cstr mystring2("meg");

    std::cout<<std::endl<<mystring2.len();
    mystring1 = mystring2;
   // cstr mystring3 ;
    cstr mystring3;
    cstr mystring4;
    mystring3 = mystring1 + mystring2;
    mystring4 = "simplified ";
    std::cout<<std::endl<<" index of e in meg : " << mystring1.index_of('e') << std::endl;
   //std::cout <<  " appended : " << mystring3.str_source << std::endl;

    std::cout << " appended length : " << std::endl << mystring3.len() << std::endl;
    std::cout << " substring : " << mystring4.substr(2,5) << std::endl;
    return 0;
}
