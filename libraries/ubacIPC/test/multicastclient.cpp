#include<ubacipc/MultiCastClient.h>
#include<iostream>
#include<string>
using namespace std;
class mclient:public MultiCastClient
{
        public:

        string ip;
        int port;
        mclient(string ip,int port) : MultiCastClient(ip,port)
        {
        }
        void receive_data( void *data, size_t len)
        {
           cout << " data " << (char*) data  << endl << " length : " << len << endl;

        }
};
int main()
{
        string ip = "239.2.2.20";
        int port = 7708;
        MultiCastClient *mlt = new mclient(ip,port);
        mlt->start();
        return 0;
}
