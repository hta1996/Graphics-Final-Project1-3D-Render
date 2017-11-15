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

	ColT mod2(void) const; //��ɫģ��
	
	Color inverse(void) const; //����ɫ 
	
	Color exp(void) const; //ָ��
	
	Color normal(void) const; //Լ����[0,1]֮��
	
	ColT power(void) const; //���� 
	
};

#endif
