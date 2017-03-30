 ///
 /// @file    testMylog.cc
 /// @author  lee(847394837@qq.com)
 /// @date    2017-02-27 17:49:12
 ///
 
#include "Mylog.h"
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

int main()
{
	LogWarn("warn msg");
	LogError("error msg");
	LogInfo("info msg");
	LogPath("test.log");//设置日志系统的存储路径，如果之前被设置过，则失败并记入日志
	LogDebug("debug msg");

	return 0;
}
