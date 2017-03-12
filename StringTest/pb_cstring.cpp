#include "pb_cstring.hpp"

i64 cstr_len(ptr_c8 c1)
{
	i64 ln = 0;
	while(*c1 != '\0')
	{
		ln++;
		c1++;
	}
	ret ln;
}
