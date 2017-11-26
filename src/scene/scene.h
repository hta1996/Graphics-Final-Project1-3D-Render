#ifndef SCENE_H
#define SCENE_H

#include "light/light.h"
#include "object/object.h"
#include "camera.h"

class Scene
{
public:
	Scene(Camera *camera, const Color& ambient = Color()) : camera(camera), ambient(ambient) { /*init();*/ }

	~Scene()
	{
		if (camera) delete camera;
		for (auto x : lights) delete x;
		for (auto x : objects) delete x;
		lights.clear(), objects.clear();
	}

	Camera* getc(void) const { return camera; }
	Color geta(void) const { return ambient; }
	Light* getl(const int& x) const { return lights[x]; }
	Object* geto(const int& x) const { return objects[x]; }
	const auto getl(void) const { return lights; }
	const auto geto(void) const { return objects; }	

	void addl(Light* x) { lights.push_back(x); }
	void addo(Object* x) { objects.push_back(x); }
	//Collision findC(const Ray& ray) const; //找第一次碰撞


private: 
	Camera *camera;                     // 相机
    Color ambient;                      // 环境光
    vector < Light* > lights;           // 光源
    vector < Object* > objects;         // 物体

    //static std::string m_scene_file_dir; // 场景文件路径

   // void init();

};


    // 寻找视线最先碰到的物体或光源
   // Collision findNearestCollision(const Ray& ray) const;



#endif
