#ifndef vector3D_H
#define vector3D_H

#include "constant.h"
//#include "Vector2D.h"

struct Vec2D
{
	typedef Constant::data_type Coor_T;
	
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

	Coor_T mod2(void) const { return x * x + y * y;} //����ģ����ƽ��
	
	Coor_T mod(void) const { return std::sqrt(x * x + y * y);} //����ģ��
	
	Coor_T dot(const Vec2D& k) const { return x * k.x + y * k.y; } //�ڻ�
    
    Vec2D genVert(void) const { return Vec2D(y, -x); }
	
	Vec2D unit(void) const; //��λ��
	
	inline static Vec2D rand(void);	
};



#endif
