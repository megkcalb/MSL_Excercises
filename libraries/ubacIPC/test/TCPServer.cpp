#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>

#include <ubacutils/IFHelper.h>

#include <ubacipc/EventFax.h>
#include <ubacipc/TCPServer.h>
#include <ubacipc/Thread.h>

using namespace UBACIPC;
EventFax *fax;

class NewTCPClient :
	public TCPClient
{
	public:
        
        int recvCount;

		NewTCPClient(int fd) : TCPClient(fd) { recvCount = 0; }

		void receive_data(void *ptr, size_t len)
		{
			string data( (char *)ptr, len);
			cout << data << endl;
			//this->sendData(data);
		}

		void unbind()
		{
//			cout << "Calling unbind" << endl;
                        closeConnection();
			abort();
 		}
};

class MyServer :
	public TCPServer,
	public Thread
{
	public:

		vector<NewTCPClient *> clients;

		MyServer(int port, int listen_q) : TCPServer(port, listen_q)
		{
			if( descriptor < 0 )
				exit(0);
		}

        ~MyServer() {}

       void createNewClient(int fd)
        {
            IFHelper helper;
            cout << "For pid = " << getpid() << " Creating a new client with fd = " << fd << endl;
            NewTCPClient *tcp_client;
            tcp_client = new NewTCPClient(fd);
            fax->addTCPClient( tcp_client );

            clients.push_back(tcp_client);

        }

       void sendInfo(string sData)
       {
//	         cout << " broad cast function  " << endl;
            vector<NewTCPClient *>::iterator iList = clients.begin();
            while( iList != clients.end() ) {
                (*iList)->asyncSendData( sData.c_str(), sData.length() );
                iList++;
            }
        }


       void run()
        {
	    cout << " server run " << endl;
            string sData = "Response";
            size_t nBytes = 0;
            while( clients.size() == 0 ) {}
            while(1) {
                stringstream s;
                s << sData  << endl;
                sendInfo( s.str() );
                nBytes += s.str().length();
                if( nBytes > 32){ //(200*1024) ) {
                    sleep(1);
                    nBytes = 0;
                    abort();
                }

            }
        }

};


MyServer *server = NULL;

int main()
{

    server = new MyServer(11006, 1000);
    fax = new EventFax();
    fax->addTCPServer(server);
    server->start(NULL);
    fax->run();
}
