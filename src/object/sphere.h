#ifndef SPHERE_H
#define SPHERE_H

#include "object/object.h"

class Sphere : public Object
{
public:
    Sphere() : Object() {}
    Sphere(const Vec3D& o, data_type r, const Material* m = nullptr)
    : Object(m), o(o), r(r), dz(0, 0, 1), dx(1, 0, 0) { }

    Sphere(const YAML::Node& x)
    {
        x["name"] >> name;
        m = new Material(x["material"]);
        x["o"] >> o;
        x["r"] >> r;
    }

    virtual string getT() const override { return "Sphere"; }

    // 与视线相交
    virtual Collision collide(const Ray& ray) const override
    {
        Vec3D l = o - ray.o;
        data_type tp = tp = l.dot(ray.d), t = r * r + tp * tp - l.len2();
        if (t >= 0)
        {
            t = sqrt(t);
            data_type t1 = tp - t, t2 = tp + t;
            if (t1 > EPS) return Collision(ray, t1, ray.get(t1) - o, this, false);
            if (t2 > EPS) return Collision(ray, t2, o - ray.get(t2), this, true);
        }
        return Collision();
    }
    Color getT(const Collision& coll) const override
    {
        return Color(1, 1, 1);
    }
    friend void operator >> (const YAML::Node& x, Sphere &y);
/*
    // 交点处的纹理颜色
    virtual 


    // 设置纹理坐标轴
    void setTextureAxis(const Vector3& dz, const Vector3& dx) { m_dz = dz, m_dx = dx; }
*/
private:
    Vec3D o;        // 球心
    data_type r;         // 半径
    Vec3D dz, dx; // 北极向量和 0 度经线方向
};

#endif
