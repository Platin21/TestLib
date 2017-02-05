#include "pb_types.hpp"
#include "pb_string.hpp"
//#include "Windows.h"
//#include "pb_memmory.hpp"
#include "pb_hashtable.hpp"

//Don't use it is Error prone! but in this test it is okey
using namespace PB;

int main(int argc, char* argv[])
{
	/*
	char* t = "test";
	
	String t0 = String(argv[0],50);

	String t1(u8"aäbcdfghijklnmoöpqrsßtuüvwxyz");
	String t2 = right(t1,5);
	String t3 = left(t1,5);

	LPDWORD written{};
	SetConsoleOutputCP(CP_UTF8);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), t1.data, t1.lenght, written, NULL);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, written, NULL);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), t2.data, t2.lenght, written, NULL);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),"\n",1, written, NULL);
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), t3.data, t3.lenght, written, NULL);

	i8 t4 = 0;

	clear(t1);
	clear(t2);
	clear(t3);
	clear(t0);
	*/

	STR::String t1(u8"FileIsFile");

	bl test = HASH::cstr_compare("test", "test");
	
	HASH::insert("key1",&t1);

	auto t2 = (STR::String*)HASH::lookup("key1");

	clear(t1);
	HASH::clear();

	//RAM::allocate(40);
}
