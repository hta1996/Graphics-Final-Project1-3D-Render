#ifndef vector3D_H
#define vector3D_H

#include "constant.h"
using Constant::EPS;

//模板类定义和实现放一起 
template < typename Coor_T >
struct Vector3D
{	
	Coor_T x, y, z;
	Coor_T &r = x, &g = y, &b = z;
	
	Vector3D() : x(0), y(0), z(0) {}
	Vector3D(Coor_T x, Coor_T y, Coor_T z) : x(x), y(y), z(z) {}
	Vector3D& operator = (const Vector3D &k) { x = k.x, y = k.y, z = k.z; return *this; }
	
	Vector3D operator + (const Vector3D& k) const { return Vector3D(x + k.x, y + k.y, z + k.z); }
	Vector3D& operator += (const Vector3D& k) { x += k.x, y += k.y, z += k.z; return *this; }
	Vector3D operator + (const Coor_T& k) const { return Vector3D(x + k, y + k, z + k); }
	Vector3D& operator += (const Coor_T& k) { x += k, y += k, z += k; return *this; }
	
	Vector3D operator - (const Vector3D& k) const { return Vector3D(x - k.x, y - k.y, z - k.z); }
	Vector3D operator -= (const Vector3D& k) { x -= k.x, y -= k.y, z -= k.z; return *this; }
	Vector3D operator - (const Coor_T& k) const { return Vector3D(x - k, y - k, z - k); }
	Vector3D & operator -= (const Coor_T& k) { x -= k, y -= k, z -= k; return *this; }
		
	Vector3D operator * (const Vector3D& k) const
	{
		return Vector3D(y * k.z - z * k.y, z * k.x - x * k.z, x * k.y - y * k.x);
	}
	Vector3D & operator *= (const Vector3D& k) 
	{
		return *this = Vector3D(y * k.z - z * k.y, z * k.x - x * k.z, x * k.y - y * k.x);
	}
	Vector3D operator * (const Coor_T& k) const { return Vector3D(x * k, y * k, z * k); }
	Vector3D & operator *= (const Coor_T& k) { x *= k, y *= k, z *= k; return *this; }
		
	Vector3D operator / (const Coor_T& k) const { return Vector3D(x / k, y / k, z / k); }
	Vector3D & operator /= (const Coor_T& k) { x /= k, y /= k, z /= k; return *this; }
	
	Vector3D operator - (void) const { return Vector3D(-x, -y, -z); }
	
	Coor_T& operator[] (int i) { return !i ? x : (i == 1 ? y : z); }	
	const Coor_T operator[] (int i) const { return !i ? x : (i == 1 ? y : z); }

	Coor_T len2(void) const { return x * x + y * y + z * z; }                             //向量模长的平方
	Coor_T len(void) const { return std::sqrt(x * x + y * y + z * z);}                    //向量模长
	Coor_T dot(const Vector3D& k) const { return x * k.x + y * k.y + z * k.z; }           //内积
	Vector3D mul(const Vector3D& k) const { return Vector3D(x * k.x, y * k.y, z * k.z); }  //对应相乘 
	Vector3D inverse(void) const { return Vector3D(1 - r, 1 - g, 1 - b); }                //反颜色 
	Vector3D exp(void) const {	return Vector3D(std::exp(r), std::exp(g), std::exp(b)); } //指数
    // Vector2 toVector2() const { return Vector2(x, y); }
    
    Vector3D reflect(const Vector3D& n) const { return *this - n * (2 * this->dot(n)); }  //反射 
    
    Vector3D refract(const Vector3D& n, other_data re_index) const                        //折射
    {
		Coor_T ni = 1 / re_index, cosI = this->dot(n), cosT2; //I->T 
		cosT2 = 1 - ni * ni * (1 - cosI * cosI);
		if (cosT2 >= 0)
			return (*this) * ni - n * (sqrt(cosT2) + cosI * ni);
		else return Vector3D<Coor_T>(); //全反射
	}
    
    Vector3D genVert(void) const
    {
		return Vector3D<Coor_T>(y, -x, 0).unit(); 
		/*
		Vector3D v = (*this) * (Vector3D(0, 0, 1));
		if (v.mod2() < Const::EPS) Vector3D v = (*this) * (Vector3D(1, 0, 0));
		return v.unit();*/
	}
    
    Vector3D diffuse(void) const;
	
	Vector3D unit(void) const //单位化
	{
		Coor_T s = len();
		return *(this) / (s < EPS ? 1 : s);
	}
	
	void unitize(void)
	{
		Coor_T s = len();
		if (s >= EPS)
			x /= s, y /= s, z /= s;
	}
	
	
	Vector3D normal(void) const //约束到[0,1]之间
	{
		return Vector3D<Coor_T>(max(min(r, 1.0), 0.0), max(min(g, 1.0), 0.0), max(min(b, 1.0), 0.0));
	}

	Coor_T maxo(void) const { return max(max(x, y), z); }
	Coor_T mino(void) const { return min(min(x, y), z); }

	//Col_T power(void) const; //能量 
	
	static inline Coor_T mix(const Vector3D &a, const Vector3D &b, const Vector3D &c);
	static inline Vector3D rand(void);
};


/*
Vector3D Vector3D::diffuse() const
{
	
    double theta = acos(sqrt(Const::randDouble())), phi = 2 * Const::PI * Const::randDouble();
    Vector3 dir(cos(phi) * sin(theta), sin(phi) * sin(theta), cos(theta));
    Vector3 dx = getAnVerticalVector(), dy = (*this) * (dx);
    return dx * dir.x + dy * dir.y + operator*(dir.z);
}*/

template < typename Coor_T >
Coor_T Vector3D<Coor_T>::mix(const Vector3D<Coor_T> &a, const Vector3D<Coor_T> &b, const Vector3D<Coor_T> &c)
{ return a.dot(b * c); }

template < typename Coor_T >
Vector3D<Coor_T> Vector3D<Coor_T>::rand(void)
{
	Vector3D<Coor_T> v;
	while (true)
	{
		v.x = Constant::randD();
		v.y = Constant::randD();
		v.z = Constant::randD();
		if (v.mod2() > Constant::EPS) break;
	}
    return v.unit();
}

template < typename Coor_T >
inline std::ostream& operator << (std::ostream& out, const Vector3D<Coor_T>& x)
{
    return out << '(' << x.x << ' ' << x.y << ' ' << x.z << ')';
}

template < typename Coor_T >
inline void operator >> (const YAML::Node& x, Vector3D<Coor_T> &y)
{
	if (x) for (auto i = 0; i < x.size(); i++) x[i] >> y[i];
}

typedef Vector3D < data_type > Vec3D;

#endif

