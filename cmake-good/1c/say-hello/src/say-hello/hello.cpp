#include "hello.hpp"
#include <iostream>

void hello::say_hello() { std::cout << "Hello, world from say-hello version " << SAY_HELLO_VERSION << "\n"; }