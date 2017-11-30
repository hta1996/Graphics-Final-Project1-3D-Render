#ifndef CONST_H
#define CONST_H
#include "heads.h"

namespace Constant
{

	const double RT_THERASHOLD = 0.01;
	const double OUTPUT_PT = 600;
	const int RT_MAXDEP = 20;

	const int PHONG_S = 50;
	const int SHADOW_SAMPLES = 4;

//int Config::soft_shadow_samples = 4;


	const double EPS = 1e-6;
	const double PI = std::acos(-1.0);
	
	inline int randI(void)
	{
		#ifdef __linux__
			return rand();
		#else
			return (rand() << 15) | rand();
		#endif
	}

	inline int64 randI64(void)
	{
		#ifdef __linux__
			return (rand() << 31) | rand();
		#else
			return (((((0LL + rand() << 15) | rand()) << 15) | rand()) << 15) | rand();
		#endif
	}
	inline int64 gen(void) { static int64 s = 0; return ++s; }
	inline double randD(void) // [0,1]
	{
		#ifdef __linux__
			return rand() / 2147483648.0;
		#else
			return ((rand() << 15) | rand()) / 1073741824.0;
		#endif
	}
}

#endif

