#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Easing.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"

#include "Defs.h"
#include "Log.h"

Scene::Scene() : Module()
{
	name.Create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	//Blue rectangle initialization. you can change this values as you wish

	rect.x = 75;
	rect.y = 130;
	rect.w = 300;
	rect.h = 200;

	

	img = app->tex->Load("Assets/Textures/MARIO.png");
	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{


	if(app->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		app->render->camera.y -= 1;

	if(app->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		app->render->camera.y += 1;

	if(app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		app->render->camera.x -= 1;

	if(app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		app->render->camera.x += 1;

	if (app->input->GetKey(SDL_SCANCODE_U) == KEY_DOWN) UI = !UI;

	if (app->input->GetKey(SDL_SCANCODE_B) == KEY_DOWN) back = !back;

	//TODO 5 having implemented the previous code, you can allready call the splines to do what you want. YOu can move for example the camera or the 
	// rectangle created at the start to make your own tests with position and speed.

	if (back == true)
	{
		app->render->DrawTextureS(img, 0, 0);

	}

	if (UI == true)
	{
		app->render->DrawRectangleS(rect, 25, 222, 238);
	}

	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
