
#include <ubacipc/CircularBuffer.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
cout << " Enter the size : " << endl;

    int size ;

    cin >> size;

    CircularBuffer *cobj = new CircularBuffer(size);

    cout << " Writing " << endl;

    cout << " enter the text to write : " << endl;

    string s ;

    cin >> s;

    int totWritten = cobj -> write ( s.c_str() , s.length());
    cout << " tot written to the buffer  " << totWritten << endl;

    cout << " Reading " << endl;

    char *readB = new char [100] ;

    int totRead = cobj ->read(readB);

    cout << " Total read " << totRead << endl << " Buffer --- > " << readB << endl;
    free(readB);
    
    cout << " Committing Read " << endl;

    cout << " enter the no of pos to commit : " << endl;
    
    int readC;

    cin >>readC;
    
    //read commit
    cobj -> readCommit(readC);

    cobj -> print();

    cout << " enter the new content : " << endl;
    
    cin >> s;

    //writing n pos of content to the buffer 
    cobj -> write(s.c_str(), s.length());

    cobj -> print();

    return 0;
 }
