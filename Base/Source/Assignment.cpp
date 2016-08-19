#include "Assignment.h"
#include "GL\glew.h"

#include "shader.hpp"
#include "MeshBuilder.h"
#include "Application.h"
#include "Utility.h"
#include "LoadTGA.h"
#include <sstream>
#include "Strategy_Kill.h"
#include "Strategy_Escape.h"

Assignment::Assignment()
	: goToNextLevel(false)
{

}

Assignment::~Assignment()
{

}

void Assignment::Init()
{
	//Blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	//Enable depth test
	//glEnable(GL_DEPTH_TEST);
	//Accept fragment if it closer to the camera than the former one
	//glDepthFunc(GL_LESS); 
	
	glEnable(GL_CULL_FACE);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	m_programID = LoadShaders( "Shader//Texture.vertexshader", "Shader//Text.fragmentshader" );
	
	// Get a handle for our uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");
	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");
	// Get a handle for our "colorTexture" uniform
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");
	// Get a handle for our "textColor" uniform
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");
	
	// Use our shader
	glUseProgram(m_programID);

	lights[0].type = Light::LIGHT_DIRECTIONAL;
	lights[0].position.Set(0, 20, 0);
	lights[0].color.Set(1, 1, 1);
	lights[0].power = 1;
	lights[0].kC = 1.f;
	lights[0].kL = 0.01f;
	lights[0].kQ = 0.001f;
	lights[0].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[0].cosInner = cos(Math::DegreeToRadian(30));
	lights[0].exponent = 3.f;
	lights[0].spotDirection.Set(0.f, 1.f, 0.f);

	lights[1].type = Light::LIGHT_DIRECTIONAL;
	lights[1].position.Set(1, 1, 0);
	lights[1].color.Set(1, 1, 0.5f);
	lights[1].power = 0.4f;
	
	glUniform1i(m_parameters[U_NUMLIGHTS], 1);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);

	glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &lights[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], lights[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], lights[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], lights[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], lights[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], lights[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], lights[0].exponent);
	
	glUniform1i(m_parameters[U_LIGHT1_TYPE], lights[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &lights[1].color.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], lights[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], lights[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], lights[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], lights[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], lights[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT1_COSINNER], lights[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], lights[1].exponent);

	camera.Init(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));

	// Initialise the hero's position
	GEOMETRY_TYPE heroTexture[] = { GEO_TILEHERO_FRAME0, GEO_TILEHERO_FRAME1, GEO_TILEHERO_FRAME2, GEO_TILEHERO_FRAME3 };
	currHero = new Hero(512, 400, "HERO", heroTexture , 4);
	currHero->health = 3;
	m_avatarList.push_back(currHero);

	SharedData::GetInstance()->SD_CurrDoor = CENTER;

	MapRandomizer = new Generator();
	MapRandomizer->GenerateStructure(); 
	MapRandomizer->ConnectRooms();

	//gates
	for (int i = 0; i < 4; ++i)
	{
		Gate * newGate = new Gate(0, 0, "GEO_GATE", GEO_NORMAL_DOOR, MapRandomizer);
		Gates.push_back(newGate);
	}

	ReadLevel();

	for(int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference");
	meshList[GEO_CROSSHAIR] = MeshBuilder::GenerateCrossHair("crosshair");
	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("quad", Color(1, 1, 1), 1.f);
	meshList[GEO_QUAD]->textureID = LoadTGA("Image//Consolas.tga");
	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//Consolas.tga");
	meshList[GEO_TEXT]->material.kAmbient.Set(1, 0, 0);
	meshList[GEO_RING] = MeshBuilder::GenerateRing("ring", Color(1, 0, 1), 36, 1, 0.5f);
	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1, 0, 0), 18, 36, 1.f);
	meshList[GEO_SPHERE] = MeshBuilder::GenerateSphere("sphere", Color(1, 0, 0), 18, 36, 10.f);
	meshList[GEO_CONE] = MeshBuilder::GenerateCone("cone", Color(0.5f, 1, 0.3f), 36, 10.f, 10.f);
	meshList[GEO_CONE]->material.kDiffuse.Set(0.99f, 0.99f, 0.99f);
	meshList[GEO_CONE]->material.kSpecular.Set(0.f, 0.f, 0.f);

	// Load the ground mesh and texture
	meshList[GEO_BACKGROUND] = MeshBuilder::Generate2DMesh("GEO_BACKGROUND", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetMapWidth(), tilemap.GetMapHeight());
	meshList[GEO_BACKGROUND] ->textureID = LoadTGA("Image//mariobackground.tga");
	
	//in Game BackGround
	meshList[GEO_INGAME_BACKGROUND] = MeshBuilder::Generate2DMesh("GEO_INGAME_BACKGROUND", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, 1,1);
	meshList[GEO_INGAME_BACKGROUND]->textureID = LoadTGA("Image//Backgrounds//Background_1.tga");

	//black Background
	meshList[GEO_BLACK_BACKGROUND] = MeshBuilder::Generate2DMesh("GEO_BLACK_BACKGROUND", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, 1,1);
	meshList[GEO_BLACK_BACKGROUND]->textureID = LoadTGA("Image//Backgrounds//Black_background.tga");

	//Doors
	meshList[GEO_NORMAL_DOOR] = MeshBuilder::Generate2DMesh("GEO_NORMAL_DOOR", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_NORMAL_DOOR]->textureID = LoadTGA("Image//normal_door.tga");

	meshList[GEO_MARIO] = MeshBuilder::Generate2DMesh("Hero_Pic", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_MARIO]->textureID = LoadTGA("Image//tile2_hero_frame_0.tga");

	meshList[GEO_COIN] = MeshBuilder::Generate2DMesh("coin", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_COIN]->textureID = LoadTGA("Image//coin.tga");

	meshList[GEO_TILEGROUND] = MeshBuilder::Generate2DMesh("GEO_TILEGROUND", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_TILEGROUND]->textureID = LoadTGA("Image//mariotile.tga");

	meshList[GEO_TILETREE] = MeshBuilder::Generate2DMesh("GEO_TILETREE", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_TILETREE]->textureID = LoadTGA("Image//tree.tga");

	meshList[GEO_TILESTRUCTURE] = MeshBuilder::Generate2DMesh("GEO_TILESTRUCTURE", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_TILESTRUCTURE]->textureID = LoadTGA("Image//step4b.tga");

	meshList[GEO_TILEHERO_FRAME0] = MeshBuilder::Generate2DMesh("GEO_TILEHERO_FRAME0", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_TILEHERO_FRAME0]->textureID = LoadTGA("Image//tile2_hero_frame_0.tga"); 

	meshList[GEO_TILEHERO_FRAME1] = MeshBuilder::Generate2DMesh("GEO_TILEHERO_FRAME1", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_TILEHERO_FRAME1]->textureID = LoadTGA("Image//tile2_hero_frame_1.tga");

	meshList[GEO_TILEHERO_FRAME2] = MeshBuilder::Generate2DMesh("GEO_TILEHERO_FRAME2", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_TILEHERO_FRAME2]->textureID = LoadTGA("Image//tile2_hero_frame_2.tga");

	meshList[GEO_TILEHERO_FRAME3] = MeshBuilder::Generate2DMesh("GEO_TILEHERO_FRAME3", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_TILEHERO_FRAME3]->textureID = LoadTGA("Image//tile2_hero_frame_3.tga");

	meshList[GEO_PLACEHOLDER] = MeshBuilder::GenerateQuad("Placeholder", Color(1.f, 1.f, 1.f), 10.f);
	meshList[GEO_PLACEHOLDER]->textureID = LoadTGA("Image//Placeholder//placeholder.tga");

	meshList[GEO_SPIKE_TRAP] = MeshBuilder::Generate2DMesh("GEO_SPIKED_TRAP", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_SPIKE_TRAP]->textureID = LoadTGA("Image//Traps//Spike_Trap.tga");

	meshList[GEO_POISONED_BLOCK] = MeshBuilder::Generate2DMesh("spiked block", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_POISONED_BLOCK]->textureID = LoadTGA("Image//Traps//Spike_Block.tga");

	meshList[GEO_SALT] = MeshBuilder::Generate2DMesh("treeSalt", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_SALT]->textureID = LoadTGA("Image//tree.tga");

	meshList[GEO_FIRE] = MeshBuilder::Generate2DMesh("treeSalt", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_FIRE]->textureID = LoadTGA("Image//Fire.tga");

	meshList[GEO_FIRESALT] = MeshBuilder::Generate2DMesh("coinsalt", Color(1.f, 1.f, 1.f), 0.0f, 0.0f, tilemap.GetTileSize(), tilemap.GetTileSize());
	meshList[GEO_FIRESALT]->textureID = LoadTGA("Image//coin.tga");
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 1000 units
	//perspective.SetToOrtho(-80, 80, -60, 60, -1000, 1000);

	Mtx44 perspective;
	perspective.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
	projectionStack.LoadMatrix(perspective);

	bLightEnabled = true;
	state_enter_seed_screen::seedentered(false);
	ssss.str("");
}

