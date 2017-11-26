#ifndef vector3D_H
#define vector3D_H

#include "constant.h"

struct Vec2D
{
	typedef data_type Coor_T;
	
	Coor_T x, y;
	
	Vec2D() : x(0), y(0){}
	Vec2D(Coor_T x, Coor_T y) : x(x), y(y) {}
	
	Vec2D operator + (const Vec2D& k) const { return Vec2D(x + k.x, y + k.y); } 
	Vec2D& operator += (const Vec2D& k) { x += k.x, y += k.y; return *this; } 
	Vec2D operator + (const Coor_T& k) const { return Vec2D(x + k, y + k); }
	Vec2D& operator += (const Coor_T& k) { x += k, y += k; return *this; }
	
	Vec2D operator - (const Vec2D& k) const { return Vec2D(x - k.x, y - k.y); }
	Vec2D& operator -= (const Vec2D& k) { x -= k.x, y -= k.y; return *this; }
	Vec2D operator - (const Coor_T& k) const { return Vec2D(x - k, y - k); }
	Vec2D& operator -= (const Coor_T& k) { x -= k, y -= k; return *this; }
		
	Coor_T operator * (const Vec2D& k) const { return x * k.y - y * k.x; }
	
	Vec2D operator * (const Coor_T& k) const { return Vec2D(x * k, y * k); }
	Vec2D& operator *= (const Coor_T& k) { x *= k, y *= k; return *this; }
		
	Vec2D operator / (const Coor_T& k) const { return Vec2D(x / k, y / k); }
	Vec2D& operator /= (const Coor_T& k) { x /= k, y /= k; return *this; }
	
	Vec2D operator - (void) const { return Vec2D(-x, -y); }
	
	Coor_T& operator[] (int i) { return i == 1 ? y : x; }	
	const Coor_T operator[] (int i) const { return i ? y : x; }

	Coor_T len2(void) const { return x * x + y * y;} //向量模长的平方
	
	Coor_T len(void) const { return std::sqrt(x * x + y * y);} //向量模长
	
	Coor_T dot(const Vec2D& k) const { return x * k.x + y * k.y; } //内积
    
    Vec2D genVert(void) const { return Vec2D(y, -x); }
	
	Vec2D unit(void) const //单位化
	{
		Coor_T s = len();
		return *(this) / (s < Constant::EPS ? 1 : s);
	}
	
	inline static Vec2D rand(void);	
};



#endif
