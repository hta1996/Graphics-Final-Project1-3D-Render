#ifndef AREALIGHT_H
#define AREALIGHT_H

#include "light/light.h"

class ALight : public Light
{
public:
	ALight(){}
	ALight(const Color& c, const Vec3D& o, const Vec3D& dx, const Vec3D& dy, data_type p = 1)
        : Light(c, p), o(o), dx(dx), dy(dy) { n = dx * dy; }
    ALight(const YAML::Node& x)
    {	
	    x["name"] >> name;
	    x["color"] >> c;
	    x["n"] >> n;
	    x["o"] >> o;
	    x["dx"] >> dx;
	    x["dy"] >> dy;
	    x["power"] >> p;
	    id = Constant::gen();
    }

    virtual Vec3D getS(void) const override { return o; }

    virtual data_type getSR(const Scene* scene, const Vec3D& p) const override;

    virtual Collision collide(const Ray& ray) const override
	{
	    data_type cost = n.dot(ray.d);
	    if (abs(cost) < EPS) return Collision(); //射线和面几乎平行
	    data_type t = (n.dot(o - ray.o)) / cost;
	    if (t < EPS) return Collision();            //在光源背面
	    Vec3D p = ray.get(t) - o;
	    if (abs(p.dot(dx)) + EPS < dx.len2() && abs(p.dot(dy)) + EPS < dy.len2()) //交点是不是在光源面内部
	        return Collision(ray, t, this);
	    else
	        return Collision();
	}

    //friend void operator >> (const YAML::Node& x, ALight &y);

private:
    Vec3D o, n, dx, dy;   // 矩形中心点，光源朝向，横向，纵向向量
};

#endif