void Assignment::ReadLevel()
{
	MapRandomizer->Read(&tilemap);

	if (goToNextLevel)
	{
		currHero->Reset(&tilemap);
	}
	// Actual Map
	for (int i = 0; i < tilemap.GetNumRows(); i++)
	{
		for (int k = 0; k < tilemap.GetNumColumns(); k++)
		{
			switch (tilemap.map[i][k])
			{
			case 1:
			{
				Tile *newTile = new Tile(k*tilemap.GetTileSize(), i*tilemap.GetTileSize(), "GEO_TILEGROUND", GEO_TILEGROUND);
				m_goList.push_back(newTile); 
				break;

			} 
			//Up door
			case 3:
			case 4:
			case 5:
			case 6:
			{
				//if there is a room next door, create door
				if (MapRandomizer->GetCurrentRoom()->up != nullptr &&  tilemap.map[i][k] == 3)
				{
					if (SharedData::GetInstance()->SD_CurrDoor == DOWN)
					{
						currHero->SetPos(k*tilemap.GetTileSize(), i*tilemap.GetTileSize() - tilemap.GetTileSize());
						SharedData::GetInstance()->SD_CurrDoor = NONE;
					}
					Gates[tilemap.map[i][k] - 3]->SetLocation(Vector2(0, 1));
					Gates[tilemap.map[i][k] - 3]->SetPos(k*tilemap.GetTileSize(), i*tilemap.GetTileSize());
					Gates[tilemap.map[i][k] - 3]->active = true;
				}
				else if (MapRandomizer->GetCurrentRoom()->right != nullptr &&  tilemap.map[i][k] == 4)
				{
					if (SharedData::GetInstance()->SD_CurrDoor == LEFT)
					{
						currHero->SetPos(k*tilemap.GetTileSize() - tilemap.GetTileSize(), i*tilemap.GetTileSize());
						SharedData::GetInstance()->SD_CurrDoor = NONE;
					}
					Gates[tilemap.map[i][k] - 3]->SetLocation(Vector2(1, 0));
					Gates[tilemap.map[i][k] - 3]->SetPos(k*tilemap.GetTileSize(), i*tilemap.GetTileSize());
					Gates[tilemap.map[i][k] - 3]->active = true;
				}
				else if (MapRandomizer->GetCurrentRoom()->down != nullptr &&  tilemap.map[i][k] == 5)
				{
					if (SharedData::GetInstance()->SD_CurrDoor == UP)
					{
						currHero->SetPos(k*tilemap.GetTileSize(), i*tilemap.GetTileSize() + tilemap.GetTileSize());
						SharedData::GetInstance()->SD_CurrDoor = NONE;
					}
					Gates[tilemap.map[i][k] - 3]->SetLocation(Vector2(0, -1));
					Gates[tilemap.map[i][k] - 3]->SetPos(k*tilemap.GetTileSize(), i*tilemap.GetTileSize());
					Gates[tilemap.map[i][k] - 3]->active = true;
				}
				else if (MapRandomizer->GetCurrentRoom()->left != nullptr &&  tilemap.map[i][k] == 6)
				{
					if (SharedData::GetInstance()->SD_CurrDoor == RIGHT)
					{
						currHero->SetPos(k*tilemap.GetTileSize() + tilemap.GetTileSize(), i*tilemap.GetTileSize());
						SharedData::GetInstance()->SD_CurrDoor = NONE;
					}
					Gates[tilemap.map[i][k] - 3]->SetLocation(Vector2(-1, 0));
					Gates[tilemap.map[i][k] - 3]->SetPos(k*tilemap.GetTileSize(), i*tilemap.GetTileSize());
					Gates[tilemap.map[i][k] - 3]->active = true;
				}
				else
				{
					Tile *newTile = new Tile(k*tilemap.GetTileSize(), i*tilemap.GetTileSize(), "GEO_TILEGROUND", GEO_TILEGROUND);
					m_goList.push_back(newTile);
				}

				break;
			} 

			case 15: 
			{
				C_SpikeTrap *newTrap = new C_SpikeTrap(k*tilemap.GetTileSize(), i*tilemap.GetTileSize(), "GEO_SPIKED_TRAP", GEO_SPIKE_TRAP,1);
				m_gotrapslist.push_back(newTrap); 
				break;
			}

			//dumb enemy
			case 10:
			{
				GEOMETRY_TYPE heroTexture[] = { GEO_TILEHERO_FRAME0, GEO_TILEHERO_FRAME1, GEO_TILEHERO_FRAME2, GEO_TILEHERO_FRAME3 };
				EnemyAI* newEnemy = new EnemyAI(k*tilemap.GetTileSize(), i*tilemap.GetTileSize(), "GEO_ENEMY",heroTexture, 4);
				newEnemy->health = 10;
				m_avatarList.push_back(newEnemy); 
				break;
			}

			}
		}
	}
}

