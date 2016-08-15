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


class SharedData{

public:

	static SharedData* GetInstance()
	{
		static SharedData data;
		return &data;
	}

	bool SD_ChangeScene;
	bool SD_QuitGame;

	unsigned SD_health;



};


#endif