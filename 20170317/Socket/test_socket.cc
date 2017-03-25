 ///
 /// @file    test_socket.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-25 17:45:33
 ///
 
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char const *argv[])
{
	wd::InetAddress addr("192.168.175.128",9999);
	wd::Socket sock;
	sock.ready(addr);

	int peerfd = sock.accept();

	wd::SocketIO sio(peerfd);
	char recvbuf[1024] = {0};
	while(1)
	{
		int ret = sio.readline(recvbuf,sizeof(recvbuf));
		if(ret != 0)
		{
			printf("receive msg : %s",recvbuf);
			sleep(1);
			sio.writen(recvbuf,strlen(recvbuf));
		}else{
			break;
		}
	}
	sock.shutdownWrite();
	return 0;
}
