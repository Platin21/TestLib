#pragma once
#include "pb_types.hpp"
#include "pb_string.hpp"
#include "pb_memmory.hpp"

namespace PB::HASH
{
	i64 cstr_len(ptr_c8 c1);

	bl cstr_compare(ptr_c8 c1, ptr_c8 c2);
	
	//#TODO Move this in define.hpp
#define PB_HASH_TABLE_SIZE 4127 
	
	struct bucket
	{
		ptr_c8 key;
		ptr_Void binding;
		bucket* next;
		bucket* last;
	};

	u32 hash(ptr_c8 s0);

	bucket* Bucket(ptr_c8 key, ptr_Void binding, bucket* next);

	Void insert(ptr_c8 key, ptr_Void binding, bucket* table[]);

	ptr_Void lookup(ptr_c8 key, bucket* table[]);

	Void pop(ptr_c8 key, bucket* table[]);

};


