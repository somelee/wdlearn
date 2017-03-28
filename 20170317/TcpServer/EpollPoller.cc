 ///
 /// @file    EpollPoller.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-27 17:16:37
 ///
 
#include "EpollPoller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
using std::endl;
using std::cout;

namespace 
{

int createEpollFd()
{
	int epollfd = ::epoll_create1(0);
	if(epollfd == -1)
	{
		perror("create epoll fd error");
	}
	return epollfd;
}

void addEpollReadFd(int epollfd,int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	if(epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev) == -1)
	{
		perror("add epoll fd error");
	}
}

void delEpollReadFd(int epollfd,int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	if(epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev) == -1)
	{
		perror("del epoll fd error");
	}
}

int acceptConnFd(int listenfd)
{
	int peerfd = ::accept(listenfd,NULL,NULL);
	if(peerfd == -1)
	{
		perror("accept conn fd");
	}
	return peerfd;
}

ssize_t recvPeek(int sockfd,void *buf,size_t len)
{
	int nread;
	do{
		nread = ::recv(sockfd,buf,len,MSG_PEEK);
	}while (nread == -1 && errno == EINTR);

	return nread;
}

bool isConnectionClosed(int sockfd)
{
	char buf[1024];
	ssize_t nread = recvPeek(sockfd,buf,sizeof(buf));
	if(nread == -1)
	{
		perror("recvPeek");
	}

	return (nread == 0);
}
}//end of namespace ::

namespace wd
{

EpollPoller::EpollPoller(int listenfd)
:epollfd_(createEpollFd())
,listenfd_(listenfd)
,isLooping_(false)
,events_(1024)
{
	addEpollReadFd(epollfd_,listenfd);
}

EpollPoller::~EpollPoller()
{
	::close(epollfd_);
}

void EpollPoller::waitEpollFd()
{
	int nready;
	do{
		nready = ::epoll_wait(epollfd_,&(*events_.begin()),static_cast<int>(events_.size()),5000);
	}while (nready == -1 && errno == EINTR);

	if(nready == -1)
	{
		perror("epoll wait error");
		exit(EXIT_FAILURE);
	}else if(nready == 0){
		printf("epoll timeout.\n");
	}else
	{
		if(nready == static_cast<int>(events_.size()))
		{
			events_.resize(events_.size() * 2);
		}

		for(int ix = 0; ix != nready;++ix)
		{
			if(events_[ix].data.fd == listenfd_)
			{
				if(events_[ix].events & EPOLLIN)
					handleConnection();
				cout << "connect sucess" << endl;
			}else{
				if(events_[ix].events & EPOLLIN)
					handleMessage(events_[ix].data.fd);
			}
		}
	}
}

void EpollPoller::handleConnection()
{
	int peerfd = acceptConnFd(listenfd_);
	addEpollReadFd(epollfd_,peerfd);

	std::pair<ConnectionList::iterator,bool> ret;

	TcpConnectionPtr conn(new TcpConnection(peerfd));
	conn->setConnectCallback(onConnectCallback_);
	conn->setMessageCallback(onMessageCallback_);
	conn->setCloseCallback(onCloseCallback_);

	ret = lists_.insert(std::make_pair(peerfd,conn));
	assert(ret.second == true);
	(void)ret;

	conn->handleConnectCallback();
}

void EpollPoller::handleMessage(int peerfd)
{
	bool isClosed = isConnectionClosed(peerfd);
	ConnectionList::iterator it = lists_.find(peerfd);
	assert(it != lists_.end());

	if(isClosed)
	{
		it->second->handleCloseCallback();
		delEpollReadFd(epollfd_,peerfd);
		lists_.erase(it);
	}else{
		it->second->handleMessageCallback();
	}
}

void EpollPoller::loop()
{
	isLooping_ = true;

	while(isLooping_)
	{
		waitEpollFd();
	}

	printf("Loop quit safely\n");
}

void EpollPoller::unloop()
{
	isLooping_ = false;
}


}
