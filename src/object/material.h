#ifndef MATERIAL_H
#define MATERIAL_H

#include "utility/bmp.h"

class Material  //物体表面的材质
{
public:
    Color c, ac;                 // 颜色，透射时吸收的颜色
    data_type fd, fs;            // 漫反射系数，镜面反射系数
    data_type fl, fr, ri;        // 反射和折射光的比例,折射率
    const static Material* DEFAULT;

    Material(const YAML::Node& x) : Material()
    {
        //cout << ri << "----------------------" << endl;
        //Material();
   //     cout << ri << "----------------------" << endl;
        if (!x) return ;
     ///   cout << ri << "----------------------" << endl;
        x["color"] >> c;
        x["diffuse"] >> fd;
        //cout << "YES!!" << endl;
        x["reflect"] >> fl;
        //cout << "YES!!" << endl;
        x["refraction"] >> fr;
        x["refract_index"] >> ri;
        x["absorb_color"] >> ac;
        x["mirror"] >> fs;
       // if (x["refract_index"]) cout << "ERROR!!" << endl;
    //    cout << x << ' ' << x.size() << ' ' << x["color"].size()<< endl;
     //   cout << "!!!!ri: " << ri << ' ' << x["refract_index"] << endl;
    }

    //默认材质-白光
    Material(): c(1, 1, 1), ac(0, 0, 0), fd(0.8), fs(0.2), fl(0), fr(0), ri(1){}

    // 漫反射材质
    Material(const Color& c, data_type fd, data_type fs) : c(c), fd(fd), fs(fs), ri(1), ac()  { fl = fr = 0; }

    // 不透明反射材质
    Material(const Color& c, data_type fd, data_type fs, data_type fl) : c(c), fd(fd), fs(fs), fl(fl), ri(1), ac()
    { fr = 0; }

    // 透明材质
    Material(const Color& c, data_type fd, data_type fs, data_type fl, data_type fr, data_type ri, const Color& ac):
    c(c), fd(fd), fs(fs), fl(fl), fr(fr), ri(ri), ac(ac){}


    virtual ~Material(){}

    Color getc(data_type x, data_type y)
    {
        if (text == nullptr) return Color(1, 1, 1);
        else return text->getC(x, y);
    }
    bool hasT(void) const { return false; }
    /*
    bool hasTexture() const { return m_texture || m_texture_func; }

    void setTexture(Bmp* texture) { m_texture_func = nullptr, m_texture = texture; }
    void setTexture(Color (*func)(data_type, data_type))
    {
        if (m_texture) delete m_texture;
        m_texture = nullptr, m_texture_func = func;
    }

    // 获得纹理颜色
    Color getTextureColor(data_type u, data_type v) const;

    // 求交时的优先级
    bool compare(const Material* B) const;
    {

    }

    bool Material::compare(const Material* B) const
{
    return this->refl + Const::EPS < B->refl ||
           (std::abs(this->refl - B->refl) < Const::EPS && this->refr + Const::EPS < B->refr);
}*/

    data_type BRDF(const Vec3D& l, const Vec3D& n, const Vec3D& v) const //Phong模型
    {
        Vec3D r = l.reflect(n);
        return fd * l.dot(n) + fs * pow(v.dot(r), Constant::PHONG_S);
    }

    //virtual Json::Value toJson() const;

    friend void operator >> (const YAML::Node& x, Material &y);

private:
    Bmp *text;

    //Bmp* texture;                            // 纹理图片
    //Color (*m_texture_func)(data_type, data_type); // 纹理函数
};

#endif