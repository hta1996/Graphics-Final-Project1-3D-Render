#include "raytracer.h"
using Constant::OUTPUT_PT;
using Constant::RT_THERASHOLD;
using Constant::RT_MAXDEP;

RayTracer::RayTracer(Scene* scene): Engine(scene)
{
    if (!scene) return ;
}
RayTracer::~RayTracer()
{
    if (!scene) return ;
}

inline double gettime(clock_t x)
{
    double s = 1.0 * (clock() - x) / CLOCKS_PER_SEC;
    return s;
}

void RayTracer::run(const string& outFile)
{
    if (!scene) return;
    cout << "The Ray tracing starts!" << endl;
    clock_t lastr = clock(), bts = clock();
    for (int i = 0; i < w; i++)
    {
    	clock_t tbi = clock();
    	x = i;
    	for (int j = 0; j < h; j++)
    	{
    		y = j;
            // 1333 357
           // if (i == 860 && j == 730)
            {
                camera->setC(i, j, getPixel(i, j));   
               // cout << camera->getC(i, j) << endl;
            }
            //if (i == 0 && j == 20) return ;
    	}
        //cout << "Ray tracing: column " << i << ' ' <<  gettime(tbi) << endl;
        if (OUTPUT_PT > 0 && clock() - lastr > OUTPUT_PT * CLOCKS_PER_SEC)
            camera->cache(outFile), lastr = clock();
    }
    cout << "Total Tracing Time: " << gettime(bts) << endl; bts = clock();
    camera->save(outFile);
    cout << "Total Saving Time: " << gettime(bts) << endl;


/*
    

    if (Config::anti_aliasing_samples)
    {
        cout << "Smoothing..." << endl;

        vector<pair<int, int>> list;
        switch (Config::anti_aliasing_edge_detection_mode)
        {
        case 0: // 根据不同物体
            for (int i = 0; i < m_w; i++)
                for (int j = 0; j < m_h; j++)
                {
                    m_is_edge[i][j] = false;
                    if (i < m_w - 1 && j < m_h - 1)
                        if (m_hash[i][j] != m_hash[i + 1][j + 1] || m_hash[i + 1][j] != m_hash[i][j + 1])
                        {
                            list.push_back(make_pair(i, j));
                            list.push_back(make_pair(i + 1, j + 1));
                            list.push_back(make_pair(i + 1, j));
                            list.push_back(make_pair(i, j + 1));
                        }
                }
            sort(list.begin(), list.end());
            list.erase(unique(list.begin(), list.end()), list.end());
            break;
        case 1: // 根据相邻像素色差
            list = m_camera->detectEdge();
            break;
        default: // 全图采样
            for (int i = 0; i < m_w; i++)
                for (int j = 0; j < m_h; j++) list.push_back(make_pair(i, j));
            break;
        }

        lastRefreshTime = clock();
        for (size_t t = 0; t < list.size(); t++)
        {
            if (!t || list[t].first != list[t - 1].first)
                cout << "Smoothing: column " << list[t].first << endl;

            m_is_edge[list[t].first][list[t].second] = true;
            m_camera->setColor(list[t].first, list[t].second, m_AASamplingColor(list[t].first, list[t].second));

            if (Config::output_refresh_interval > 0 &&
                clock() - lastRefreshTime > Config::output_refresh_interval * CLOCKS_PER_SEC)
            {
                lastRefreshTime = clock();
                m_camera->print(outFile.c_str());
            }
        }

        m_camera->print(outFile.c_str());
    }*/
}

Color RayTracer::getPixel(data_type xx, data_type yy, data_type factor) const
{
    return rayTrace(camera->emit(xx, yy), Color(1, 1, 1) * factor, 1, 1);
}

Color RayTracer::getlocal(const Collision& co, const Material* com, const Color& factor) const
{
    Color c = com->c.mul(co.o->getT(co));      //注意纹理和颜色中必有一个全部都是1
    Color ret = c.mul(scene->getA()) * com->fd; //环境光
    for (auto x : scene->getL()) //所有的光
    {
        Vec3D l = (x->getS() - co.p).unit();
        if (l.dot(co.n) < EPS) continue; //光几乎和物体相切

        //阴影
        data_type shade = x->getSR(scene, co.p);
        if (shade > EPS)
            ret += c.mul(x->getC() * (com->BRDF(l, co.n, co.r.d) * shade));
    }
    return ret.mul(factor);
}

