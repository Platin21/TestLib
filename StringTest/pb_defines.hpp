#pragma once

//#SECTION Pool Things
//#DEF Size of the Memmory Pool to Allocate size is 1MB
#define PB_MEMORY_POOL_SIZE 1000000
//#DEF Size of one byte 
#define PB_BYTE_SIZE 1

//#SECTION Hash Table
//#DEF Size of an PB standart hashtable also a Prime Number
#define PB_HASH_TABLE_SIZE 4127 

//#INF Special Defines

//#INF ret is equal to return 
#define	ret return

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__)  || defined(__WINDOWS__)
#define  __WINDOWS__
#endif

#if defined(__APPLE__) && defined(__MACH__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 10100
#define  __MACOS__
#endif

#ifdef defined(__APPLE__) &&  defined(__MACH__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 70000
#define __IOS__
#endif

#ifdef defined(linux) || defined(__linux)
#define  __LINUX__
#endif