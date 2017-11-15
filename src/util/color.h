#ifndef COLOR_H
#define COLOR_H

#include "const.h"

struct Color
{
	//typedef float ColT;
	typedef double ColT;
	
	ColT r, g, b;
	
	Color() : r(0), g(0), b(0) {}
	Color(ColT r, ColT g, ColT b) : r(r), g(g), b(b) {}
	
	Color operator + (const Color& k) const;
	Color& operator += (const Color& k);
	Color operator + (const ColT& k) const;
	Color& operator += (const ColT& k);
	
	Color operator - (const Color& k) const;
	Color& operator -= (const Color& k);
	Color operator - (const ColT& k) const;
	Color& operator -= (const ColT& k);
		
	Color operator * (const Color& k) const;
	Color& operator *= (const Color& k);
	Color operator * (const ColT& k) const;
	Color& operator *= (const ColT& k);
		
	Color operator / (const ColT& k) const;
	Color& operator /= (const ColT& k);

	ColT mod2(void) const; //颜色模长
	
	Color inverse(void) const; //反颜色 
	
	Color exp(void) const; //指数
	
	Color normal(void) const; //约束到[0,1]之间
	
	ColT power(void) const; //能量 
	
};

#endif
