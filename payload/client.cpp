#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
using namespace std;

class client
{


        public :
                struct pack{

        	    int len;
                    char message[150]="";
                  }s1;
 
    
		int port;
                const char *serIp;
                int clientSd;
                int conn;
                
        	 void connectsoc(const char*sip,int p)
                 {
                         struct hostent* host = gethostbyname(sip);
                         port =p;

                         sockaddr_in saddr;
                         saddr.sin_family = AF_INET;
                         saddr.sin_addr.s_addr =inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
                         saddr.sin_port = htons(port);

                         clientSd = socket(AF_INET,SOCK_STREAM,0);
                         conn = connect(clientSd,(sockaddr*)&saddr,sizeof(saddr));
                         if(conn <0)
                         {
                                 cout<<"socket not connected.."<<endl;
                         }
                         cout<<"conncected to server.."<<endl;
                       			 
		      while(true){	 		
			
			 cout<<"enter the message:";
			 cin >> s1.message;
			 s1.len = strlen(s1.message);
                         char buffer[512];               
	
			 if(s1.len<10){
			         memcpy(buffer, "1",1);
			 }else if(s1.len >= 10 && s1.len <100){
				 memcpy(buffer,"2",1);
			 }else if(s1.len >=100){
				 memcpy(buffer,"3",1);
			 }

			 memcpy(buffer+1,(char*)&s1, sizeof(s1));
		        
			 cout << &buffer[0];
				 
			 cout << " sending buffer size : " << sizeof(s1);	 
                         
                         send(clientSd,(char*)&buffer,sizeof(buffer),0);

                         cout<<"sent"<<endl;
		      }
			 close(clientSd);
		      
		      }
};


int main(int argc, char *argv[])
{
        if(argc != 3)
          cout<<"One of the argument missing !"<<endl;

        client c;
        c.connectsoc(argv[1],atoi(argv[2]));
        return 0;
}
