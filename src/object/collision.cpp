#include "light/light.h"
#include "object.h"
#include "collision.h"

Collision::Collision(const Ray& r, data_type t, const Light *l) :
o(nullptr), l(l), t(t), r(r), id(l->geti()), in(false)
{ p = r.get(t); }