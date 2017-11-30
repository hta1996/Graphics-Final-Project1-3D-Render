#ifndef LIGHT_H
#define LIGHT_H

#include "utility/ray.h"
#include "utility/color.h"
#include "object/collision.h"

class Scene;
class Light //光源的基类
{
public:
	Light() {}
	Light(const Color& c, data_type power = 1) : c(c), p(power), id(Constant::gen()) {}

	virtual ~Light() {}

	auto getI(void) const { return id; }
	auto getC(void) const { return c; }
	auto getP(void) const { return p; }

    virtual Vec3D getS(void) const = 0;
    virtual Collision collide(const Ray& ray) const = 0;
    virtual data_type getSR(const Scene* scene, const Vec3D& p) const = 0;
protected:
    Color c;                    // 颜色
    data_type p;                // 光能
    uint64 id;              // 标识符
    string name;
};

#endif 
