 ///
 /// @file    InetAddress.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-26 10:54:09
 ///
 
#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__

#include <string>
#include <netinet/in.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;

namespace wd
{

class InetAddress
{
public:
	explicit InetAddress(uint16_t port);
	InetAddress(const std::string &ip,uint16_t port);
	InetAddress(const SAI &addr);

	void setSockAddrInet(const SAI &addr)
	{	addr_ = addr;	}
	const SAI *getSockAddrInet() const
	{	return &addr_;	}

	std::string toIp() const;
	uint16_t toPort() const;

private:
	SAI addr_;
};

}

#endif
