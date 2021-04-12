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

		if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 6000, SplineType::EASE);
		}
		if (app->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 6000, SplineType::CIRC);
		}
		if (app->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 8000, SplineType::BACK);
		}
		if (app->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 8000, SplineType::EXPO);
		}
		if (app->input->GetKey(SDL_SCANCODE_5) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 8000, SplineType::QUAD);
		}
		if (app->input->GetKey(SDL_SCANCODE_6) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 8000, SplineType::CUBIC);
		}
		if (app->input->GetKey(SDL_SCANCODE_7) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 8000, SplineType::QUART);
		}
		if (app->input->GetKey(SDL_SCANCODE_8) == KEY_DOWN) {
			app->easing->CreateSpline(&app->render->camera.x, -app->render->camera.x - 6582, 8000, SplineType::QUINT);
		}
	}

	if (UI == true)
	{
		app->render->DrawRectangleS(rect, 25, 222, 238);

		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 6000, SplineType::EASE);
		}
		if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 6000, SplineType::CIRC);
		}
		if (app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 10000, SplineType::BACK);
		}
		if (app->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 10000, SplineType::EXPO);
		}
		if (app->input->GetKey(SDL_SCANCODE_G) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 10000, SplineType::QUAD);
		}
		if (app->input->GetKey(SDL_SCANCODE_H) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 10000, SplineType::CUBIC);
		}
		if (app->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 10000, SplineType::QUART);
		}
		if (app->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN) {
			app->easing->CreateSpline(&rect.x, -rect.x + 400, 10000, SplineType::QUINT);
		}
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
