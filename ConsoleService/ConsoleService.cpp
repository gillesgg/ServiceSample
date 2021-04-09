// ConsoleService.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	CoInitialize(0L);
	try
	{
		ATLServiceLib::ICalcPtr spCalc(__uuidof(ATLServiceLib::Calc));
		if (spCalc == nullptr)
		{
			printf("CoCreateInstance failed GetLastError=%d", GetLastError());
			return -1;
		}
		auto result = spCalc->Add(10, 10);
		printf("result = %d \n", result);
	}
	catch (_com_error& e)
	{
		wprintf(L"error = %d", e.Error());
	}
}


