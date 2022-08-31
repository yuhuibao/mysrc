#include "say-hello/hello.hpp"
#include <iostream>
int main()
{
	hello::say_hello();
	std::cout << "The say-hello library is version " << SAY_HELLO_VERSION << "\n";
}