#ifndef __SOCKETCLI_H__
#define __SOCKETCLI_H__
#include<iostream>
#include<string.h>
#include<pthread>



using namespace std;


class SocketCli
{

public:
	SocketCli(){pthread_spin_init(&m_spin,1);}
	~SocketCli(){pthread_spin_destroy(&m_spin);}

	int SetTarget(int Family, int Type, int Protocol)
	{
		sockaddr_in cli;
		cli.sin_family = Family;
		cli.sin_addr.s_addr = IP;
		cli.sin_port = Port;

		int ret = 0;
		ret = socket(Family, Type,);
	
	}

	
	
	ConnectTo(){}
	
private:
	inline void LockUp(){pthread_spin_lock(&m_spin);}
	inline void LockDown(){pthread_spin_unlock(&m_spin);}


private:
	pthread_spinlock_t m_spin;

	int socketfd;

};




#endif