void Assignment::Restart()
{
	currHero->health -= 1;
	if (currHero->health <= 0)
	{ 
		ClearLevel();
		ReadLevel(); 
		currHero->Restart();
	}
	currHero->Reset(&tilemap);
}

void Assignment::Update(double dt)
{
	statemachine.FMSupdate();

	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 10)
	{
	}
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 2)
	{
		// Update the hero
		if (dt > 1.0 / 30.0)
			return;

		//status:done
		if (Application::IsKeyPressed('W'))
			currHero->MoveUpDown(true, 1.0f, &tilemap);
		if (Application::IsKeyPressed('S'))
			currHero->MoveUpDown(false, 1.0f, &tilemap);
		if (Application::IsKeyPressed('A'))
			currHero->MoveLeftRight(true, 1.0f, &tilemap);
		if (Application::IsKeyPressed('D'))
			currHero->MoveLeftRight(false, 1.0f, &tilemap);
		//attacks
		if (Application::IsKeyPressed('E'))
			currHero->NextPowerUp();
		if (Application::IsKeyPressed(' '))
			currHero->NormalAttack();
		if (Application::IsKeyPressed('F'))
			currHero->SkillAttack();

		for (int i = 0; i < m_avatarList.size(); ++i)
		{
			m_avatarList[i]->Update(&tilemap, dt);
		}

		tilemap.Update();
	
		UpdateAllObjects();

		if (goToRestart)
		{
			Restart();
			goToRestart = false;
		}
		if (goToNextLevel)
		{
			ClearLevel();
			ReadLevel();
			goToNextLevel = false;
		}

		fps = (float)(1.f / dt);
	}
}

