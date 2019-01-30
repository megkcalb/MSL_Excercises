#include  <iostream>
#include "cstr.h"
#include <cstring>
using namespace std;

cstr::cstr()
: str_source(new char[1])
,str_len(0)
{
    str_source[0] = '\0';
}

cstr::cstr(const char * source)
{
    this->str_source = NULL;
    this->copy(source);
}


int cstr::copy(const char * source)
{
    char * temp_string;
    temp_string = this->str_source;

    this->str_len = (unsigned)strlen(source);
    this->str_source = new char[(this->str_len)+1];

    massive_copy(source, this->str_source, 0, this->str_len);

    delete[] temp_string;
    return 0;
}

int cstr::strlen(const char * source)
{
    int i;
    for(i=0;source[i]!='\0';i++);
    return i;
}

void cstr::massive_copy(const char * source, char * destination, int init_point, int string_length)
{
    memcpy(destination+init_point, source, string_length);
    destination[init_point+string_length]='\0';
}

int cstr::len()
{
    return this->str_len;
}

int cstr::index_of(char c)
{
	cout << "length : " << strlen(str_source) << endl;
	for ( unsigned int j = 0; j < (unsigned)strlen(str_source) ; j++ )
		if( str_source[j] == c ) return (int)j;
	return -1;
}

char* cstr::substr(int start , int end )
{
//	cout << "start : " << start << " end : " << end << "string length : " <<strlen(str_source);
	if((start > strlen(str_source)) || (end > strlen(str_source))){
                        cout << " index overflow " << endl;
                        exit(0);
        }
        char* op1 = new char[end - start +2];
        int i;

	for(i=0;start <= end; i++, start++)
                op1[i] = str_source[start];

 	op1[i] = '\0';

        return op1;
}

cstr operator+ ( cstr &str1, cstr &str2 ) 
{
	cstr * source2 = new cstr();

	int str1len = (unsigned)strlen(str1.str_source);
        int str2len = (unsigned)strlen(str2.str_source);
        
	int totlen = str1len + str2len ;

	source2 -> str_len = totlen;

	source2 -> str_source = new char[totlen+1];

	source2 -> massive_copy(str1.str_source, source2 -> str_source, 0 ,  str1len);
        source2 -> massive_copy(str2.str_source, source2 -> str_source, str1len ,  str2len);

	return *source2;
}

std::ostream& operator<< (std::ostream &out, const cstr & string)
{
    out << string.str_source;

    return out;
}

cstr:: ~cstr()
{
   delete[] str_source;
}



