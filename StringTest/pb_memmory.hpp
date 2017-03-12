#pragma once
#include "pb_types.hpp"
#include "pb_defines.hpp"

//#TODO Remove Std!
#include  <cstdlib>

#ifdef __WINDOWS__
//#TODO Platform depnedent
#include "Windows.h"
#elif __MACOS__
//#TODO Replace this with darwin.h
#include <cstdlib>
#elif __LINUX__
#include <cstdlib>
#endif


namespace PB::RAM
{
		
		//#CLASS Pool
		//#INF Holds to Pointers begin_Pos wich should not be moved
		//#INF and act_Pos wich you can move
		struct Area
		{
			ptr_Void begin_Pos;
			ptr_c8   act_Pos;
		};

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


		//#INF Allocates the pool wich we can use later
		Void     Pool(Area& pool);

		//#INF Allocate a pool with an spesific amount
		Void     Pool_Amount(i64 size,Area& pool);

		//#INF Returns a New Pointer from the Pool
		ptr_Void Pool_New(i64 size,Area& pool);

		//# Retruns a new pointer and sets it to zero from the pool
		ptr_Void Pool_New_zero(i64 size,Area& pool);

		//#INFO Clears the hohle memmory pool out ! aka free's
		bl		 Pool_clear(Area& pool);


		
}
