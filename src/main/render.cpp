#include "engine/raytracer/raytracer.h"
#include <fstream>
#include <iostream>

void showUsage(void)
{
	cout << "Usage: ./render [Options] <SCENE_FILE> -o <PICTURE_OUTPUT_FILE>." << endl;
	cout << "Options:" << endl;
	cout << "--help                 Show this information" << endl;
	cout << "--debug                For debugging, and do not need to give other inputs. " << endl;
	cout << "-e <engine>            Select the engine. Available engine list:" << endl;
	cout << "                         0: Ray tracing (default)." << endl;
	cout << "                         1: Photon mapping." << endl;
	cout << "                         2: PPM." << endl;
	cout << "                         3: SPPM." << endl;
	cout << "The final result will use SPPM, and the others are for debugging." << endl;
	exit(0);
}

void do_debug(void)
{
	Vec3D eye(0, 0, -1), vp(0, 0, 1), up(0, 1, 0);
	Camera camera(eye, vp, up, 100, 100, 45);
	std::cout << camera.emit(60, 60) << std::endl;
	exit(0);
}

int main(int argc, char *argv[])
{
	int engine_id = 0;
	string sceneFile = "", outFile = "";

	if (string(argv[1]).substr(0, 3) == "--d") do_debug();

	if (argc > 1) sceneFile = argv[1];
/*	for (int i = 0; i < argc; i++)
	{
		auto x = argv[i];
		if (!x) { printf ("%d???\n", i); continue; }
		printf ("%d %s\n", i, x);
	}*/
	for (int i = 2; i < argc; i++)
	{
		string x = string(argv[i]);
		if (x == string("-e"))
			if (i + 1 < argc && '0' <= argv[i + 1][0] && argv[i + 1][0] <= '2')
				engine_id = argv[++i][0] - '0';
			else showUsage();
		else if (x == string("-o"))
			if (i + 1 < argc) outFile = argv[++i];
			else showUsage();
		else if (x.substr(0, 3) == string("--h")) showUsage();
	}
	if (!sceneFile.length() || !outFile.length()) showUsage();

	std::ifstream fin(sceneFile);
	if (!fin) cout << "Error" << endl << std::flush;

	srand(time(0));
	Engine *engine;
	Scene *scene = new Scene (sceneFile);

	//fin(outFile);
	//cout << fin  << endl;

	switch(engine_id)
	{
		case 0: engine = new RayTracer(scene); break;
		//case 1: engine = new PM(scene); break;
		//case 2: engine = new PPM(scene); break;
		//case 3: engine = new SPPM(scene); break;
	}
    engine->run(outFile);
    if (scene) delete scene;
    delete engine;
    //*/
	return 0;
}