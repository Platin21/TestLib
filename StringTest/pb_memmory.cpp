#include  "pb_memmory.hpp"

namespace PB::RAM
{
	//#TODO Add Memmory Stuff here
	ptr_Void POOL;

	ptr_Void allocte_zero(i64 size)
	{
		ret HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
	}

	ptr_Void allocate(i64 size)
	{
		ret HeapAlloc(GetProcessHeap(), 0, size);
	}

	ptr_Void advance(ptr_c8 & ptr, r_i64 bytes)
	{
		ret (ptr+=bytes);
	}

	ptr_Void regess(ptr_c8 & ptr, r_i64 bytes)
	{
		ret(ptr -= bytes);
	}

	ptr_Void Pool()
	{
		return ptr_Void();
	}

	ptr_Void Pool_New(i64 size)
	{
		return ptr_Void();
	}

	ptr_Void Pool_New_zero(i64 size)
	{
		return ptr_Void();
	}

	bl Pool_clear()
	{
		return bl();
	}

};