#ifndef SCENE_H
#define SCENE_H

//#include "utility/utility.h"
#include "light/light.h"
#include "object/object.h"
#include "scene/camera.h"

class Scene
{
public:
	Scene(){}
	Scene(Camera *camera, const Color& ambient = Color());
	Scene(string sceneFile);

	~Scene();
	
	Camera* getC(void) const { return camera; }
	Color getA(void) const { return ambient; }
	Light* getL(const int& x) const { return lights[x]; }
	Object* getO(const int& x) const { return objects[x]; }
	const auto& getL(void) const { return lights; }
	const auto& getO(void) const { return objects; }


	void addL(Light* x) { lights.push_back(x); }
	void addO(Object* x) { objects.push_back(x); }
	Collision findC(const Ray& ray) const; //找第一次碰撞


private: 
	Camera *camera;                     // 相机
    Color ambient;                      // 环境光
    vector < Light* > lights;           // 光源
    vector < Object* > objects;         // 物体
    string name, sceneFile;                        // 场景的名称
    
    //static std::string m_scene_file_dir; // 场景文件路径
   // void init();

};


    // 寻找视线最先碰到的物体或光源
   // Collision findNearestCollision(const Ray& ray) const;



#endif
