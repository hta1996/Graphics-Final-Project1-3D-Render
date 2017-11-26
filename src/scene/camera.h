#ifndef CAMERA_H
#define CAMERA_H

//#include <scene.h>
#include "util/ray.h"
#include "util/bmp.h"


class Camera
{
public:
	Camera(const Vec3D& o, const Vec3D& vp, const Vec3D& up, const int& w, const int& h, 
        const data_type& fov):
    o(o), vp(vp), up(up), w(w), h(h), fov(fov)
    {
        d = (vp - o).unit();
        init();
    }
	~Camera()
	{
    	for (int i = 0; i < w; i++) delete[] c[i];
    	delete[] c;
	}
    int getH(void) const { return h; }
    int getW(void) const { return w; }
    Vec3D geto(void) const { return o; }
    Vec3D getd(void) const { return d; }
    Color getc(const int& x, const int& y) const { return 0 <= x && x <= w && 0 <= y && y <= h ? c[x][y] : Color(); }
    void setc(const int& x, const int& y, const Color& cc) { c[x][y] = cc; }

    Ray emit(data_type x, data_type y) const
    {
        return Ray(o, d + dw * (2.0 * x / w - 1) + dh * (2.0 * y / h - 1));
    }

    void save(const string& file) const
    {
        static int cnt = 0;
        static char str[100];
        cnt++;
        Bmp* bmp = new Bmp(w, h);
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
                bmp->setc(i, j, c[i][j].normal());
        itoa((cnt + 999) / 1000, str, 10);
        bmp->save(file + string(str));
        delete bmp;
    }

    Bmp* toBmp() const
    {
        Bmp* bmp = new Bmp(w, h);
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
                bmp->setc(i, j, getc(i, j));
        return bmp;
    }


    void fromBmp(const Bmp* film);

    //bool enableDOF() const;

    // 处理景深时的发射光线
   // Ray dofEmit(double x, double y) const;


    // 边缘检测
   // std::vector<std::pair<int, int>> detectEdge() const;


    

private:
    Vec3D o, d, vp, up, dw, dh; //相机位置，视线方向，视点，向上的方向, 视平面的坐标系
    int w, h;                   //像素
    data_type fov;              //视角
    Color** c;                  //视平面(距离o的距离为1，焦平面距离为2)
    void init(void);
};

#endif
