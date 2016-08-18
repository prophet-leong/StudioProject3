#ifndef SCENE_ASSIGNMENT_H
#define SCENE_ASSIGNMENT_H

#include "Scene.h"
#include "Mtx44.h"
#include "Camera3.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"
#include "Vector2.h"
#include "TileMap.h"
#include "Hero.h"
#include "Enemy.h"
#include "Tile.h"
#include "GeometryType.h"
#include "MapGenerator.h"
#include "FiniteStatemachine.h"
#include "Gate.h"
#include "Traps.h"


class Assignment : public Scene
{
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHTENABLED,
		U_NUMLIGHTS,
		U_LIGHT0_TYPE,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,
		U_LIGHT1_TYPE,
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,
	};

public:
	Assignment();
	~Assignment();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderTextOnScreen2(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderMeshIn2D(Mesh *mesh, bool enableLight, const float size = 1.f, float x = 0.0f, float y = 0.0f, bool rotate = false);
	void RenderMesh(Mesh *mesh, bool enableLight);
	void RenderBackground();
	void Render2DMesh(Mesh *mesh, const bool enableLight, const float sizeX = 1.0f, const float sizeY = 1.0f, const float x = 0.0f, const float y = 0.0f, const bool rotate = false, bool invert = false);

private:
	

	bool goToNextLevel = false;
	bool goToRestart = false;


	// Main Update Loop
	void UpdateAllObjects();
	//private functions
	void ReadLevel();
	void LoadLevel();
	void ClearLevel();
	
	void Restart();

	template<class Type>
	Type* FetchGO(vector<Type*>&list)
	{
		for (std::vector<Type*>::iterator iter = list.begin(); iter != list.end(); ++iter)
		{
			Type *go = *iter;
			if (!go->active)
			{
				go->active = true;
				return go;
			}
		}
		//Exercise 2b: increase object count every time an object is set to active

		list.push_back(new Type());

		Type *go = *(list.end() - 1);
		go->active = true;
		return go;
	};

	//private variabless
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	Camera3 camera;

	MS modelStack;
	MS viewStack;
	MS projectionStack;

	Light lights[2];

	bool bLightEnabled;

	float fps;

	// Hero's information
	Hero* currHero;

	//Gates

	//The maps
	TileMap tilemap;

	//All Objects

	vector<Gate*>Gates;
	vector<Avatar*> m_avatarList;
	vector<GameObject*> m_goList;
	vector<C_Traps*>m_gotrapslist;

	//Map RNG
	Generator* MapRandomizer;

	//the state machine
	the_state_machine statemachine;

	//individual render functions
	void render_main_menu();
	void render_achievement_screen();
	void render_options_screen();
	void render_pause_menu();
	void render_in_game_option_screen();
	void render_enter_seed_screen();
	
};

#endif