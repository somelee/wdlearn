 ///
 /// @file    InetAddress.h
 /// @author  lee(847394837@qq.com)
 /// @date    2017-03-25 14:35:20
 ///
 
#ifndef __WD_INET_ADDRESS_H__
#define __WD_INET_ADDRESS_H__

#include <string>
#include <netinet/in.h>

namespace wd
{

class InetAddress
{
public:
	explicit InetAddress(uint16_t port);
	InetAddress(const std::string &ip,uint16_t port);
	InetAddress(const struct sockaddr_in &addr);

	void setSockAddrInet(const struct sockaddr_in &addr)
	{	addr_ = addr;	}
	const struct sockaddr_in *getSockAddrInet() const
	{	return &addr_;	}

	std::string toIp() const;
	uint16_t toPort() const;

private:
	struct sockaddr_in addr_;
};

}

#endif
