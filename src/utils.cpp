#include "utils.h"

std::string Utils::GetTimeString(bool date)
{
	char szBuffer[24];
	struct tm* pTimeinfo;
	time_t rawtime;

	time(&rawtime);
	pTimeinfo = localtime(&rawtime);

	if (date)
		strftime(szBuffer, 24, "%d/%m/%Y %X", pTimeinfo);
	else
		strftime(szBuffer, 24, "%X", pTimeinfo);

	//puts(szBuffer);

	std::string rtnStr(szBuffer);
	return rtnStr;
}

std::string Utils::GetTimeStamp()
{
	std::string rtnStr = "[" + Utils::GetTimeString() + "]";
	return rtnStr;
}