#include <iostream>

auto main() -> int
{
	int* ap = reinterpret_cast<int*>(0xdeadbeef);
        std::cout << ap << "\n";
	std::cout << *ap << "\n";

	return 0;    
}
