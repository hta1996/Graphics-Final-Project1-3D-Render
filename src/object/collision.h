#ifndef COLLISION_H
#define COLLISION_H

#include "utility/ray.h"

class Light;
class Object;

struct Collision
{
    
    Collision() : t(1E8) {} // 不相交

    Collision(const Ray& r, data_type t, const Light *l);// 与光源相交
    Collision(const Ray& r, data_type t, const Vec3D& n, const Object* o, bool in, uint64 id = 0); //物体

    const Object* o;     // 相交的物体
    const Light* l;      // 相交的光源

    Ray r;               // 射线
    Vec3D p, n;          // 交点
    data_type t, u, v;   // 交点对应的射线参数，参数曲面
    bool in;             // 射线起点是否在物体内部（可选）
    uint64 id;           // 相交物体标识符

    bool isHit(void) const { return t <= 5E7; }      // 是否有交点
    bool atO(void) const { return o != nullptr; }
    bool atL(void) const { return l != nullptr; }
};

#endif
