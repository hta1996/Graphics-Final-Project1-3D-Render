#ifndef vector3D_H
#define vector3D_H

#include "constant.h"
//#include "Vector2D.h"

template < typename Coor_T >
struct Vector3D
{	
	Coor_T x, y, z;
	Coor_T &r = x, &g = y, &b = z;
	
	Vector3D() : x(0), y(0), z(0) {}
	Vector3D(Coor_T x, Coor_T y, Coor_T z) : x(x), y(y), z(z) {}
	auto& operator = (const Vector3D &k) { x = k.x, y = k.y, z = k.z; return *this; }
	
	auto operator + (const Vector3D& k) const { return Vector3D(x + k.x, y + k.y, z + k.z); }
	auto& operator += (const Vector3D& k) { x += k.x, y += k.y, z += k.z; return *this; }
	auto operator + (const Coor_T& k) const { return Vector3D(x + k, y + k, z + k); }
	auto& operator += (const Coor_T& k) { x += k, y += k, z += k; return *this; }
	
	auto operator - (const Vector3D& k) const { return Vector3D(x - k.x, y - k.y, z - k.z); }
	auto operator -= (const Vector3D& k) { x -= k.x, y -= k.y, z -= k.z; return *this; }
	auto operator - (const Coor_T& k) const { return Vector3D(x - k, y - k, z - k); }
	auto & operator -= (const Coor_T& k) { x -= k, y -= k, z -= k; return *this; }
		
	auto operator * (const Vector3D& k) const
	{
		return Vector3D(y * k.z - z * k.y, z * k.x - x * k.z, x * k.y - y * k.x);
	}
	auto & operator *= (const Vector3D& k) 
	{
		return *this = Vector3D(y * k.z - z * k.y, z * k.x - x * k.z, x * k.y - y * k.x);
	}
	auto operator * (const Coor_T& k) const { return Vector3D(x * k, y * k, z * k); }
	auto & operator *= (const Coor_T& k) { x *= k, y *= k, z *= k; return *this; }
		
	auto operator / (const Coor_T& k) const { return Vector3D(x / k, y / k, z / k); }
	auto & operator /= (const Coor_T& k) { x /= k, y /= k, z /= k; return *this; }
	
	auto operator - (void) const { return Vector3D(-x, -y, -z); }
	
	auto& operator[] (int i) { return !i ? x : (i == 1 ? y : z); }	
	const auto operator[] (int i) const { return !i ? x : (i == 1 ? y : z); }

	auto mod2(void) const { return x * x + y * y + z * z; } //向量模长的平方
	auto mod(void) const { return std::sqrt(x * x + y * y + z * z);} //向量模长
	auto dot(const Vector3D& k) const { return x * k.x + y * k.y + z * k.z; } //内积
	auto mul(const Vector3D& k) const { return Vector3D(x * k.x, y, k.y, z * k.z); } //对应相乘 
	auto inverse(void) const { return Vector3D(1 - r, 1 - g, 1 - b); } //反颜色 
	auto exp(void) const {	return Vector3D(std::exp(r), std::exp(g), std::exp(b)); } //指数
    // Vector2 toVector2() const { return Vector2(x, y); }
    
    auto reflect(const Vector3D& n) const { return *this - n * (2 * this->dot(n)); } //反射 
    
    auto refract(const Vector3D& n, Constant::other_data re_index) const;
    
    auto genVert(void) const;
    
    auto diffuse(void) const;
	
	auto unit(void) const; //单位化
	
	
	auto normal(void) const; //约束到[0,1]之间
	
	//Col_T power(void) const; //能量 
	
	static inline auto mix(const Vector3D &a, const Vector3D &b, const Vector3D &c);
	static inline auto rand(void);
};

template < typename Coor_T >
inline std::ostream& operator << (std::ostream& out, const Vector3D<Coor_T>& x)
{
    return out << '(' << x.x << ' ' << x.y << ' ' << x.z << ')';
}

typedef Vector3D < Constant::data_type > Vec3D;
#endif

