#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <Windows.h>

namespace Utils {
	std::string GetTimeString(bool date = false);
	std::string GetTimeStamp();
};