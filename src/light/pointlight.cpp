#include "pointlight.h"
#include "scene/scene.h"

data_type PLight::getSR(const Scene* scene, const Vec3D& p) const
{
    Vec3D dir = o - p; data_type dis = dir.len();
    for (auto o : scene->getO())
    {
        Collision co = o->collide(Ray(p, dir));
        if (co.isHit() && co.t + EPS < dis) return 0;
    }
    return 1;
}


/*
#include "common/const.h"

#include "object/object.h"
#include "scene/scene.h"

Collision PointLight::collide(const Ray& ray) const
{
    return Collision(); // 点光源永远不会与视线相交
}

double PointLight::getShadowRatio(const Scene* scene, const Vector3& p) const
{
    Vector3 dir = m_o - p;
    double dist = dir.mod();
    for (auto o = scene->objectsBegin(); o != scene->objectsEnd(); o++)
    {
        Collision coll = (*o)->collide(Ray(p, dir));
        if (coll.isHit() && coll.dist + Const::EPS < dist) return 0;
    }
    return 1;
}

Photon PointLight::emitPhoton(double power) const
{
    return Photon(m_o, Vector3::randVector(), m_color * power);
}

Json::Value PointLight::toJson() const
{
    Json::Value light = Light::toJson();
    light["type"] = "PointLight";
    light["o"] = m_o.toJson();
    return light;
}
*/