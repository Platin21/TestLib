#include "pb_hashtable.hpp"
namespace PB::HASH
{
	i64 cstr_len(ptr_c8 c1)
	{
		i64 result = 0;
		while( *c1 != '\0' )
		{
			++c1;
			++result;
		}
		c1 -= result;
		ret result;
	}

	bl cstr_compare(ptr_c8 c1, ptr_c8 c2)
	{
		bl result = false;
		i64 l1 = cstr_len(c1), l2 = cstr_len(c2);
		if (l1 != l2) ret false;
		i64 iter = 0;
		while (*c1 == *c2)
		{
			++c1;
			++c2;
			++iter;
			if (iter == l1)
			{
				result = true; 
				break;
			}
		}
		c1 -= iter;
		c2 -= iter;

		ret result;
	}

	bucket* table[PB_HASH_TABLE_SIZE];

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
		table[index] = Bucket(key, binding, table[index]);
	}

	ptr_Void lookup(ptr_c8 key)
	{
		i32 index = hash(key) % PB_HASH_TABLE_SIZE;
		bucket* b;
		for (b = table[index]; b; b = b->next)
		{
			if (false == cstr_compare(b->key, key)) ret b->binding;
		}
		ret ptr_Void();
	};


	Void pop(ptr_c8 key)
	{
		int index = hash(key) % PB_HASH_TABLE_SIZE;
		auto ptr = table[index];
		table[index] = table[index]->next;
		RAM::clear(ptr);
	}
	bl clear()
	{
		for(i64 i = 0; i < PB_HASH_TABLE_SIZE; ++i )
		{
			if(table[i] != nullptr )
			{
				free(table[i]);
			}
		}
		ret true;
	}
};
