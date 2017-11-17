#ifndef vector3D_H
#define vector3D_H

#include "constant.h"
//#include "Vector2D.h"

struct Vec2D
{
	typedef Constant::coordinate_type Coor_T;
	
	Coor_T x, y;
	
	Vec2D() : x(0), y(0){}
	Vec2D(Coor_T x, Coor_T y) : x(x), y(y) {}
	
	Vec2D operator + (const Vec2D& k) const;
	Vec2D& operator += (const Vec2D& k);
	Vec2D operator + (const Coor_T& k) const;
	Vec2D& operator += (const Coor_T& k);
	
	Vec2D operator - (const Vec2D& k) const;
	Vec2D& operator -= (const Vec2D& k);
	Vec2D operator - (const Coor_T& k) const;
	Vec2D& operator -= (const Coor_T& k);
		
	Coor_T operator * (const Vec2D& k) const;
	
	Vec2D operator * (const Coor_T& k) const;
	Vec2D& operator *= (const Coor_T& k);
		
	Vec2D operator / (const Coor_T& k) const;
	Vec2D& operator /= (const Coor_T& k);
	
	Vec2D operator - (void) const;
	
	Coor_T& operator[] (int i) ;	
	const Coor_T operator[] (int i) const;

	Coor_T mod2(void) const; //����ģ����ƽ��
	
	Coor_T mod(void) const; //����ģ��
	
	Coor_T dot(const Vec2D& k) const; //�ڻ�
    
    Vec2D genVert(void) const;
	
	Vec2D unit(void) const; //��λ��
	
};

inline Vec2D randV2(void);

#endif
