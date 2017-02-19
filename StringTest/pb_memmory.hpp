#pragma once
#include "pb_types.hpp"
#include "pb_defines.h"

//#TODO Platform depnedent
#include "Windows.h"

namespace PB::RAM
{
		
		//#INF Allocates ram on the heap an zeros it out
		ptr_Void allocte_zero(i64 size);

		//#INF Allocates Ram on the Heap 
		ptr_Void allocate(i64 size);

		//#INF Moves a Pointer by bytes amount forward
		ptr_Void advance(ptr_c8& ptr, r_i64 bytes);

		//#INF Moves a Pointer by bytes amount in backward
		ptr_Void regess(ptr_c8& ptr, r_i64 bytes);

	    //#INF Free's a pointer allocated with: allocate || allocate_zero
		bl       clear(ptr_Void to_sclear);

		//#VAR Our pool pointer 
		extern ptr_Void POOL;

		//#VAR Actual pool pointer 
		extern ptr_c8   POOL_ACTUAL_POS;

		//#INF Allocates the pool wich we can use later
		Void Pool();

		//#INF Allocate a pool with an spesific amount
		Void Pool_Amount(i64 size);

		//#INF Returns a New Pointer from the Pool
		ptr_Void Pool_New(i64 size);

		//# Retruns a new pointer and sets it to zero from the pool
		ptr_Void Pool_New_zero(i64 size);

		//#INFO Clears the hohle memmory pool out ! aka free's
		bl		 Pool_clear();
}
