#pragma once

class Log
{
public:
	static void Initialise();
	static void Print(const char*, ...);
	static void PrintDebug(const char*, const char*, int, const char*, ...);	
};