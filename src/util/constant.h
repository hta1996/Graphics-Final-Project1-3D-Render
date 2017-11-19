#ifndef CONST_H
#define CONST_H
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

namespace Constant
{
	typedef unsigned long long uint64;
	typedef long long int64;
	typedef double data_type;
	typedef double other_data;

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

