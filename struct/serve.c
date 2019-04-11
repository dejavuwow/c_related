/*
/*
Simple HTTP Web Server 
By : Kartik Kumar Perisetla(kartik.peri@gmail.com)
hosted for http://kperisetla.blogspot.com
*/
 
//for windows 
#include<winsock2.h>
 
// for POSIX based systems use- #include<sock.h> in place of #include<winsock2.h>
 
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#pragma comment(lib, "Ws2_32.lib")
 
 
//function specific for Windows-to be called before invoking call to socket()
int init()
{
 WSADATA wsaData;
 int iResult;
 
 // Initialize Winsock
 iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
 if (iResult != 0) 
 {
  printf("WSAStartup failed: %d\n", iResult);
  return 1;
 }
 
}
 
//function specific for windows-to be called after all socket communication is complete
void clean()
{
 WSACleanup();
}
 
 
void server()
{
  
        int sock, connected, bytes_recieved , true = 1;  
        char send_data [1024] , recv_data[1024];       
 
        struct sockaddr_in server_addr,client_addr;    
        int sin_size;
         
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }
 
        if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&true,sizeof(int)) == -1) {
            perror("Setsockopt");
            exit(1);
        }
         
        server_addr.sin_family = AF_INET;         
        server_addr.sin_port = htons(8080);     
        server_addr.sin_addr.s_addr = INADDR_ANY; 
        //bzero(&(server_addr.sin_zero),8); --This is for POSIX based systems
  memset(&(server_addr.sin_zero),0,8);
        if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))== -1) 
    {
            perror("Unable to bind");
            exit(1);
        }
 
        if (listen(sock, 5) == -1) 
  {
            perror("Listen");
            exit(1);
        }
   
  printf("\n\nMyHTTPServer waiting on port 8080");
        fflush(stdout);
         
 
            sin_size = sizeof(struct sockaddr_in);
 
            connected = accept(sock, (struct sockaddr *)&client_addr,&sin_size);
 
           // printf("\n I got a connection from (%s , %d)",
                //   inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
 
   char kk[9999];
   recv(connected,kk,sizeof(kk),0);
   printf("\n Received:%s",kk); 
    
   char xx[9999];
   strcpy(xx,"HTTP/1.1 200 OK\nContent-length: 47\nContent-Type: text/html\n\n<html><body><H1>Hello Kartik</H1></body></html>");
    
   int c=send(connected,&xx,sizeof(xx),0);
   printf("\nSTATUS:%d",c);
      
   printf("\nSent : %s\n",xx);
    
            close(sock);
   WSACleanup();
}
int main()
{
 
 
 while(1)
 {
  init();
  server();
  clean();
 }
   
    return 0;
}
