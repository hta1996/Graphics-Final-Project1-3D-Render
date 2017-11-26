#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "light/light.h"


class PLight : public Light
{
public:
    PLight(const Color& c, const Vec3D& o, data_type power = 1) : Light(c, power), o(o) {}

    virtual Vec3D getS(void) const override { return o; }
    
    virtual Collision collide(const Ray& ray) const override
    {
    	if (!ray.onray(o)) return Collision(); 
    	data_type t = (o - ray.o).dot(ray.d);
    	if (t > Constant::EPS) return Collision(ray, t, this);
    	return Collision(); 
    }

private:
    Vec3D o;
};

#endif 
