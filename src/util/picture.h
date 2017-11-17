#ifndef vector3D_H
#define vector3D_H

#include "constant.h"
//#include "Vector2D.h"

struct Vec3D
{
	typedef Constant::coordinate_type Coor_T;
	
	Coor_T x, y, z;
	
	Vec3D() : x(0), y(0), z(0) {}
	Vec3D(Coor_T x, Coor_T y, Coor_T z) : x(x), y(y), z(z) {}
	
	Vec3D operator + (const Vec3D& k) const;
	Vec3D& operator += (const Vec3D& k);
	Vec3D operator + (const Coor_T& k) const;
	Vec3D& operator += (const Coor_T& k);
	
	Vec3D operator - (const Vec3D& k) const;
	Vec3D& operator -= (const Vec3D& k);
	Vec3D operator - (const Coor_T& k) const;
	Vec3D& operator -= (const Coor_T& k);
		
	Vec3D operator * (const Vec3D& k) const;
	Vec3D& operator *= (const Vec3D& k);
	Vec3D operator * (const Coor_T& k) const;
	Vec3D& operator *= (const Coor_T& k);
		
	Vec3D operator / (const Coor_T& k) const;
	Vec3D& operator /= (const Coor_T& k);
	
	Vec3D operator - (void) const;
	
	Coor_T& operator[] (int i) ;	
	const Coor_T operator[] (int i) const;

	Coor_T mod2(void) const; //向量模长的平方
	
	Coor_T mod(void) const; //向量模长
	
	Coor_T dot(const Vec3D& k) const; //内积
	 
    // Vector2 toVector2() const { return Vector2(x, y); }
    
    Vec3D reflect(const Vec3D& n) const;
    
    Vec3D refract(const Vec3D& n, Constant::other_data re_index) const;
    
    Vec3D genVert(void) const;
    
    Vec3D diffuse(void) const;
	
	Vec3D unit(void) const; //单位化
	
};

inline Vec3D::Coor_T mix(const Vec3D &a, const Vec3D &b, const Vec3D &c);
inline Vec3D randV3(void);

#endif
