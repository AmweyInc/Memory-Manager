#include "header.h"
#include "Memory.h"

int main() {
	Memory memory = Memory("exlporer.exe");
	std::cout << "Process id: " << memory.GetProcessID() << std::endl;

	const uintptr_t client = memory.GetModuleAddress("module.dll");

	std::cout << "module.dll : " << "0x" << std::hex << client << std::dec << std::endl;
	int exp = memory.Read<uintptr_t>(0x421E119);
	std::cout << "exp: " << exp << std::endl;
	while (true)
	{
		
	}
}