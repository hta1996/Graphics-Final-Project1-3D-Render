#ifndef RAY_H
#define RAY_H

#include "constant.h"
#include "vector3D.h"
using Constant::EPS;

struct Ray //…‰œﬂ¿‡ 
{
	Vec3D o, d;
	
	Ray(): o(), d() {}
	Ray(const Vec3D& o, const Vec3D& dir): o(o), d(dir.unit()) {}
	Vec3D get(const data_type &t) const { return o + d * t; }
	Ray unit(void) const { return Ray(o, d.unit()); }
	void unitize(void) { d.unitize(); }	
	bool onray(Vec3D x) const { return ((x - o).unit() - d).len() <= EPS; }
};

inline std::ostream& operator << (std::ostream& out, const Ray& ray)
{
    return out << ray.o << " -> " << ray.d << "(vp = " << ray.o + ray.d << ')';
}
#endif
