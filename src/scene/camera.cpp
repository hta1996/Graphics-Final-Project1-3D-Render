#include "scene/camera.h"
#include "utility/ray.h"
#include "utility/bmp.h"

Camera::Camera(const Vec3D& o, const Vec3D& vp, const Vec3D& up, const int& w, const int& h, const data_type& fov):
    o(o), vp(vp), up(up), w(w), h(h), fov(fov)
{
    init();
}


Camera::~Camera()
{
	for (int i = 0; i < w; i++) delete[] c[i];
	delete[] c;
}


void Camera::save(const string& file) const
{
    Bmp* bmp = new Bmp(w, h);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            bmp->setC(i, j, c[i][j].normal());
    bmp->save(file);
    delete bmp;
}

void Camera::cache(const string& file) const
{
    static int cnt = 0;
    cnt++;
    Bmp* bmp = new Bmp(w, h);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            bmp->setC(i, j, c[i][j].normal());
    bmp->save(file + to_string((cnt + 999) / 1000));
    delete bmp;
}

Bmp* Camera::toBmp() const
{
    Bmp* bmp = new Bmp(w, h);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            bmp->setC(i, j, getC(i, j));
    return bmp;
}

void Camera::init(void)
{
    fov *= Constant::PI / 180;
	d = (vp - o).unit();
	dw = (d * up).unit() * tan(fov / 2) * (1.0 * w / h);
	dh = (d * dw).unit() * tan(fov / 2);
	c = new Color* [w];
	for (int i = 0; i < w; i++) c[i] = new Color[h];
}

void Camera::fromBmp(const Bmp* bmp)
{
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
        	setC(i, j, bmp->getC(i, j));
}

void operator >> (const YAML::Node& x, Camera &y)
{
    //cout << x << endl;
	x["eye"] >> y.o;
	x["viewpoint"] >> y.vp;
	x["fovy"] >> y.fov;
	x["h"] >> y.h;
	x["w"] >> y.w;
	x["up"] >> y.up;

	y.init();
}

std::ostream& operator << (std::ostream& out, const Camera& c)
{
    return out << "[o = " << c.o << ", d = "  << c.d << ", w = " << c.w << ", h = " << c.h
               << ", dw = " << c.dw << ", dh = " << c.dh << ']';
}  