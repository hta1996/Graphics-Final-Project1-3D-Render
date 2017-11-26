#ifndef LIGHT_H
#define LIGHT_H

#include "util/ray.h"
#include "util/color.h"
#include "object/collision.h"

class Light //光源的基类
{
public:
	Light(const Color& c, data_type power = 1) : c(c), p(power), id(Constant::gen()) {}

	virtual ~Light() {}

	auto geti(void) const { return id; }
	auto getc(void) const { return c; }
	auto getp(void) const { return p; }

    virtual Vec3D getS(void) const = 0;
    virtual Collision collide(const Ray& ray) const = 0;
protected:
    Color c;                    // 颜色
    data_type p;                // 光能
    uint64 id;              // 标识符

};

#endif 
