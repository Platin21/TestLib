#pragma once
#include <string>
#include <stdlib.h>

// ReSharper disable once CppUnusedIncludeDirective
#include "pb_defines.hpp"


//Build namespace
namespace PB
{
	typedef std::string str;
	//Int Datatypes
	//[
		using i8  = char;
		using i16 = short;
		using i32 = int;
		using i64 = long long;

		using u8  = unsigned char;
		using u16 = unsigned short;
		using u32 = unsigned int;
		using u64 = unsigned long long;

		//Special Integer Values
		//Reference
		using r_i8 =  char&;
		using r_i16 = short&;
		using r_i32 = int&;
		using r_i64 = long long& ;
	
		//Pointer
		using ptr_i8  = char*;
		using ptr_i16 = short*;
		using ptr_i32 = int*;
		using ptr_i64 = long long*;
	//]

	//Charackter Datatypes whit using!
	//[
		using c8  = char;
		using c16 = char16_t;
		using c32 = char32_t;

		//Special Charackter Values
		//Reference
		using r_c8  = char&;
		using r_c16 = char16_t&;
		using r_c32 = char32_t&;

		//Pointer
		using ptr_c8  = char*;
		using ptr_c16 = char16_t*;
		using ptr_c32 = char32_t*;
	//]

	//Floating Point Values
	//[
		using f16  = float;
		using f32 =  double;
		using f64 =  long double;
		//Special Float Values
		//Refrence
		using r_f16 = float&;
		using r_f32 = double&;
		using r_f64 = long double&;
		//Pointer
		using ptr_f16 = float*;
		using ptr_f32 = double*;
		using ptr_f64 = long double*;
	//]

	//Void NILL
	//[
		using Void = void;
		using NILL = void;
		using nill = void;
		using null = void;
		//Special Voids
		//Refrence

		using ptr_Void = void*;
		using ptr_NILL = void*;
		using ptr_nill = void*;
		using ptr_null = void*;

	//]


	//File System Stuff
	typedef	FILE* fs;

	//Boolean Value
	//[
		using bl = bool;
	//]

	//Enums for Diffrent Things

	//Structs for Diffrent Things
	 // Maybe add some things to this Section?
	
}

//Alpha Namespace
namespace PA
{
	//Globals
	namespace global {
		//[Error Section

		//Error Code Int
		extern int Error;

		//Error Reasons
		enum Reason
		{
			File_Does_Not_Exist,
			Can_Not_Advance_by_Zero,
			Can_Not_Regress_by_One,
			//TODO: Add more Errors to the Enum
		};

		//Simple Error Checker
		PB::bl error_check();

		//Show Error Msg
		PB::str error_msg();

		//If Error KIll Programm
		void error_exc();

		//]Error Section
	}
}
