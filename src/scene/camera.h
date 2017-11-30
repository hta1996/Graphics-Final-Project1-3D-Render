#ifndef CAMERA_H
#define CAMERA_H

//#include <scene.h>
#include "utility/vector3D.h"
#include "utility/color.h"
#include "utility/ray.h"

class Bmp;

class Camera
{
public:
    Camera() {}
	Camera(const Vec3D& o, const Vec3D& vp, const Vec3D& up, const int& w, const int& h, const data_type& fov);
	~Camera();

    int getH(void) const { return h; }
    int getW(void) const { return w; }
    Vec3D getO(void) const { return o; }
    Vec3D getD(void) const { return d; }
    void setC(const int& x, const int& y, const Color& cc) { c[x][y] = cc; }

    inline Color getC(const int& x, const int& y) const;

    inline Ray emit(data_type x, data_type y) const;

    void save(const string& file) const;

    void cache(const string& file) const;

    Bmp* toBmp() const;

    void fromBmp(const Bmp* film);

    //bool enableDOF() const;

    // 处理景深时的发射光线
   // Ray dofEmit(double x, double y) const;


    // 边缘检测
   // std::vector<std::pair<int, int>> detectEdge() const;

    friend void operator >> (const YAML::Node& x, Camera &y);
    friend std::ostream& operator << (std::ostream& out, const Camera& c);

private:
    Vec3D o, d, vp, up, dw, dh; //相机位置，视线方向，视点，向上的方向, 视平面的坐标系
    int w, h;                   //像素
    data_type fov;              //视角
    Color** c;                  //视平面(距离o的距离为1，焦平面距离为2)
    void init(void);
};

//inline 函数得在一个文件中实现
Ray Camera::emit(data_type x, data_type y) const
{
    return Ray(o, d + dw * (2.0 * x / w - 1) + dh * (2.0 * y / h - 1));
}

Color Camera::getC(const int& x, const int& y) const
{
    return 0 <= x && x <= w && 0 <= y && y <= h ? c[x][y] : Color();
}

#endif
