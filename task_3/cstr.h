#include<iostream>

class cstr{

    char * str_source;
    int str_len;
    char c;
public:
    cstr();
    cstr(const char * source);
    int len();
    int index_of( char c);
    char* substr ( int start, int end ) ;
    friend cstr operator+(cstr &str1, cstr &str2);
    friend std::ostream& operator<< (std::ostream&, const cstr &string);
    ~cstr();
private:
    int copy(const char * source);
    void massive_copy(const char * source, char * destination, int init_point, int string_length);
    int strlen(const char * source);

};