void Assignment::UpdateAllObjects()
{
	//hero enemy enemy
	for (vector<Avatar*>::iterator iter = m_avatarList.begin(); iter != m_avatarList.end(); iter++)
	{
		Avatar *go = (Avatar*)*iter;
		if (!go->active)
			continue;

		for (vector<Gate*>::iterator iter4 = Gates.begin(); iter4 != Gates.end(); iter4++)
		{
			Gate *other = (Gate *)*iter4;
			if (!other->active)
				continue;
			if (other->CheckCollision(go, &tilemap))
			{
				other->CollisionResponse(go, &tilemap);
				goToNextLevel = true;
			}
		}

		for (vector<GameObject*>::iterator iter2 = m_goList.begin(); iter2 != m_goList.end(); iter2++)
		{
			GameObject *other = (GameObject *)*iter2;
			if (!other->active)
				continue;
			if (go->CheckCollision(other, &tilemap))
				go->CollisionResponse(other, &tilemap);	
		}
		for (vector<C_Traps*>::iterator iter2 = m_gotrapslist.begin(); iter2 != m_gotrapslist.end(); iter2++)
		{
			C_SpikeTrap *other = (C_SpikeTrap *)*iter2;
			if (!other->active)
				continue;
			if (other->CheckCollision(go, &tilemap))
			{
				other->CollisionResponse(go, &tilemap);
			}
		}
		for (vector<Avatar*>::iterator iter3 = iter + 1; iter3 != m_avatarList.end(); iter3++)
		{
			Avatar *other = (Avatar *)*iter3;
			if (!other->active)
				continue;
			if (go->CheckCollision(other, &tilemap))
			{
				go->CollisionResponse(other, &tilemap);
			}
		}
	}
}

