#include "pb_types.hpp"
#include "pb_string.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	char* t = "test";
	
	PB::String t1("Test String this is! צה ");

	auto t2 = PB::right(t1,4);
	auto t3 = PB::left(t1,5);

	PB::clear(t1);
	PB::clear(t2);
	PB::clear(t3);
}
