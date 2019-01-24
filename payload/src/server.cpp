#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
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

class server 
{
     public :
	     struct pack{

                 int len;
                 char message[150]="";
             }s2;

              
	      int port;
	      int ib ;
	      int count = 0;
	      int c = 0;
	      int g = 0;
              int msgrec;
              int socdes;
              int bindsock;
              int accsock;
	      int offset=0;
	      char mainbuf[1024];
	      char buffer[512];
	      char midbuff[512];
	       void connectsoc(int p)
               {
                 port = p;
                 sockaddr_in servSoc;
                 servSoc.sin_family = AF_INET;
                 servSoc.sin_addr.s_addr = htonl(INADDR_ANY);
                 servSoc.sin_port = htons(port);

                 //creating socket descriptor
                 socdes = socket(AF_INET,SOCK_STREAM,0);
                 if(socdes < 0)
                 {
                         cout<<"unable to create socket.."<<endl;
                         exit(0);
                 }


                 bindsock = bind(socdes, (struct sockaddr*)&servSoc,sizeof(servSoc));

                 if(bindsock < 0)
                 {
                         cout<<"unable to bind socket.."<<endl;
                         exit(0);
                 }

                 cout<<"socket connected and binded."<<endl;
                 listen(socdes,5);

                 sockaddr_in newSock;
                 socklen_t lensock = sizeof(newSock);

                 accsock = accept(socdes,(struct sockaddr*)&newSock,&lensock);
		 cout << " connnected with client " << endl;
                 if(accsock < 0)
                 {
                         cout<<"unable to accept the client."<<endl;
                         exit(1);
                 }
                         
                  memset(&mainbuf, 0 , sizeof(mainbuf));
		  memset(&midbuff, 0 , sizeof(midbuff));
	          while(true){
               
	             recv(accsock,(char*)&buffer,sizeof(buffer),0);
                     char len ;
                     memcpy(&len,&buffer[0],1);
		     ib = len - '0';
		     
		     
		     cout << " identifier byte "  << ib << endl;		     
	
		     cout << " received buffer size : " << sizeof(s2) << endl;
	
		     memcpy(&s2,&buffer[1],sizeof s2 );

                     cout << " identifier byte "  << ib << endl ;
		    
	             cout <<" message length : " << s2.len<<endl;
		  	                    
	             cout <<" message : " <<s2.message << endl;
		   
	
		    string man = to_string(s2.len);
		    char arr[10];
		    sprintf(arr,"%d",s2.len);
		    arr[10] = (char)(s2.len);
		    strcat(midbuff,arr);
		    strcat(midbuff,s2.message);
		    if( ib == 1 ){
                        
			    memset(mainbuf, 0 , sizeof(mainbuf));         
                            cout << endl <<  " offset >>>>>>>>>>>> " << offset << endl << endl;

			    memcpy(mainbuf,midbuff+offset,ib);
		
		 	    int lenf = atoi(mainbuf);
		
		 	    cout << " until length : " << lenf << endl <<  endl;
		        
		
		 	    memcpy(mainbuf+1,midbuff+offset+ib,lenf);
		
		 	    cout << " so main buffer here is : " << mainbuf << endl << endl;
		    	    count+=lenf;
			    cout << " lenf after some process : " << lenf << endl << " count after some process : " << count << endl << endl;
			    offset = ib + count + g;
			    cout << endl << " c value : " << g << endl << endl;
			    cout << endl <<  " offset >>>>>>>>>>>> " << offset << endl << endl;
                            g++;
		      
		    }
		    else if( ib == 2 ){
		         memset(mainbuf, 0 , sizeof(mainbuf));
                            cout << endl <<  " offset >>>>>>>>>>>> " << offset << endl << endl;

                            memcpy(mainbuf,midbuff+offset,ib);

                            int lenf = atoi(mainbuf);

                            cout << " until length : " << lenf << endl <<  endl;


                            memcpy(mainbuf+2,midbuff+offset+ib,lenf);

                            cout << " so main buffer here is : " << mainbuf << endl << endl;
                            count+=lenf;
                            cout << " lenf after some process : " << lenf << endl << " count after some process : " << count << endl << endl;
                            offset = ib + count + g;
                            cout << endl << " c value : " << g << endl << endl;
                            cout << endl <<  " offset >>>>>>>>>>>> " << offset << endl << endl;
                            //memset(midbuff, 0 , sizeof(midbuff));
                            
			    g+=2;
                           //memset(&mainbuf, 0 , sizeof(mainbuf));    
		     	    
		    }
		    else if(ib == 3){
			    cout << endl << "identifier byte is 3 now " << endl;
                            memset(mainbuf, 0 , sizeof(mainbuf));
                            cout << endl <<  " offset >>>>>>>>>>>> " << offset << endl << endl;

                            memcpy(mainbuf,midbuff+offset,ib);

                            int lenf = atoi(mainbuf);

                            cout << " until length : " << lenf << endl <<  endl;


                            memcpy(mainbuf+3,midbuff+offset+ib,lenf);

                            cout << " so main buffer here is : " << mainbuf << endl << endl;
                            count+=lenf;
                            cout << " lenf after some process : " << lenf << endl << " count after some process : " << count << endl << endl;
                            offset = ib + count + g;
                            cout << endl << " c value : " << g << endl << endl;
                            cout << endl <<  " offset >>>>>>>>>>>> " << offset << endl << endl;
                            //memset(midbuff, 0 , sizeof(midbuff));

                            g+=3;
                           //memset(&mainbuf, 0 , sizeof(mainbuf));    


		    }
		    cout << "appended buffer : " << midbuff << endl;
                  }	  
		    close(accsock);
		    close(socdes);
	       
	       } 


};


int main(int argc, char *argv[])
{
        if(argc != 2)
                cout<<"invalid input..."<<endl;

        server s;
        s.connectsoc(atoi(argv[1]));
        return 0;
}
