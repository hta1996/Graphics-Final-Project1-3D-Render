#ifndef BMP_H
#define BMP_H

#include "utility/constant.h"
#include "utility/color.h"

class Bmp //用来保存输出的图片
{
public:
	Bmp(int w, int h, const Color& background = Color());
 	Bmp(const std::string& file);
	~Bmp() { for (int i = 0; i < w; i++) delete[] data[i]; delete[] data; }

	int getW(void) const { return w; }
	int getH(void) const { return h; }
	Color getC(int x, int y) const { return Color(data[x][y].r, data[x][y].g, data[x][y].b) / 255; }
	inline Color getC(double x, double y) const;
	
	void setC(int x, int y, const Color& c) { data[x][y] = RGB(c.r * 255 + 0.5, c.g * 255 + 0.5, c.b * 255 + 0.5); }
	inline void save(const std::string &file) const;
	
	

private:
    typedef unsigned char byte;
    typedef unsigned short word;
    typedef unsigned int dword;

#pragma pack(push, 1)
    struct BITMAPFILEHEADER
    {
        word bfType;
        dword bfSize;
        word bfReserved1;
        word bfReserved2;
        dword bfOffBits;
    };
    struct BITMAPINFOHEADER
    {
        dword biSize;
        dword biWidth;
        dword biHeight;
        word biPlanes;
        word biBitCount;
        dword biCompression;
        dword biSizeImage;
        dword biXPelsPerMeter;
        dword biYPelsPerMeter;
        dword biClrUsed;
        dword biClrImportant;
    };
#pragma pack(pop)

	typedef Vector3D<byte> RGB;
	
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
	int w, h;
	RGB** data;
    std::string file_name;
	
	void set(RGB& x, const Color& c) { x = RGB(c.r * 255 + 0.5, c.g * 255 + 0.5, c.b * 255 + 0.5); }
};

Color Bmp::getC(double x, double y) const
{
    x *= w - 1, y *= h - 1;
    /*
    if (Config::enable_texture_filtering) // 双线性插值
    {
        int u1 = floor(u + Const::EPS), v1 = floor(v + Const::EPS),
            u2 = u1 + 1, v2 = v1 + 1;
        double ru = u2 - u, rv = v2 - v;
        if (u1 < 0) u1 = w - 1;
        if (v1 < 0) v1 = h - 1;
        if (u2 == w) u2 = 0;
        if (v2 == h) v2 = 0;
        return getColor(u1, v1) * (ru * rv) + getColor(u1, v2) * (ru * (1 - rv)) +
               getColor(u2, v1) * ((1 - ru) * rv) + getColor(u2, v2) * ((1 - ru) * (1 - rv));
    }
*/
    return getC(int(x + 0.5), int(y + 0.5));
}

void Bmp::save(const string& file) const
{
    FILE* f = fopen(file.c_str(), "wb");

    fwrite(&bf, 1, sizeof(BITMAPFILEHEADER), f);
    fwrite(&bi, 1, sizeof(BITMAPINFOHEADER), f);

    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            fwrite(&data[i][j].b, 1, sizeof(byte), f);
            fwrite(&data[i][j].g, 1, sizeof(byte), f);
            fwrite(&data[i][j].r, 1, sizeof(byte), f);
        }
        for (int i = 0; i < w % 4; i++) fputc(0, f);
    }

    fclose(f);
}


#endif
