#ifndef COLOR_H
#define COLOR_H

#include "constant.h"

struct Color
{
	//typedef float Col_T;
	typedef double Col_T;
	
	Col_T r, g, b;
	const Col_T &x = r, &y = g, &z = b;
	
	Color() : r(0), g(0), b(0) {}
	Color(Col_T r, Col_T g, Col_T b) : r(r), g(g), b(b) {}
	
	Color operator + (const Color& k) const;
	Color& operator += (const Color& k);
	Color operator + (const Col_T& k) const;
	Color& operator += (const Col_T& k);
	
	Color operator - (const Color& k) const;
	Color& operator -= (const Color& k);
	Color operator - (const Col_T& k) const;
	Color& operator -= (const Col_T& k);
		
	virtual Color operator * (const Color& k) const;
	Color& operator *= (const Color& k);
	Color operator * (const Col_T& k) const;
	Color& operator *= (const Col_T& k);
		
	Color operator / (const Col_T& k) const;
	Color& operator /= (const Col_T& k);
	
	Color operator - (void) const;
	
	Col_T& operator[] (int i) ;	
	const Col_T operator[] (int i) const;

	Col_T mod2(void) const; //��ɫģ����ƽ�� 
	
	Color inverse(void) const; //����ɫ 
	
	Color exp(void) const; //ָ��
	
	Color normal(void) const; //Լ����[0,1]֮��
	
	Col_T power(void) const; //���� 
	
};

#endif
