#include "MyScene.h"
#include "TexturedSphere.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

#ifdef __APPLE__
    TexturedSphere *ts = new TexturedSphere("./full_map_surface.bmp");
#else
    TexturedSphere *ts = new TexturedSphere("./Textures/full_map_surface.bmp");
#endif
	ts->size(100.0f);
	ts->SetResolution(5);

	AddObjectToScene(ts);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
