#include "object.h"
#include "light/light.h"

Collision::Collision(const Ray& r, data_type t, const Light *l) :
	o(nullptr), l(l), t(t), r(r), id(l->getI()), in(false)
{ p = r.get(t); }


Collision::Collision(const Ray& r, data_type t, const Vec3D& n, const Object* o, bool in, uint64 id)
	: o(o), l(nullptr), r(r.unit()), p(r.get(t)), n(n.unit()), t(t), in(in), id(id ? id : o->getI()){}