void Assignment::RenderText(Mesh* mesh, std::string text, Color color)
{
	if(!mesh || mesh->textureID <= 0)
		return;
	
//	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	
		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
//	glEnable(GL_DEPTH_TEST);
}

void Assignment::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0)
		return;
	
//	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 800, 0, 600, -10, 10);
	projectionStack.PushMatrix();
		projectionStack.LoadMatrix(ortho);
		viewStack.PushMatrix();
			viewStack.LoadIdentity();
			modelStack.PushMatrix();
				modelStack.LoadIdentity();
				modelStack.Translate(x, y, 0);
				modelStack.Scale(size, size, size);
				glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
				glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
				glUniform1i(m_parameters[U_LIGHTENABLED], 0);
				glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, mesh->textureID);
				glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
				for(unsigned i = 0; i < text.length(); ++i)
				{
					Mtx44 characterSpacing;
					characterSpacing.SetToTranslation(i + 0.5f, 0.3f, 0); //1.0f is the spacing of each character, you may change this value
					Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
					glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	
					mesh->Render((unsigned)text[i] * 6, 6);
				}
				glBindTexture(GL_TEXTURE_2D, 0);
				glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
			modelStack.PopMatrix();
		viewStack.PopMatrix();
	projectionStack.PopMatrix();
//	glEnable(GL_DEPTH_TEST);
}

void Assignment::RenderMeshIn2D(Mesh *mesh, const bool enableLight, const float size, const float x, const float y, const bool rotate)
{
	Mtx44 ortho;
	ortho.SetToOrtho(-80, 80, -60, 60, -10, 10);
	projectionStack.PushMatrix();
		projectionStack.LoadMatrix(ortho);
		viewStack.PushMatrix();
			viewStack.LoadIdentity();
			modelStack.PushMatrix();
				modelStack.LoadIdentity();
				modelStack.Translate(x, y, 0);
				modelStack.Scale(size, size, size);
       
				Mtx44 MVP, modelView, modelView_inverse_transpose;
	
				MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
				glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
				if(mesh->textureID > 0)
				{
					glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, mesh->textureID);
					glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
				}
				else
				{
					glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
				}
				mesh->Render();
				if(mesh->textureID > 0)
				{
					glBindTexture(GL_TEXTURE_2D, 0);
				}
       
			modelStack.PopMatrix();
		viewStack.PopMatrix();
	projectionStack.PopMatrix();

}

