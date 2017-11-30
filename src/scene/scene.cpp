#include "scene/scene.h"
#include "object/object_all.h"
#include "light/light_all.h"

Scene::Scene(Camera *camera, const Color& ambient) : camera(camera), ambient(ambient) { /*init();*/ }
Scene::Scene(string sceneFile) : sceneFile(sceneFile)
{
    YAML::Node file = YAML::LoadFile(sceneFile);
    file["name"] >> name;
    file["ambient"] >> ambient;

    /*cout << name << endl;
    cout << ambient << endl;
    cout << file["lights"] << endl;
    cout << file["objects"][0] << endl;*/
    camera = new Camera;
    file["camera"] >> *camera;

    cout << *camera << endl;

    //cout << file["lights"] << endl;
    for (auto x : file["lights"])
    {
        //cout << x["AreaLight"] << endl;
        if (x["AreaLight"]) addL(new ALight(x["AreaLight"]));

        /*
        else if (x["PointLight"])
        {
            PLight *l = new ALight;
            x["AreaLight"] >> *l;
            addL(l);
        }*/
    }
    //cout << lights.size() << ' '  << objects.size() << endl;
    for (auto x : file["objects"])
    {
        //cout << x << endl;
        if (x["Plane"]) addO(new Plane(x["Plane"]));
        else if (x["Sphere"]) addO(new Sphere(x["Sphere"]));
    }
    //cout << lights.size() << ' '  << objects.size() << endl;
}


Scene::~Scene()
{
    if (camera) delete camera;
    for (auto x : lights) delete x;
    for (auto x : objects) delete x;
    lights.clear(), objects.clear();
}

/*

Scene::Scene(const Json::Value& scene)
    : m_camera(new Camera(scene["camera"])), m_ambient_color(scene["ambient_color"])
{
    for (auto l : scene["lights"])
    {
        Light* light = Light::loadFromJson(l);
        if (light) m_lights.push_back(light);
    }
    for (auto o : scene["objects"])
    {
        Object* object;
        if (o.isString())
            object = Object::loadFrom(m_scene_file_dir + "/" + o.asString());
        else
            object = Object::loadFromJson(o);
        if (object) m_objects.push_back(object);
    }

    Json::Value config = scene["config"];
    if (config.isString())
        Config::loadFrom(m_scene_file_dir + "/" + config.asString());
    else if (!config.isNull())
        Config::load(config);

    m_init();
}
*/


 
Collision Scene::findC(const Ray& ray) const
{
   
    Collision ret;
    for (auto x : lights)
    {
        Collision s = x->collide(ray);
        if (s.isHit() && s.t + EPS < ret.t) ret = s;
    }
    for (auto o : objects)
    {
        Collision s = o->collide(ray);
        if (s.isHit() && s.t + EPS < ret.t) ret = s;
    }
    return ret;
}

/*
void Scene::save(const string& file) const
{
    std::ofstream fout(file.c_str());
    fout << this->toJson() << std::endl;
    fout.close();
}

Scene* Scene::loadFrom(const std::string& file)
{
    Json::Value scene;
    std::ifstream fin(file.c_str());
    if (!fin)
    {
        std::cerr << "ERROR: No such scene file '" + file + "'" << std::endl;
        return nullptr;
    }
    fin >> scene;
    fin.close();

    m_scene_file_dir = file.substr(0, file.find_last_of('/'));
    return new Scene(scene);
}*/
/*
void Scene::init(void)
{
	sort(objects.begin(), objects.end());
}

void Scene::m_init()
{
    // 反射光比例小的物体优先，其次折射光
    sort(m_objects.begin(), m_objects.end(), [](const Object* A, const Object* B) {
        return A->getMaterial()->compare(B->getMaterial());
    });
}
*/