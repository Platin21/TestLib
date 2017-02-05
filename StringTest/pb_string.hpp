#pragma once
#include "pb_types.hpp"
#include "pb_memmory.hpp"

//#INFO These are some headers of the Std Lib wich we need for conversion to std::string
#include <string>
#include <iostream>


//TODO Use allocater from pb_types.hpp and use pool!

namespace PB {

	enum Charackters
	{
		WhiteSpace,
		DoubleSlash,
		NewLine,
		Numbers,
		Alpha,
		Symbols,
		Operators,
		//#TODO Add more charackter sets!
	};

   struct String
   {
	   c8* data;
	   i64 lenght;
	   void* ptr;

	   String()
	   {
		   this->lenght = 0;
		   this->data = nullptr;
		   this->ptr = nullptr;
	   }

	   String(char* text)
	   {
		   i64 count{ 0 };
		   while (*text != '\0')
		   {
			   ++text;
			   ++count;
		   };
		    
		   this->ptr = memory_allocte_zero(count);
		   this->data = (c8*) this->ptr;

		   text -= count;

		   for (i64 i = 0; i < count; ++i)
		   {
			   *data++ = *text++;
		   }
		   this->lenght = count;
		   this->data -= this->lenght;
	   }

	   String(const char* text)
	   {
		   i64 count{ 0 };
		   while (*text != '\0')
		   {
			   ++text;
			   ++count;
		   };

		   this->ptr = memory_allocte_zero(count);
		   this->data = (c8*) this->ptr;

		   text -= count;

		   for (i64 i = 0; i < count; ++i)
		   {
			   *data++ = *text++;
		   }
		   this->lenght = count;
		   this->data -= this->lenght;
	   }

	   String(char* text,i64 size)
	   {
		   this->lenght = size;
		   this->ptr = memory_allocte_zero(size);
		   this->data = (c8*)this->ptr;
		   
	   	   for (i64 i = 0; i < size; ++i)
		   {
			   *data++ = *text++;
		   }
		   this->data -= this->lenght;
	   }

   };
	
   struct String_Cordinate
   {
	   i64 positon;
	   bl  isvalid;
   };

   struct String_Cordinate;

   String	   apppend_back(String& to_append_on,String to_append);
   String	   apppend_back(String& to_append_on,std::string to_append);
   String	   apppend_back(String& to_append_on,c8* to_append);
   String	   apppend_back(String& to_append_on,const c8* to_append);

   String	   append_front(String to_append_on,String to_append);
   String	   append_front(String& to_append_on,std::string to_append);
   String	   append_front(String& to_append_on,c8* to_append);
   String	   append_front(String& to_append_on,const c8* to_append);

   bl		   search(String searchin,String tosearch);
   bl		   search(String searchin,std::string tosearch);
   bl		   search(String searchin,c8* tosearch);
   bl		   search(String searchin,const c8* tosearch);

   i64		   search_first(String searchin,String tosearch);
   i64		   search_first(String searchin,std::string tosearch);
   i64		   search_first(String searchin,c8* tosearch);
   i64		   search_first(String searchin,const c8* tosearch);

   bl		   clear(String& to_clear );

   //@HINT in *.cpp file !
   //i64		   getCodePoints(String to_getPoints);



   std::string to_stdstr(String to_convert);
   c8*		   to_charptr(String to_convert);
   c16*		   to_wchar(String to_convert);

   String      copy(String to_copy);
   String	   substr(String for_substr,i64 start,i64 end);

   //@TODO Add this to the *.cpp file
   String	   left(String string,i64 count);
   String	   right(String string,i64 count);

   String      replace(String to_replacein, String to_replace);
   String      replace_first(String to_replacein, String to_replace);

   String      convert(c8* to_convert);
   String      convert(const c8* to_convert);
   String      convert(std::string to_convert);
   String      convert(c16* to_convert);


   String      remove(Charackters charackterset, String string);
}