void Assignment::Render2DMesh(Mesh *mesh, bool enableLight, float sizeX, float sizeY , float x, float y,float rotation, bool rotate, bool invert)
{
	Mtx44 ortho;
	ortho.SetToOrtho(0, 1024, 0, 800, -10, 10);
	projectionStack.PushMatrix();
		projectionStack.LoadMatrix(ortho);
		viewStack.PushMatrix();
			viewStack.LoadIdentity();
			modelStack.PushMatrix();
				modelStack.LoadIdentity();

				if (rotation == 0.0f)
				{
					modelStack.Translate(x, y, 0);
					modelStack.Scale(sizeX, sizeY, 1);
				}
				else if (rotation == 90.0f)
				{
					modelStack.Translate(x + tilemap.GetTileSize(), y, 0);
					modelStack.Rotate(rotation, 0, 0, 1);
					modelStack.Scale(sizeX, sizeY, 1);
				}
				else if (rotation == 180.0f)
				{
					modelStack.Translate(x + tilemap.GetTileSize(), y + tilemap.GetTileSize(), 0);
					modelStack.Rotate(rotation, 0, 0, 1);
					modelStack.Scale(sizeX, sizeY, 1);
				}
				else if (rotation == -90)
				{
					modelStack.Translate(x, y + tilemap.GetTileSize(), 0);
					modelStack.Rotate(rotation, 0, 0, 1);
					modelStack.Scale(sizeX, sizeY, 1);
				}


				Mtx44 MVP, modelView, modelView_inverse_transpose;
	
				MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
				glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
				if(mesh->textureID > 0)
				{
					glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, mesh->textureID);
					glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
				}
				else
				{
					glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
				}
				mesh->Render();

				if(mesh->textureID > 0)
				{
					glBindTexture(GL_TEXTURE_2D, 0);
				}
       
			modelStack.PopMatrix();
		viewStack.PopMatrix();
	projectionStack.PopMatrix();
}

void Assignment::RenderMesh(Mesh *mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;
	
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	if(enableLight && bLightEnabled)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView = viewStack.Top() * modelStack.Top();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView.a[0]);
		
		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{	
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}
	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	mesh->Render();
	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void Assignment::RenderBackground()
{
	Render2DMesh(meshList[GEO_BLACK_BACKGROUND], false, tilemap.GetMapWidth(), tilemap.GetMapHeight(), 0 - tilemap.offSet_x, 0 - tilemap.offSet_y);
		// Render the crosshair							 
	Render2DMesh(meshList[GEO_INGAME_BACKGROUND], false, tilemap.GetMapWidth(), tilemap.GetMapHeight(), 0 - tilemap.offSet_x, 0 - tilemap.offSet_y);
}

void Assignment::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Mtx44 perspective;
	perspective.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
	//perspective.SetToOrtho(-80, 80, -60, 60, -1000, 1000);
	projectionStack.LoadMatrix(perspective);
	
	// Camera matrix
	viewStack.LoadIdentity();
	viewStack.LookAt(
						camera.position.x, camera.position.y, camera.position.z,
						camera.target.x, camera.target.y, camera.target.z,
						camera.up.x, camera.up.y, camera.up.z
					);
	// Model matrix : an identity matrix (model will be at the origin)
	modelStack.LoadIdentity();

	// Render the background image
	RenderBackground();

	//loading/rendering of level
	LoadLevel();

	//On screen text UI
	render_main_menu();
	render_achievement_screen();
	render_options_screen();
	render_pause_menu();
	render_in_game_option_screen();
	render_enter_seed_screen();
	
	std::ostringstream sss;
	sss.precision(5);
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 2)
	{
		sss.str("");
		Render2DMesh(meshList[GEO_MARIO], false);
		sss.str("");
		sss << " X" << currHero->health;
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 0, 0), 30, 0, 0);
	}
}

void Assignment::Exit()
{
	// Cleanup VBO
	for(int i = 0; i < NUM_GEOMETRY; ++i)
	{
		if(meshList[i])
			delete meshList[i];
	}
	glDeleteProgram(m_programID);
	glDeleteVertexArrays(1, &m_vertexArrayID);
}

/********************************************************************************
 Render the maps. This is a private function for use in this class only
 ********************************************************************************/
