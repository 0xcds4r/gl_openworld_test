#include "log.h"
#include "utils.h"

void Log::Initialise() {
	AllocConsole();
	freopen("conin$","r",stdin);
	freopen("conout$","w",stdout);
	freopen("conout$","w",stderr);
}

void Log::Print(const char* szFormat, ...) {
	char szBuffer[512+1];
	memset(szBuffer, 0, sizeof(szBuffer));

	va_list arg;
	va_start(arg, szFormat);
	vsnprintf(szBuffer, sizeof(szBuffer), szFormat, arg);
	va_end(arg);

	printf("%s %s\n", Utils::GetTimeStamp().c_str(), szBuffer);
}

void Log::PrintDebug(const char* path, const char* func, int line, const char* szFormat, ...)
{
	char szBuffer[512+1];
	memset(szBuffer, 0, sizeof(szBuffer));

	va_list arg;
	va_start(arg, szFormat);
	vsnprintf(szBuffer, sizeof(szBuffer), szFormat, arg);
	va_end(arg);

	Log::Print("%s (File: %s | Function: %s | Line: %d)", szBuffer, path, func, line);
}