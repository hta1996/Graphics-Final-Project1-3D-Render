#include "vector2D.h"

Vec2D Vec2D::unit(void) const
{
	Vec2D::Coor_T len = mod();
	return *(this) / (len < Constant::EPS ? 1 : len);
}



inline std::ostream& operator << (std::ostream& out, const Vec2D& x)
{
    return out << '(' << x.x << ' ' << x.y << ')';
}

inline Vec2D Vec2D::rand(void)
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

