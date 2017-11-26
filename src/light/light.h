#ifndef LIGHT_H
#define LIGHT_H

#include "util/ray.h"
#include "util/color.h"
#include "object/collision.h"

class Light //光源的基类
{
public:
	Light(const Color& c, data_type power = 1) : color(c), power(power), identifier(Constant::gen()) {}

	virtual ~Light() {}

	auto getI(void) const { return identifier; }
	auto getC(void) const { return color; }
	auto getP(void) const { return power; }

    virtual Vec3D getS(void) const = 0;
    virtual Collision collide(const Ray& ray) const = 0;
protected:
    Color color;                    // 颜色
    data_type power;                // 光能
    uint64 identifier;              // 标识符

};

#endif 
