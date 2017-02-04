#include "pb_string.hpp"


namespace PB {

   //Keep Copying at least from bottom !
   // and its done! @NOTE Test if it works whit std::string !
   String	   apppend_back(String& to_append_on,String to_append)
   {
	  String string{};

	  string.ptr = memory_allocte_zero( to_append_on.lenght + to_append.lenght );
	  string.data = (c8*)string.ptr;
	  string.lenght = to_append_on.lenght + to_append.lenght;

	  for(i64 i = 0; i < to_append_on.lenght; ++i)
	  {
		 *string.data++ = *to_append_on.data++;
	  }

	  for(i64 i = 0; i < to_append.lenght; ++i)
	  {
		 *string.data++ = *to_append.data++;
	  }

	  ret string;
   }

   String	   apppend_back(String& to_append_on,std::string to_append)
			   {
				  String string{};
				  i64 count = to_append.size();

				  string.ptr = malloc( to_append_on.lenght + count );
				  string.data = (c8*)string.ptr;
				  string.lenght = to_append_on.lenght + count;

				  for(i64 i = 0; i  < to_append_on.lenght; ++i)
				  {
					 *string.data++ = *to_append_on.data++;
				  }

				  for(i64 i = 0; i < count; ++i)
				  {
				  *string.data++ = to_append[i];
				  }

				  ret string;
			   }
   String	   apppend_back(String& to_append_on,c8* to_append)
			   {
				  String string{};
				  i64 count{0};
				  while( *to_append != '\0' )
				  {
					 ++to_append;
					 ++count;
				  };

				  string.ptr    = malloc(count+to_append_on.lenght);
				  string.data	= (c8*)string.ptr;
				  string.lenght = count + to_append_on.lenght;

				  for(i64 i = 0; i < to_append_on.lenght; ++i)
				  {
					 *string.data++ = *to_append_on.data++;
				  }

				  for(i64 i = count; 0 < i; ++i)
				  {
					 *string.data++ = *to_append--;
				  }

				  ret string;
			   }
   String	   apppend_back(String& to_append_on,const c8* to_append)
			   {
				  String string{};
				  i64 count{0};
				  while( *to_append != '\0' )
				  {
					 ++to_append;
					 ++count;
				  };

				  string.ptr    = malloc(count+to_append_on.lenght);
				  string.data	= (c8*)string.ptr;
				  string.lenght = count + to_append_on.lenght;

				  for(i64 i = 0; i < to_append_on.lenght; ++i)
				  {
					 *string.data++ = *to_append_on.data++;
				  }

				  for(i64 i = count; 0 < i; ++i)
				  {
					 *string.data++ = *to_append--;
				  }

				  ret string;
			   }

   //This pice of work is done so let's go on!

   String	   append_front(String to_append_on, String to_append)
			   {
				  String string{};

				  string.ptr = malloc( to_append_on.lenght + to_append.lenght );
				  string.data = (c8*)string.ptr;
				  string.lenght = to_append_on.lenght + to_append.lenght;

				  for(i64 i = 0; i < to_append.lenght; ++i)
				  {
					 *string.data++ = *to_append.data++;
				  }

				  for(i64 i = 0; i < to_append_on.lenght; ++i)
				  {
					 *string.data++ = *to_append_on.data++;
				  }
				  ret string;
			   }
   String	   append_front(String& to_append_on,std::string to_append)
			   {
				  String string{};
				  i64 count = to_append.size();

				  string.ptr = malloc( to_append_on.lenght + count );
				  string.data = (c8*)string.ptr;
				  string.lenght = to_append_on.lenght + count;

				  for(i64 i = 0; i < count; ++i)
				  {
				  *string.data++ = to_append[i];
				  }

				  for(i64 i = 0; i  < to_append_on.lenght; ++i)
				  {
					 *string.data++ = *to_append_on.data++;
				  }

				  ret string;
			   }
   String	   append_front(String& to_append_on,c8* to_append)
			   {
				  String string{};
				  i64 count{0};
				  while( *to_append != '\0' )
				  {
					 ++to_append;
					 ++count;
				  };

				  string.ptr    = malloc(count+to_append_on.lenght);
				  string.data	= (c8*)string.ptr;
				  string.lenght = count + to_append_on.lenght;

				  for(i64 i = count; 0 < i; ++i)
				  {
					 *string.data++ = *to_append--;
				  }

				  for(i64 i = 0; i < to_append_on.lenght; ++i)
				  {
					 *string.data++ = *to_append_on.data++;
				  }

				  ret string;
			   }
   String	   append_front(String& to_append_on,const c8* to_append)
			   {
				  String string{};
				  i64 count{0};
				  while( *to_append != '\0' )
				  {
					 ++to_append;
					 ++count;
				  };

				  string.ptr    = malloc(count+to_append_on.lenght);
				  string.data	= (c8*)string.ptr;
				  string.lenght = count + to_append_on.lenght;

				  for(i64 i = count; 0 < i; ++i)
				  {
					 *string.data++ = *to_append--;
				  }

				  for(i64 i = 0; i < to_append_on.lenght; ++i)
				  {
					 *string.data++ = *to_append_on.data++;
				  }

				  ret string;
			   }
				
