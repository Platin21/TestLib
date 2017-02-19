#include "pb_types.hpp"
#include "pb_string.hpp"
//#include "Windows.h"
//#include "pb_memmory.hpp"
#include "pb_hashtable.hpp"

//Don't use it is Error prone! but in this test it is okey
using namespace PB;
using namespace STR;

int main(int argc, char* argv[])
{
	
	RAM::Pool_Amount(PB_MEMORY_POOL_SIZE * 16);

	ptr_i64 num = (ptr_i64)RAM::Pool_New(sizeof(i64)*2);
	
	*num = 455;
	num++;
	*num = 66;

	num--;

	ptr_c8 cc = (ptr_c8)RAM::Pool_New(sizeof(c8) * 4);

	std::cout << *num++ << " " << *num << std::endl;

	

	String t1(u8"FileIsFile");

	clear(t1);


	RAM::Pool_clear();

	ret 0;
}
