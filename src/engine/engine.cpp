#include "engine/engine.h"

Engine::Engine(Scene *scene) : scene(scene), camera(NULL), w(0), h(0)
{
	if (scene)
	{
		camera = scene->getC();
		w = camera->getW();
		h = camera->getH();
		cout << w << ' ' << h;
	}
}
