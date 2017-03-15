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
	LogDebug("debug msg");

	return 0;
}
