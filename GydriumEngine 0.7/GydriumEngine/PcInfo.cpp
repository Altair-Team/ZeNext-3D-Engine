#include "PcInfo.h"

PcInfo::PcInfo()
{
}

int PcInfo::getRamSize()
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	int memorySize = (float)statex.ullTotalPhys / (1024 * 1024 * 1024);
	return  memorySize;
}