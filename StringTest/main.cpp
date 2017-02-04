#include "pb_types.hpp"
#include "pb_string.hpp"
#include <iostream>

//Don't use it is Error prone! but in this test it is okey
using namespace PB;

int main(int argc, char* argv[])
{
	char* t = "test";
	
	String t1("aäbcdfghijklnmoöpqrsßtuüvwxyz");
	String t2 = right(t1,4);
	String t3 = left(t1,4);

	i8 t4 = 0;

	clear(t1);
	clear(t2);
	clear(t3);
}
