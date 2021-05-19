#include <iostream>
#include <sys/types.h>
#include <unistd.h>

auto main() -> int 
{
	auto x = fork();
	if(x == 0)
       	{
		std::cout << "ppid: " << getppid() << "\n";
	} else {
		std::cout << "inny: " << x << "\n";
	}

	return 0;
}
