#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include <ubacipc/EventFax.h>
#include <ubacipc/Thread.h>

using namespace std;
using namespace UBACIPC;

class MyClient :
	public TCPClient,
	public Thread
{
	public:
		MyClient(string ip, int port) : TCPClient(ip, port) {}
		~MyClient() {}

		void receive_data(void *ptr, size_t len)
		{
		        cout << " Data " << (char * ) ptr << endl; 
	                usleep(2000);
                        abort();
		}
               
		void unbind()
		{
//			cout << "Calling unbind" << endl;
			abort();
		}
};

int main()
{
    EventFax fax;

    for(int i = 0; i < 1; i++)
    {

        MyClient * tcp_client;

        tcp_client = new MyClient("localhost", 11006);

        fax.addTCPClient(tcp_client);

    }


    fax.run();


}
