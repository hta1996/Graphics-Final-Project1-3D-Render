#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "engine/engine.h"

class RayTracer : public Engine
{
public:
    RayTracer(Scene* scene);
    virtual ~RayTracer();
    virtual void run(const std::string& outFile) override;

protected:
//    uint64** hash;          // 光线经过物体的 HASH 值，优化 SSAA
//    bool** is_edge;         // 是否是物体边缘
    int x, y; // 每次跟踪时像素的位置

    Color rayTrace(const Ray& ray, const Color& factor, data_type weight, int depth) const;

    Color getPixel(data_type xx, data_type yy, data_type factor = 1) const;

    virtual Color getlocal(const Collision& co, const Material* com, const Color& f) const; // 处理漫反射

    // 跟踪光线
    

    // 景深采样
    //Color DOFSamplingColor(double ox, double oy, double factor = 1) const;

    // 抗锯齿采样
    //Color AASamplingColor(int ox, int oy);*/
};

#endif
