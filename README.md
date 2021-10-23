# Memory-Manager
Memory manager for hooking processes not protected by collisions and without blocking drivers for the handle.

To access the process go to Source.cpp file
and enter the name of the process from the task manager into the constructor of the memory variable in the fifth line, for example "explorer.exe", 

enter the module you need inside memory.GetModuleAddress ("module.dll"), 

after which you will receive information about the address of the module in memory.

To read a piece of memory, create a variable with the filling method

for example

memory.Read <uintptr_t> (0x421E119).

To edit memory, pass to the variable a method with the memory offset and information to be placed, 

for example: 

memory.Write <uintptr_t> (0x421E119,15).
