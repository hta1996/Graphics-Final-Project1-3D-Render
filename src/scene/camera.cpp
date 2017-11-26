#include "camera.h"

void Camera::init(void)
{
	dw = (d * up).unit() * tan(fov / 2) * (1.0 * w / h);
	dh = (d * dw).unit() * tan(fov / 2);
	c = new Color* [w];
	for (int i = 0; i < w; i++) c[i] = new Color[h];
}

void Camera::fromBmp(const Bmp* bmp)
{
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
        	setc(i, j, bmp->getc(i, j));
}