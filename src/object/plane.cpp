#include "plane.h"
/*void operator >> (const YAML::Node& x, Plane &y)
{
    x["name"] >> y.name;
    y.m = new Material;
    x["material"] >> *y.m;
    x["n"] >> y.n;
    x["o"] >> y.o;
}

Plane::Plane(const Vector3& n, double d, const Material* m)
    : Object(m), m_n(n.unitize()), m_d(d),
      m_o(0, 0, 0), m_dx(n.getAnVerticalVector()), m_dy((n * m_dx).unitize())
{
}

Plane::Plane(const Json::Value& object)
    : Object(object), m_n(object["n"]), m_d(object["d"].asDouble()),
      m_o(object["texture_o"]), m_dx(object["texture_dx"]), m_dy(object["texture_dy"])
{
}


Color Plane::getTextureColor(const Collision& coll) const
{
    if (m_material->hasTexture())
    {
        double u = (coll.p - m_o).dot(m_dx) / m_dx.mod2(),
               v = (coll.p - m_o).dot(m_dy) / m_dy.mod2();
        u -= floor(u), v -= floor(v);
        return m_material->getTextureColor(u, v);
    }
    else
        return Color(1, 1, 1);
}

Json::Value Plane::toJson() const
{
    Json::Value object = Object::toJson();
    object["type"] = "Plane";
    object["n"] = m_n.toJson();
    object["d"] = m_d;
    if (m_material->hasTexture())
    {
        object["texture_o"] = m_o.toJson();
        object["texture_dx"] = m_dx.toJson();
        object["texture_dy"] = m_dy.toJson();
    }
    return object;
}
*/