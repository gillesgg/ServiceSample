// ATLService.cpp : Implementation of WinMain
// install boost
// md vcpkg
// git clone https://github.com/microsoft/vcpkg
// .\vcpkg\bootstrap-vcpkg.bat
// .\vcpkg\vcpkg install boost:x64-windows
// .\vcpkg.exe export boost:x64-windows  --nuget --nuget-id=boost_x64_1_75 --nuget-version=1.75.0
//  Install-Package boost_x64_1_75 -Source "E:\DEV\DEV.SE\Service\vcpkg"

//Grpc
// .\vcpkg.exe install grpc:x64-windows
// .\vcpkg.exe install protobuf protobuf:x64-windows 
// .\vcpkg.exe install protobuf[zlib] protobuf[zlib]:x64-windows
// .\vcpkg.exe export grpc:x64-windows protobuf:x64-windows  --nuget  --nuget-id=grpc_x64_3_14 --nuget-version=3.14.0
// Install-Package grpc_x64_3_14 -Source "E:\DEV\DEV.SE\Service\vcpkg"

//CppSDK
//vcpkg install cpprestsdk:x64-windows
// .\vcpkg.exe export cpprestsdk:x64-windows --nuget  --nuget-id=cpprestsdk_x64_2_10_18 --nuget-version=9.03.0
//Install-Package cpprestsdk_x64_2_10_18 -Source "E:\DEV\DEV.SE\Service\vcpkg"

//Install-Package boost_cpprestsdk_x64 -Source "E:\DEV\DEV.SE\Service\vcpkg"

#include "pch.h"
#include "Logger.h"
#include "framework.h"
#include "resource.h"
#include "ATLService_i.h"

const TCHAR* const kLocalSystemSid = _T("S-1-5-18");

using namespace ATL;

#include <stdio.h>

class CATLServiceModule : public ATL::CAtlServiceModuleT< CATLServiceModule, IDS_SERVICENAME >
{
public :
	DECLARE_LIBID(LIBID_ATLServiceLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLSERVICE, "{23cb900e-dde5-44b4-9187-113b652b7ffc}")
	
	HRESULT InitializeSecurity() throw()
	{
		LOG_TRACE << __FUNCTION__;

		CoInitializeSecurity(0, -1, 0, 0, RPC_C_AUTHN_LEVEL_NONE,RPC_C_IMP_LEVEL_IDENTIFY, 0, 0, 0);
		return S_OK;
	}
	void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
	
	
};

CATLServiceModule _AtlModule;
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	LOG_TRACE << __FUNCTION__;
	return _AtlModule.WinMain(nShowCmd);
}
void CATLServiceModule::ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv)
{
	
	LOG_TRACE << __FUNCTION__;
	CAtlServiceModuleT<CATLServiceModule, 100>::ServiceMain(dwArgc, lpszArgv);
}