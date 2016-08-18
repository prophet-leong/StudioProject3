#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using std::string;
using std::vector;


enum scene{

	NUM_SCENE
};


enum PAGEMODE{
	MENU,
	GAMES,
	CONTROL,
	HIGHSCORES,
	GAMEOVER,

	NUM_PAGES
};

enum DOOR
{
	NONE,
	CENTER,
	UP,
	DOWN, 
	LEFT,
	RIGHT,

	NUM_DOORS,
};

class SharedData{

public:

	static SharedData* GetInstance()
	{
		static SharedData data;
		return &data;
	}

	bool SD_ChangeScene;
	bool SD_QuitGame;

	DOOR SD_CurrDoor;

	unsigned SD_health;

};


#endif