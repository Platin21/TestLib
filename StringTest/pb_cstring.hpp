#pragma once
#include "pb_types.hpp"

using namespace PB;

//#FUNC
//#PARAM c1 : ptr_c8 
i64 cstr_len(ptr_c8 c1);

//#TODO Move this to pb_cstring.hpp
bl cstr_compare(ptr_c8 c1, ptr_c8 c2);