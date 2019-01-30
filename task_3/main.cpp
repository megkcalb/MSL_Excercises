#include <iostream>
#include <cstr.h>

int main(int argc, const char * argv[]){

    cstr mystring;
    std::cout<<" length : " << mystring.len();
    cstr mystring1 = "market";
    std::cout<<std::endl << " length : " <<mystring1.len();
    cstr mystring2("simplified");

    std::cout<<std::endl<< " length : " <<mystring2.len();
   // mystring1 = mystring2;
   // cstr mystring3 ;


    cstr  mystring3 = mystring1 + mystring2;
    cstr  mystring4 = "simplified ";
    std::cout<<std::endl<<" index of 'p in simplified : " << mystring2.index_of('p') << std::endl;
    std::cout <<  " appended : " << mystring3 << std::endl;

    std::cout << " appended length : " << std::endl << mystring3.len() << std::endl;
    std::cout << " substring : " << mystring4.substr(2,5) << std::endl;
    return 0;
}
