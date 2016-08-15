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
#include "FiniteStateManager.h"


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
	
	enum LEVEL
	{
		LEVEL1,
		LEVEL2,
		END,
	};

	LEVEL currLevel;

	bool goToNextLevel = false;
	bool goToRestart = false;

	//private functions
	void ReadLevel();
	void LoadLevel();
	void ClearLevel();
	
	void Restart();

	GameObject* FetchGO(vector<GameObject*>&list);
	

	//collision
	bool CheckCollision(Avatar* Hero, GameObject*Other);
	void CollisionResponse(Avatar* Hero, GameObject*other);
	//check wif enemy
	void CheckStrategy(Avatar* hero,Avatar* enemy );

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

	//The maps
	TileMap tilemap, rearmap;

	//All Objects
	vector<Avatar*> m_avatarList;
	vector<GameObject*> m_goList;
	vector<GameObject*> m_rearList;
	
};

#endif