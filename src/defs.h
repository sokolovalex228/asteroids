#ifndef __DEFS_H__
#define __DEFS_H__

#include "platform.h"

/////////////////////////

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long int ulong;

#if defined(__cplusplus)
	
#else

	#define nullptr 0

	typedef unsigned int bool;
	#define true 1
	#define false 0

#endif

#if defined(__cplusplus) && !defined(LB_REMOVE_TRY_CATCH)

#define LB_TRY try{
#define LB_CATCH }catch(...){
#define LB_TRY_END }

#else

#define LB_TRY
#define LB_CATCH if(false){
#define LB_TRY_END }

#endif

#if defined(_DEBUG)
#define LOG(...) printf(__VA_ARGS__); printf("\n");
#else
#define LOG(...)
#endif

// used for contol memory allocation
#define _DEBUG_CPP
#if defined(_DEBUG_CPP)
#define LOG_CPP(...) printf("%s::", __FUNCTION__); printf(""__VA_ARGS__"\n")
//#define LOG_CPP(...) printf("%s::%s:", __FILE__, __FUNCTION__); printf(""__VA_ARGS__"\n")
#else
#define LOG_CPP(...)
#endif

#define PI_LB 3.14159265358979323846
#define Deg2Rad(deg) ((deg) * PI_LB/180.0)
#define Rad2Deg(rad) ((rad) * 180.0/PI_LB)

#define uzing(t, n, v) t n = (t)(v); if(0 != n)
#define uzingt(tname, v) tname* p##tname = (tname*)(v); if(nullptr != p##tname)
#define uzingp(t, v) t* p##t= (t*)(v); if(nullptr != p##t)

#define STRNCPY2BUF(b, s) strncpy(b, s, sizeof(b)); b[sizeof(b) - 1] = 0;

#if !defined(FILENAME_MAX)
#define FILENAME_MAX 256
#endif

#endif
