#include "pb_types.hpp"
#include "pb_string.hpp"


//#include "pb_string.hpp"

namespace PB
{
    //Add Types Code Here
	ptr_Void memory_allocte_zero(i64 size)
	{
		c8* ptr = (c8*)malloc(size);
		for (i64 i = 0; i < size; ++i)
		{
			*ptr++ = 0;
		}
		ptr -= size;
		ret(void*)ptr;
	}

	//Allocate Memmory can return Zero!
	ptr_Void memory_allocte(i64 size)
	{
		ret malloc(size);
	}

	//TODO Use it in the Programm 
	//Moves a pointer by an spec amount of bytes
	ptr_Void advance_by(ptr_c8& ptr,r_i64 bytes)
	{
		if (bytes < 1)
		{
			PA::global::Error = PA::global::Reason::Can_Not_Advance_by_Zero;
			PA::global::error_exc();
			ret (ptr_Void)ptr;
		}
		ptr += bytes;
		ret (ptr_Void)ptr;
	}

	//TODO Use it in the Programm 
	//Moves back a pointer by an spec amount of bytes
	ptr_Void regess_by(ptr_c8& ptr,r_i64 bytes)
	{
		if(bytes > -1)
		{
			PA::global::Error = PA::global::Reason::Can_Not_Regress_by_One;
			PA::global::error_exc();
			ret ptr_Void();
		}
		ret ptr -= bytes;
	}

	ptr_Void Memmory_Pool() { ret ptr_Void(); };
	ptr_Void Memmory_Pool_New(i64 size) { return ptr_Void(); };
}

namespace PA
{
    namespace global {
        int Error = 0;

	    PB::bl error_check()
        {
            if (Error != 0)
            {
                ret false;
            }
            else
            {
                ret true;
            }
        }

        PB::str error_msg()
        {
            PB::str a = "Error" + std::to_string(Error);
            ret a;
        }

        void error_exc()
        {
            if (Error != 0)
            {
               exit(Error);
            }
        }

    }
}
