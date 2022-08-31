add_library(
	say-hello
	src/say-hello/hello.cpp 
	src/say-hello/hello.hpp)
target_include_directories(say-hello PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_definitions(say-hello INTERFACE SAY_HELLO_VERSION=4)