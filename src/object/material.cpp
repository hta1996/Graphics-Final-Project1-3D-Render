#include "material.h"
const Material* Material::DEFAULT = new Material();
/*
void operator >> (const YAML::Node& x, Material &y)
{
    x["color"] >> y.c;
    x["diffuse"] >> y.fd;
    x["reflect"] >> y.fl;
    x["refraction"] >> y.fr;
    x["refract_index"] >> y.ri;
    x["mirror"] >> y.fs;
}

/*
Material::Material(const Json::Value material)
    : color(material["color"]), absorb_color(material["absorb_color"]),
      diff(material["diff"].asDouble()), spec(material["spec"].asDouble()), refl(material["refl"].asDouble()),
      refr(material["refr"].asDouble()), rindex(material["refr_index"].isNull() ? 1 : material["refr_index"].asDouble()),
      m_texture(nullptr), m_texture_func(nullptr)
{
    if (material["texture"].isString())
        m_texture = new Bmp(material["texture"].asString());
}

Material::~Material()
{
    if (m_texture) delete m_texture;
}

Color Material::getTextureColor(double u, double v) const
{
    if (m_texture)
        return m_texture->getColor(u, v);
    else if (m_texture_func)
        return m_texture_func(u, v);
    else
        return Color(1, 1, 1);
}

bool Material::compare(const Material* B) const
{
    return this->refl + Const::EPS < B->refl ||
           (std::abs(this->refl - B->refl) < Const::EPS && this->refr + Const::EPS < B->refr);
}

double Material::BRDF(const Vector3& l, const Vector3& n, const Vector3& v) const
{
    Vector3 r = l.reflect(n);
    return diff * l.dot(n) + spec * pow(v.dot(r), Config::hightlight_exponent);
}

Json::Value Material::toJson() const
{
    Json::Value material;
    material["color"] = color.toJson();
    material["diff"] = diff;
    material["spec"] = spec;
    if (refl > Const::EPS) material["refl"] = refl;
    if (refr > Const::EPS)
    {
        material["refr"] = refr;
        material["refr_index"] = rindex;
        material["absorb_color"] = absorb_color.toJson();
    }
    if (m_texture)
        material["texture"] = m_texture->getFilename();
    else if (m_texture_func)
        material["texture_func"] = "Function";
    return material;
}
*/
