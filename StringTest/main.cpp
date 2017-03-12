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
	RAM::Area pool;
	RAM::Pool(pool);
	//ptr_i64 num = (ptr_i64)RAM::Pool_New(8,pool);
	
	//*num = 455;
	//num++;
	//*num = 66;

	//num--;

	//ptr_c8 cc = (ptr_c8)RAM::Pool_New(sizeof(c8) * 4,pool);

	//std::cout << *num++ << " " << *num << std::endl;

	

	String t1(u8"FileIsFile");
	String t2(u8"rtzwsFile");

	clear(t1);
	clear(t2);
	RAM::Pool_clear(pool);

	ret 0;
}
