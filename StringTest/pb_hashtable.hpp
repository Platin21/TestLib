#pragma once
#include "pb_types.hpp"
#include "pb_memmory.hpp"

namespace PB::HASH
{
	//#TODO Move this in define.hpp
#define PB_HASH_TABLE_SIZE 4127 
	
	struct bucket
	{
		ptr_c8 key;
		ptr_Void binding;
		bucket* next;
	};

	u32 hash(ptr_c8 s0);

	bucket* Bucket(ptr_c8 key, ptr_Void binding, bucket* next);

	Void insert(ptr_c8 key, ptr_Void binding);

	ptr_Void lookup(ptr_c8 key);

	Void pop(ptr_c8 key);

};


