#include "Memory.h"
#include <TlHelp32.h>
#include <comdef.h> 

Memory::Memory(const char* procces_name)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	while (Process32Next(snapShot, &entry))
	{
		_bstr_t b(entry.szExeFile);
		if (!strcmp(procces_name, b))
		{
			this->id_process = entry.th32ProcessID;
			this->process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->id_process);
			break;
		}
	}

	if (snapShot)
		CloseHandle(snapShot);
}

DWORD Memory::GetProcessID()
{
	return this->id_process;
}

HANDLE Memory::GetProcessHandle()
{
	return this->process_handle;
}

uintptr_t Memory::GetModuleAddress(const char* moduleName)
{
	MODULEENTRY32 entry;
	entry.dwSize = sizeof(MODULEENTRY32);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->id_process);

	uintptr_t result = 0;

	while (Module32Next(snapShot, &entry))
	{
		_bstr_t b(entry.szModule);
		if (!strcmp(moduleName, b))
		{
			result = reinterpret_cast<uintptr_t>(entry.modBaseAddr);
			break;
		}
	}

	if (snapShot)
		CloseHandle(snapShot);

	return result;
}
