
#include <ubacipc/SharedMemory.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

        int sID, sKey, Size;
        sKey = 1897;
        Size = 1;
        SharedMemory s;
        sID = s.initSharedMemory(sKey,Size,false);
        cout << " Sid : " << sID << endl;
        char *str;
        str = (char *) s.attachSharedMemory(sID, false);
        char c ;
        c = *str;
        while(1)
        {
        if(c != *str)
        {

            cout << "Key detected is :: " << str << endl;
            s.detachSharedMemory(str);
            s.destroySharedMemory(sID);
            exit(1);
           }
         }

        return 0;
}
