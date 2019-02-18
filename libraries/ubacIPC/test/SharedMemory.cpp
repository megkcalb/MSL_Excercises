#include <ubacipc/SharedMemory.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int nSID, nKey, nSize;
    char *sRegionName;
    nKey = 1876 ;
    nSize = 5;
    SharedMemory s;
    nSID = s.initSharedMemory(nKey, nSize, true);
    cout << "Shared Memory ID :: " << nSID << endl;
    sRegionName = (char *) s.attachSharedMemory(nSID, true);
    char c;
    while(1)
    {
        cout << "Enter an input :: ";
        c=getchar();
        cout << endl;
        if(c == '\n')
        {
            c = getchar();
        }
        strncpy(sRegionName, &c, nSize);
        s.detachSharedMemory(sRegionName);
        s.destroySharedMemory(nSID);
        exit(1);

    }
    return 0;
}