void Assignment::LoadLevel()
{
	//render bullets
	for (int i = 0; i < currHero->Projectile.size(); ++i)
	{
		if (currHero->Projectile[i]->active)
		{
			Render2DMesh(meshList[currHero->Projectile[i]->type], false, 1, 1,
				currHero->Projectile[i]->GetPosition().x - tilemap.offSet_x,
				currHero->Projectile[i]->GetPosition().y - tilemap.offSet_y);
		}
	}

	//load actual
	for (vector<GameObject*>::iterator iter = m_goList.begin(); iter != m_goList.end(); iter++)
	{
		GameObject *go = (GameObject *)*iter;
		if (!go->active)
			continue;
		Render2DMesh(meshList[go->type], false, go->scale.x, go->scale.y, go->GetPosition().x - tilemap.offSet_x, go->GetPosition().y - tilemap.offSet_y);
	}
	
	//renderGate
	for (vector<Gate*>::iterator iter = Gates.begin(); iter != Gates.end(); iter++)
	{
		Gate*go = (Gate*)*iter;
		if (!go->active)
			continue;

		Render2DMesh(meshList[go->type], false, go->scale.x, go->scale.y, go->GetPosition().x - tilemap.offSet_x, go->GetPosition().y - tilemap.offSet_y);
	}
	
	//render Traps
	for (vector<C_Traps*>::iterator iter = m_gotrapslist.begin(); iter != m_gotrapslist.end(); iter++)
	{
		C_Traps* go = (C_Traps*)*iter;
		if (!go->active)
		{
			continue;
		}
		Render2DMesh(meshList[go->type], false, go->scale.x, go->scale.y, go->GetPosition().x - tilemap.offSet_x, go->GetPosition().y - tilemap.offSet_y);
	}

	//render bullets
	for (int i = 0; i < currHero->Projectile.size(); ++i)
	{
		if (currHero->Projectile[i]->active)
		{
			Render2DMesh(meshList[currHero->Projectile[i]->type], false, 1, 1,
				currHero->Projectile[i]->GetPosition().x - tilemap.offSet_x,
				currHero->Projectile[i]->GetPosition().y - tilemap.offSet_y);
		}
	}
	//render Skill effect
	if (currHero->activeSkillEffect)
	{
		Render2DMesh(meshList[currHero->skillEffect], false, 1, 1,
			currHero->GetPosition().x - tilemap.offSet_x,
			currHero->GetPosition().y - tilemap.offSet_y);
	}
	//render avatars
	for (vector<Avatar*>::iterator iter = m_avatarList.begin(); iter != m_avatarList.end(); iter++)
	{
		Avatar*go = (Avatar*)*iter;
		if (!go->active)
			continue;

		float rotation = Math::RadianToDegree(atan2(go->direction.y, go->direction.x));
		Render2DMesh(meshList[go->type], false, go->scale.x, go->scale.y, go->GetPosition().x - tilemap.offSet_x, go->GetPosition().y - tilemap.offSet_y, rotation,false, currHero->GetAnimationInvert());
		if(go->GetElement() == FIRE)
			Render2DMesh(meshList[GEO_FIRE], false, go->scale.x, go->scale.y, go->GetPosition().x - tilemap.offSet_x, go->GetPosition().y - tilemap.offSet_y, rotation, false, currHero->GetAnimationInvert());
	}

	
	 
}

void Assignment::ClearLevel()
{
	while (m_goList.size() > 0)
	{
		GameObject *go = m_goList.back();
		delete go;
		m_goList.pop_back();
	}
	while (m_avatarList.size() > 1)
	{
		GameObject *go = m_avatarList.back();
		delete go;
		m_avatarList.pop_back();
	}
	while (m_gotrapslist.size() > 0)
	{
		GameObject *go = m_gotrapslist.back(); 
		delete go;
		m_gotrapslist.pop_back();
	}
	for (int i = 0; i < currHero->Projectile.size(); ++i)
	{
		if (currHero->Projectile[i]->active)
			currHero->Projectile[i]->active = false;
	}
	for (vector<Gate*>::iterator iter = Gates.begin(); iter != Gates.end(); iter++)
	{
		Gate *go = (Gate *)*iter;
		go->active = false;
		go->up = false;
		go->down = false;
		go->left = false;
		go->right = false; 
	}
}

