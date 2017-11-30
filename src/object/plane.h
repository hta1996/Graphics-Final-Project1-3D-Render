#ifndef PLANE_H
#define PLANE_H

#include "utility/ray.h"
#include "object.h"

class Plane : public Object
{
public:
    Plane() : Object() {}
    Plane(const Vec3D& nn, const Vec3D& o, const Material* m = nullptr): Object(m), n(nn.unit()), o(o)
    { tx = n.genVert(), ty = n * tx; }
    Plane(const YAML::Node& x)
    {
        x["name"] >> name;
       // cout << x["name"] << endl;
       // cout << x["material"];
        m = new Material(x["material"]);
        x["n"] >> n;
        x["o"] >> o;
    }

    virtual string getT(void) const override { return "Plane"; }
    
    virtual Collision collide(const Ray& ray) const override //和面光源类似
    {
        data_type cost = n.dot(ray.d);
        if (abs(cost) < EPS) return Collision();
        data_type t = (n.dot(o - ray.o)) / cost;
        if (t < EPS) return Collision();
        if (cost > EPS) return Collision(ray, t, n, this, false);
        else return Collision(ray, t, n, this, true);
    }
    virtual Color getT(const Collision& co) const override
    {
        if (m->hasT())
        {
            
        }
        else return Color(1, 1, 1);
    }
    //friend void operator >> (const YAML::Node& x, Plane &y);

/*
    // 交点处的纹理颜色
    virtual Color getTextureColor(const Collision& coll) const override;

    // 设置纹理坐标轴
    void setTextureAxis(const Vector3& o, const Vector3& dx, const Vector3& dy) { m_o = o, m_dx = dx, m_dy = dy; }
*/
private:
    Vec3D n, o;                  // 法向量(直线方程为 n * (P - o) = 0  <=> n * P - n * o = 0)
    Vec3D to, tx, ty;         // 纹理原点和坐标轴向量
};

#endif 
