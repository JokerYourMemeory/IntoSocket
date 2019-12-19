#include<iostream>
#include<string.h>
#include<string>
#include<sys/socket.h>
#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>

using namespace std;
/*
#PRINT(arg,...) printf("[%s:%d]:[%s] %s\n", __FILE__, __LINE__, __func___)
*/

#define PRINT(fmt,...) printf(fmt,__VA_ARGS__)

int main()
{
	int ret = 0;
/*
	int sockfd = bind(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sockfd <0 )
	{
		cout<<""<<endl;
	}


	while(1)
	{




	}

*/
	int sockfd = 0;
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sockfd<0)
	{
		PRINT("socket err[%d][%s]\n",errno, strerror(errno));
		return 0;
	}


	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port  = htons(6666);
	//addr.sin_addr = 
	if(inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr)<=0)
	{
		PRINT("inet_pton err[%d][%s]\n",errno, strerror(errno));
		return 0;
	}

	if(connect(sockfd, (sockaddr *)&addr, sizeof(addr)) < 0 )
	{
		PRINT("connect err[%d][%s]\n",errno, strerror(errno));
		close(sockfd);
		return 0;	
	}

	PRINT("connect server success..\n");
	char msg[128]="adflkasodgnaosdfkkk";
	
	if(send(sockfd, msg, strlen(msg)) <0 )
	{
		PRINT("connect err[%d][%s]\n",errno, strerror(errno));
		close(sockfd);
		return 0;			
	}


	close(sockfd);

	return 0;
}