Color RayTracer::rayTrace(const Ray& ray, const Color& factor, data_type weight, int depth) const
{
    if (weight < Constant::RT_THERASHOLD || depth > Constant::RT_MAXDEP)
        return Color();
    //cout <<"Begin   "<< ray << ' ' << factor << ' '  << weight << ' ' << depth << endl;
    Collision co = scene->findC(ray);
    if (!co.isHit())
    {
        //cout << "1" << ' ' << scene->getA().mul(factor) << endl;
        return scene->getA().mul(factor); //环境光
    }
    else if (co.atL())
    {
        //cout << "2" << ' ' << co.l->getC().mul(factor) << endl;
        return co.l->getC().mul(factor); //击中光源
    }
    else //考虑物体的情况
    {
        //cout << "3" << endl;
        Color ret(0, 0, 0), absorb(1, 1, 1);
        depth++;
        const Object *x = co.o;
        const Material *m = x->getM();

        //光线在物体内部会有颜色损失
        if (co.in) absorb = (m->ac * -co.t).exp();

        //源自光源的漫反射
        if (m->fd > EPS || m->fs > EPS) ret += getlocal(co, m, factor.mul(absorb));

       // cout <<1 << ' ' << absorb << ' ' << factor << ' ' << ret << ' ' << x->getN() << endl;
      //  cout << "2 " << m->fl << ' ' << m->fr << endl;

        if (m->fl > EPS || m->fr > EPS)
        {
            data_type n = co.in ? 1 / m->ri : m->ri, fl = m->fl, fr = m->fr;
            Vec3D vfl = co.r.d.reflect(co.n), vfr = co.r.d.refract(co.n, n);

        //   cout << "3 " << n << ' ' << vfl << ' ' << vfr << endl;

            if (fr < EPS) //全镜面反射
                ret += rayTrace(Ray(co.p, vfl), factor.mul(absorb.mul(m->c) * fl), weight * fl, depth);
            else if (vfr.len2() < EPS) //全反射
            {
                data_type k = m->fl + m->fr;
                ret += rayTrace(Ray(co.p, vfl), factor.mul(absorb.mul(m->c) * k), weight * k, depth);
            }
            else if (fl < EPS) //全透明材料
                ret += rayTrace(Ray(co.p, vfr), factor.mul(absorb.mul(m->c) * fr), weight * fr, depth);
            else
            {
                if (fl > EPS)
                    ret += rayTrace(Ray(co.p, vfl), factor.mul(absorb.mul(m->c) * fl), weight * fl, depth);
                if (fr > EPS)
                    ret += rayTrace(Ray(co.p, vfr), factor.mul(absorb.mul(m->c) * fr), weight * fr, depth);
            }
        }
        return ret;
    }
}
/*
           

Color RayTracer::m_DOFSamplingColor(double ox, double oy, double factor) const
{
    if (!m_camera->enableDOF())
        return m_rayTrace(m_camera->emit(ox, oy), Color(1, 1, 1) * factor, 1, 1);

    Color color;
    for (int i = 0; i < Config::depth_of_field_samples; i++)
        color += m_rayTrace(m_camera->dofEmit(ox, oy), Color(1, 1, 1) * factor / Config::depth_of_field_samples, 1, 1);
    return color;
}

Color RayTracer::m_AASamplingColor(int ox, int oy)
{
    m_pixel_x = ox, m_pixel_y = oy;
    if (!Config::anti_aliasing_samples)
        return m_DOFSamplingColor(ox, oy);

    vector<pair<double, double>> points;
    int samples = Config::anti_aliasing_samples;
    for (int i = 0; i < samples * 2; i++)
        for (int j = 0; j < samples * 2; j++)
        {
            // 旋转网格采样
            double a = atan(0.5);
            double x = (i + 0.5) / samples - 1,
                   y = (j + 0.5) / samples - 1;
            double dx = x * cos(a) - y * sin(a),
                   dy = x * sin(a) + y * cos(a);
            if (dx > -0.5 && dx < 0.5 && dy > -0.5 && dy < 0.5)
                points.push_back(make_pair(ox + dx, oy + dy));
        }
    Color color;
    for (auto p : points)
        color += m_DOFSamplingColor(p.first, p.second, 1.0 / points.size());
    return color;
}

*/
