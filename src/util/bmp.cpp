#include "bmp.h"

Bmp::Bmp(int w, int h, const Color& background) : w(w), h(h)
{
    data = new Bmp::RGB*[w];
    for (int i = 0; i < w; i++)
    {
    	data[i] = new Bmp::RGB[h];
    	for (int j = 0; j < h; j++)
    		setc(i, j, background);
  	}
  	memset(&bf, 0, sizeof(bf));
    memset(&bi, 0, sizeof(bi));

    bf.bfType = 0x4D42;
    bf.bfSize = (w * 3 + w % 4) * h + 54;
    bf.bfOffBits = 54;

    bi.biSize = 40;
    bi.biWidth = w;
    bi.biHeight = h;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
}

Bmp::Bmp(const string& file) : w(0), h(0), file_name(file)
{
    FILE* f = fopen(file.c_str(), "rb");
    if (!f)
    {
        std::cerr << "ERROR: No such BMP file '" + file + "'" << std::endl;
        exit(0);
    }

    fread(&bf, 1, sizeof(BITMAPFILEHEADER), f);
    fread(&bi, 1, sizeof(BITMAPINFOHEADER), f);

    w = bi.biWidth, h = bi.biHeight;
    data = new Bmp::RGB*[w];
    for (int i = 0; i < w; i++) data[i] = new Bmp::RGB[h];

    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            fread(&data[i][j].b, 1, sizeof(byte), f);
            fread(&data[i][j].g, 1, sizeof(byte), f);
            fread(&data[i][j].r, 1, sizeof(byte), f);
        }
        for (int i = 0; i < w % 4; i++) fgetc(f);
    }
    fclose(f);
}

	
