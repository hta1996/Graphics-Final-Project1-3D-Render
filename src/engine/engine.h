#ifndef ENGINE_H
#define ENGINE_H

#include "scene/scene.h"
#include "scene/camera.h"

class Scene;
class Camera;

class Engine //渲染使用的引擎
{
public: 
	virtual ~Engine() {}

	virtual void run(const string& outFile) = 0;

protected:
	Scene *scene;
	Camera *camera;
	int w, h;

	Engine(Scene *scene);
};

#endif
