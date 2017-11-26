#ifndef ENGINE_H
#define ENGINE_H

#include "scene/scene.h"

class Engine //渲染使用的引擎
{
public: 
	virtual ~Engine() {}

	virtual void run(const string& outFile) = 0;

protected:
	Scene *scene;
	Camera *camera;
	int w, h;

	Engine(Scene *scene) : scene(scene), camera(NULL), w(0), h(0)
	{
		if (scene)
		{
			camera = scene->getc();
			w = camera->getW();
			h = camera->getH();
		}
	}
};

#endif
