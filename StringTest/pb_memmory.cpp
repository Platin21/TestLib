#include  "pb_memmory.hpp"

namespace PB::RAM
{
	//#TODO Add Memmory Stuff here
	ptr_Void POOL;
	ptr_c8   POOL_ACTUAL_POS;


	//#FUNC
	//#INF Zeros the heap memmory out
	//#PARAM i64 : size , 17 ,  The Size in bytes that should be allocted on the heap
	//#RET Ptr : A pointer to the allocated heap 
	//#SCOPE PB::RAM
	ptr_Void allocte_zero(i64 size)
	{
		ret HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
	}

	//#FUNC
	//#PARAM i64 : size , 17 ,  The Size in bytes that should be allocted on the heap
	//#RET Ptr : A pointer to the allocated heap 
	//#SCOPE PB::RAM
	ptr_Void allocate(i64 size)
	{
		ret HeapAlloc(GetProcessHeap(), HEAP_NO_SERIALIZE, size);
	}

	//#FUNC
	//#PARAM Ptr : ptr , 27 , The pointer taht should be moved
	//#PARAM i64 : bytes , 28 , The Amounts of bytes it should move front
	//#RET Ptr : Moved Pointer 
	//#SCOPE PB::RAM
	ptr_Void advance(ptr_c8 & ptr, r_i64 bytes)
	{
		ret (ptr+=bytes);
	}

	//#FUNC
	//#PARAM Ptr : ptr , 27 , The pointer taht should be moved
	//#PARAM i64 : bytes , 28 , The Amounts of bytes it should move back
	//#RET Ptr : Moved Pointer 
	//#SCOPE PB::RAM
	ptr_Void regess(ptr_c8 & ptr, r_i64 bytes)
	{
		ret(ptr -= bytes);
	}

	//#FUNC
	//#PARAM Ptr : to_sclear , 32 , Is a Pointer Pointing to Heap Memmory
	//#RET bl : If the Heap was succesfully freed returns true
	bl clear(ptr_Void to_sclear)
	{
		HeapFree(GetProcessHeap(), HEAP_NO_SERIALIZE, to_sclear);
		ret true;
	}


	//#SECTION Pool Allocater Stuff
	
	//FUNC
	//#INFOTEXT 
	// - Allocates a new Pool keep in mind this overrides the old !
	// - The Pool Size is Predefined 
	//#ENDINFO
	//#SCOPE PB::RAM
	Void Pool()
	{
		POOL = allocate(PB_MEMORY_POOL_SIZE * PB_BYTE_SIZE);
		POOL_ACTUAL_POS = (ptr_c8)POOL;
	}

	//#FUNC
	//#PARAM i64 : size , 70 , Size of MB to Allocate
	//#SCOPE PB::RAM
	Void Pool_Amount(i64 size)
	{
		POOL = allocate(PB_MEMORY_POOL_SIZE * size);
		POOL_ACTUAL_POS = (ptr_c8)POOL;
	}

	//#FUNC
	//#INF A Simple Pool Allocater
	//#PARAM i64 : size , 65 , False : Determines the size of memmory needet
	//#RET Ptr : Returns an Void Pointer wich is in range of the Pool
	//#SCOPE PB::RAM
	ptr_Void Pool_New(i64 size)
	{
		ptr_c8 Pool_Last = POOL_ACTUAL_POS;
		ptr_c8 Pool_offset = (POOL_ACTUAL_POS += size);
		ptr_c8 Pool_End = (ptr_c8)POOL;
		Pool_End += PB_MEMORY_POOL_SIZE;

		if (Pool_offset >= Pool_End)
			exit(12);

		ret Pool_Last;
	}

	//#FUNC
	//#INF A Simple Pool Allocater wich zeros out the memmory 
	//#PARAM i64 : size , 65 , False : Determines the size of memmory needet
	//#RET Ptr : Returns an Void Pointer wich is in range of the Pool
	//#SCOPE PB::RAM
	ptr_Void Pool_New_zero(i64 size)
	{
		ptr_c8 Pool_Last = POOL_ACTUAL_POS;
		ptr_c8 Pool_offset = (POOL_ACTUAL_POS += size);
		ptr_c8 Pool_End = (ptr_c8)POOL;
		Pool_End += PB_MEMORY_POOL_SIZE;

		if (Pool_offset >= Pool_End)
			exit(12);

		for(i64 i = 0; i < size; ++i)
		{
			++Pool_Last;
			*Pool_Last = 0;
		}
		Pool_Last -= size;

		ret Pool_Last;
	}

	//#FUNC
	//#INF Clears the actual pool 
	//#RET bl : Returns a bool if deallocation is working!
	//#SCOPE PB::RAM
	bl Pool_clear()
	{
		clear(POOL);
		ret true;
	}

};