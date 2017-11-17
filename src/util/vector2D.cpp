#include "vector2D.h"

Vec2D Vec2D::operator + (const Vec2D& k) const
{
	return Vec2D(x + k.x, y + k.y);
}

Vec2D& Vec2D::operator += (const Vec2D& k)
{
	x += k.x, y += k.y;
	return *this;
}

Vec2D Vec2D::operator + (const Vec2D::Coor_T& k) const
{
	return Vec2D(x + k, y + k);
}

Vec2D& Vec2D::operator += (const Vec2D::Coor_T& k)
{
	x += k, y += k;
	return *this;
}



Vec2D Vec2D::operator - (const Vec2D& k) const
{
	return Vec2D(x - k.x, y - k.y);
}

Vec2D& Vec2D::operator -= (const Vec2D& k)
{
	x -= k.x, y -= k.y;
	return *this;
}

Vec2D Vec2D::operator - (const Vec2D::Coor_T& k) const
{
	return Vec2D(x - k, y - k);
}

Vec2D& Vec2D::operator -= (const Vec2D::Coor_T& k)
{
	x -= k, y -= k;
	return *this;
}



Vec2D::Coor_T Vec2D::operator * (const Vec2D& k) const
{
	return x * k.y - y * k.x;
}

Vec2D Vec2D::operator * (const Vec2D::Coor_T& k) const
{
	return Vec2D(x * k, y * k);
}

Vec2D& Vec2D::operator *= (const Vec2D::Coor_T& k)
{
	x *= k, y *= k;
	return *this;
}



Vec2D Vec2D::operator / (const Vec2D::Coor_T& k) const
{
	return Vec2D(x / k, y / k);
}

Vec2D& Vec2D::operator /= (const Vec2D::Coor_T& k)
{
	x /= k, y /= k;
	return *this;
}

Vec2D Vec2D::operator - (void) const { return Vec2D(-x, -y); }



Vec2D::Coor_T& Vec2D::operator[] (int i) { return i == 1 ? y : x; }
const Vec2D::Coor_T Vec2D::operator[] (int i) const { return i ? y : x; }

Vec2D::Coor_T Vec2D::mod2(void) const { return x * x + y * y;}
Vec2D::Coor_T Vec2D::mod(void) const { return std::sqrt(x * x + y * y);}
Vec2D::Coor_T Vec2D::dot(const Vec2D& k) const { return x * k.x + y * k.y; }
    
Vec2D Vec2D::genVert(void) const { return Vec2D(y, -x); }

Vec2D Vec2D::unit(void) const
{
	Vec2D::Coor_T len = mod();
	return *(this) / (len < Constant::EPS ? 1 : len);
}



inline std::ostream& operator << (std::ostream& out, const Vec2D& x)
{
    return out << '(' << x.x << ' ' << x.y << ')';
}

inline Vec2D randV2(void)
{
	Vec2D v;
	while (true)
	{
		v.x = Constant::randD();
		v.y = Constant::randD();
		if (v.mod2() > Constant::EPS) break;
	}
    return v.unit();
}

