#include "vector3D.h"

Vec3D Vec3D::operator + (const Vec3D& k) const
{
	return Vec3D(x + k.x, y + k.y, z + k.z);
}

Vec3D& Vec3D::operator += (const Vec3D& k)
{
	x += k.x, y += k.y, z += k.z;
	return *this;
}

Vec3D Vec3D::operator + (const Vec3D::Coor_T& k) const
{
	return Vec3D(x + k, y + k, z + k);
}

Vec3D& Vec3D::operator += (const Vec3D::Coor_T& k)
{
	x += k, y += k, z += k;
	return *this;
}



Vec3D Vec3D::operator - (const Vec3D& k) const
{
	return Vec3D(x - k.x, y - k.y, z - k.z);
}

Vec3D& Vec3D::operator -= (const Vec3D& k)
{
	x -= k.x, y -= k.y, z -= k.z;
	return *this;
}

Vec3D Vec3D::operator - (const Vec3D::Coor_T& k) const
{
	return Vec3D(x - k, y - k, z - k);
}

Vec3D& Vec3D::operator -= (const Vec3D::Coor_T& k)
{
	x -= k, y -= k, z -= k;
	return *this;
}



Vec3D Vec3D::operator * (const Vec3D& k) const
{
	return Vec3D(y * k.z - z * k.y, z * k.x - x * k.z, x * k.y - y * k.x);
}

Vec3D& Vec3D::operator *= (const Vec3D& k)
{
	return *this = Vec3D(y * k.z - z * k.y, z * k.x - x * k.z, x * k.y - y * k.x);
}

Vec3D Vec3D::operator * (const Vec3D::Coor_T& k) const
{
	return Vec3D(x * k, y * k, z * k);
}

Vec3D& Vec3D::operator *= (const Vec3D::Coor_T& k)
{
	x *= k, y *= k, z *= k;
	return *this;
}



Vec3D Vec3D::operator / (const Vec3D::Coor_T& k) const
{
	return Vec3D(x / k, y / k, z / k);
}

Vec3D& Vec3D::operator /= (const Vec3D::Coor_T& k)
{
	x /= k, y /= k, z /= k;
	return *this;
}

Vec3D Vec3D::operator - (void) const { return Vec3D(-x, -y, -z); }



Vec3D::Coor_T& Vec3D::operator[] (int i) { return !i ? x : (i == 1 ? y : z); }
const Vec3D::Coor_T Vec3D::operator[] (int i) const { return !i ? x : (i == 1 ? y : z); }

Vec3D::Coor_T Vec3D::mod2(void) const { return x * x + y * y + z * z;}
Vec3D::Coor_T Vec3D::mod(void) const { return std::sqrt(x * x + y * y + z * z);}
Vec3D::Coor_T Vec3D::dot(const Vec3D& k) const { return x * k.x + y * k.y + z * k.z; }
Vec3D Vec3D::reflect(const Vec3D& n) const { return *this - n * (2 * this->dot(n)); }

Vec3D Vec3D::refract(const Vec3D& n, Constant::other_data re_index) const
{
	Vec3D::Coor_T ni = 1 / re_index, cosI = this->dot(n), cosT2; //I->T 
	cosT2 = 1 - ni * ni * (1 - cosI * cosI);
	if (cosT2 >= 0)
		return (*this) * ni - n * (sqrt(cosT2) + cosI * ni);
	else return Vec3D(); //È«·´Éä
}
    
Vec3D Vec3D::genVert(void) const
{
	return Vec3D(y, -x, 0).unit(); 
	/*
	Vec3D v = (*this) * (Vec3D(0, 0, 1));
	if (v.mod2() < Const::EPS) Vec3D v = (*this) * (Vec3D(1, 0, 0));
	return v.unit();*/
}
/*
Vec3D Vec3D::diffuse() const
{
	
    double theta = acos(sqrt(Const::randDouble())), phi = 2 * Const::PI * Const::randDouble();
    Vector3 dir(cos(phi) * sin(theta), sin(phi) * sin(theta), cos(theta));
    Vector3 dx = getAnVerticalVector(), dy = (*this) * (dx);
    return dx * dir.x + dy * dir.y + operator*(dir.z);
}*/

Vec3D Vec3D::unit(void) const
{
	Vec3D::Coor_T len = mod();
	return *(this) / (len < Constant::EPS ? 1 : len);
}



inline std::ostream& operator << (std::ostream& out, const Vec3D& x)
{
    return out << '(' << x.x << ' ' << x.y << ' ' << x.z << ')';
}

inline Vec3D::Coor_T mix(const Vec3D &a, const Vec3D &b, const Vec3D &c) { return a.dot(b * c); }

inline Vec3D randV3(void)
{
	Vec3D v;
	while (true)
	{
		v.x = Constant::randD();
		v.y = Constant::randD();
		v.z = Constant::randD();
		if (v.mod2() > Constant::EPS) break;
	}
    return v.unit();
}

