#include "pb_hashtable.hpp"
namespace PB::HASH
{
	u32 hash(ptr_c8 s0)
	{
		u32 h = 0; ptr_c8 s;
		for(s=s0; *s; ++s)
			h = h * 65599 + *s;

		return h;
	}
	bucket* Bucket(ptr_c8 key, ptr_Void binding, bucket * next)
	{
		bucket* b = (bucket*)RAM::allocate(sizeof(*b));
		b->key = key;
		b->binding = binding;
		b->next = next;
		ret b;
	}
	Void insert(ptr_c8 key, ptr_Void binding)
	{
		i32 index = hash(key) % PB_HASH_TABLE_SIZE;

	}
	ptr_Void lookup(ptr_c8 key)
	{
		return ptr_Void();
	}
	Void pop(ptr_c8 key)
	{
		return Void();
	}
};