			   //#TODO Find a better algo
   bl		   search(String searchin,String tosearch)
			   {
				  if(tosearch.lenght > searchin.lenght)
					 ret false;

				  for(i64 i = 0; i < searchin.lenght; ++i)
				  {
					 i64 i2 = 0;
					 searchin.data++;
					 if(*searchin.data == *tosearch.data)
					 {
						while( *searchin.data == *tosearch.data && i2 < tosearch.lenght)
						{
						   searchin.data++;
						   tosearch.data++;
						   i2++;
						   i++;

						   if(i2 == tosearch.lenght)
							  return true;

						}
					 }
				  }
				  ret false;
			   }

   bl		   search(String searchin, std::string tosearch) { ret true; };
   bl		   search(String searchin,c8* tosearch) { ret true; };
   bl		   search(String searchin,const c8* tosearch) { ret true; };

   i64		   search_first(String searchin,String tosearch) { ret true; };
   i64		   search_first(String searchin,std::string tosearch) { ret true; };
   i64		   search_first(String searchin,c8* tosearch) { ret true; };
   i64		   search_first(String searchin,const c8* tosearch) { ret true; };

   bl		   clear(String& to_clear )
   {
	  free(to_clear.ptr);
	  to_clear.ptr = nullptr;
	  to_clear.data = nullptr;
	  to_clear.lenght = 0;
	  ret true;
   }

   // I don't no how we should do this or if we should do this
   //i64		   getCodePoints(String to_getPoints);



   std::string to_stdstr(String to_convert) { ret std::string(); }

   //#INFO Keep in mind this is post increment ! 
   c8 * to_charptr(String to_convert)
   {
	   c8* to_clear = (c8*)malloc(to_convert.lenght+1);
	   for (i64 i = 0; i < to_convert.lenght; ++i)
	   {
		   *to_clear++ = *to_convert.data++;
	   }
	   *to_clear = '\0';
	   to_clear -= (to_convert.lenght);

	   ret to_clear;
   }
   c16 * to_wchar(String to_convert)
   {
	   return nullptr;
   }
   ;
  // c8*		   to_charptr(String to_convert) {  };
  // c16*		   to_wchar(String to_convert) {  };

   String      copy(String to_copy)
			   {
				  String string{};
				  string.ptr = malloc(to_copy.lenght);
				  string.data = (c8*)string.ptr;

				  for(i64 i = 0; i < to_copy.lenght; ++i )
				  {
				  *string.data++ = *to_copy.data++;
				  }
				  string.lenght = to_copy.lenght;
				  ret string;
			   }

   String	   substr(String for_substr,i64 start,i64 end)
			   {
				  if( start > for_substr.lenght || end < start )
				  {
					 std::cout << "Error you can not make a Range with Neagtiv Index" << end;
					 ret String();
				  };

				  String string{};
				  i64 size = end - start;
				  string.ptr = memory_allocte_zero(size);
				  string.data = (c8*) string.ptr;

				  for_substr.data+=start;

				  for(i64 i = start; i <= end; ++i )
				  {
					 *string.data++ = *for_substr.data++;
				  }

				  string.data -= size;
				  string.lenght = size;
				  ret string;
			   }

   String left(String string, i64 count)
   {
	   i64 trimsize = string.lenght - count;
	   ret substr(string,1,trimsize);
   }

   String right(String string, i64 count)
   {
	   i64 trimsize = string.lenght - count;
	   ret substr(string, trimsize-1, string.lenght);
   }

   String      replace(String to_replacein, String to_replace) { ret String(); };
   String      replace_first(String to_replacein, String to_replace) { ret String(); };

   String      convert(c8* to_convert){ ret String(); };
   String      convert(const c8* to_convert) { ret String(); };
   String      convert(std::string to_convert) { ret String(); };
   String      convert(c16* to_convert) { ret String(); };
   
}