/*Individual functions to render what when the state happens*/
void Assignment::render_main_menu()
{
	stringstream sss;
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 1)
	{
		modelStack.PushMatrix();
		modelStack.Translate(0, 0.f, -2);
		modelStack.Scale(1.5f, 1.f, 1.f);
		RenderMesh(meshList[GEO_PLACEHOLDER], false);
		modelStack.PopMatrix();
		sss.str("");
		sss << "Main Menu Screen LOL";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 20.f, 200.f);
		sss.str("");
		sss << "Press Enter to start da level";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 20.f, 180);
		sss.str("");
		sss << "Press 1 to go to achievements";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 20.f, 160);
		sss.str("");
		sss << "Press 2 to go to options";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 20.f, 140);
	}
}
void Assignment::render_achievement_screen()
{
	stringstream sss;
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 4) //Achievenemts
	{
		modelStack.PushMatrix();
		modelStack.Translate(20.f, 20.f, -2);
		modelStack.Scale(1.5f, 1.f, 1.f);
		RenderMesh(meshList[GEO_PLACEHOLDER], false);
		modelStack.PopMatrix();
		sss.str("");
		sss << "Temp Achievement Screen LOL";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 200.f);
		sss.str("");
		sss << "Press Backspace to main menu";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 180);

	}

}
void Assignment::render_options_screen()
{
	stringstream sss;
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 5)
	{
		modelStack.PushMatrix();
		modelStack.Translate(20.f, 20.f, -2);
		modelStack.Scale(1.5f, 1.f, 1.f);
		RenderMesh(meshList[GEO_PLACEHOLDER], false);
		modelStack.PopMatrix();
		sss.str("");
		sss << "Temp Options Screen LOL";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 200.f);
		sss.str("");
		sss << "Press Backspace to main menu";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 180);

	}
}
void Assignment::render_pause_menu()
{
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 6) //pause menu
	{
		stringstream sss;
		modelStack.PushMatrix();
		modelStack.Translate(20.f, 20.f, -2);
		modelStack.Scale(1.5f, 1.f, 1.f);
		RenderMesh(meshList[GEO_PLACEHOLDER], false);
		modelStack.PopMatrix();
		sss.str("");
		sss << "Temp Pause Screen LOL";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 200.f);
		sss.str("");
		sss << "Press Enter to resume da level";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 180);

	}
}
void Assignment::render_in_game_option_screen()
{
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 7) //pause menu
	{
		stringstream sss;
		modelStack.PushMatrix();
		modelStack.Translate(20.f, 20.f, -2);
		modelStack.Scale(1.5f, 1.f, 1.f);
		RenderMesh(meshList[GEO_PLACEHOLDER], false);
		modelStack.PopMatrix();

		sss.str("");
		sss << "Temp in-game Options Screen LOL";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 200.f);
		sss.str("");
		sss << "Press Backspace to return";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 180);
	}
}
void Assignment::render_enter_seed_screen()
{
	if (statemachine.the_current_state_of_state_machine->getcurrent_state() == 10)
	{
		stringstream sss;
		modelStack.PushMatrix();
		modelStack.Translate(0, 0, -2);
		modelStack.Scale(1.5f, 1.f, 1.f);
		RenderMesh(meshList[GEO_PLACEHOLDER], false);
		modelStack.PopMatrix();

		sss.str("");
		sss << "Temp seed Screen LOL";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 200.f);
		sss.str("");
		sss << "Press Enter to play";
		RenderTextOnScreen(meshList[GEO_TEXT], sss.str(), Color(0, 1, 0), 30, 180, 180);

		RenderTextOnScreen(meshList[GEO_TEXT], ssss.str(), Color(0, 1, 0), 30, 20.f, 260);

	}
	
}
