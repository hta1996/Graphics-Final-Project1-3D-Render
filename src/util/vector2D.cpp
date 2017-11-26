#include "vector2D.h"



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
		if (v.len2() > Constant::EPS) break;
	}
    return v.unit();
}

