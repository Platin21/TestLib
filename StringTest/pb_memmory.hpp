#pragma once
#include "pb_types.hpp"

//#TODO Platform depnedent
#include "Windows.h"

namespace PB::RAM
{
		ptr_Void allocte_zero(i64 size);
		ptr_Void allocate(i64 size);

		ptr_Void advance(ptr_c8& ptr, r_i64 bytes);
		ptr_Void regess(ptr_c8& ptr, r_i64 bytes);

		bl       clear(ptr_Void to_sclear);

		//#VAR Our Pool Pointer 
		extern ptr_Void POOL;

		//TODO Implement this !
		ptr_Void Pool();
		ptr_Void Pool_New(i64 size);
		ptr_Void Pool_New_zero(i64 size);

		//#INFO Clears the hohle memmory pool out !
		bl		 Pool_clear();
}
