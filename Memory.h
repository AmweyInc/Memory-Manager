#pragma once
#include <Windows.h>
#include <iostream>

class Memory {
private:
	DWORD id_process = NULL;
	HANDLE process_handle = nullptr;

public:
	Memory(const char* procces_name);

	DWORD GetProcessID();
	HANDLE GetProcessHandle();

	uintptr_t GetModuleAddress(const char* moduleName);

	template<typename T>
	T Read(uintptr_t address) {
		T value;
		ReadProcessMemory(this->process_handle, (LPCVOID)address, &value, sizeof(T), NULL);
		return value;
	}

	template<typename T>
	bool Write(uintptr_t address, T value) {
		return WriteProcessMemory(this->process_handle, (LPVOID)address, &value, sizeof(T), NULL);
	}
};