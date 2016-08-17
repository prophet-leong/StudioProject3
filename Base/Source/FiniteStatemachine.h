#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

#include <iostream>
using std::cout;
using std::endl;

class state
{
private:
	int current_state;
public:
	state();
	state(int newstate);
	~state(){};
	int getcurrent_state()
	{
		return current_state;
	}
	virtual state * change_state(int choice) = 0;
};

//main state
class state_main_menu : public state
{
public:
	state_main_menu();
	~state_main_menu(){};
	state * change_state(int choice);
	//void testing change state
	void changestate();
};

class state_play : public state
{
public:
	state_play();
	~state_play(){};
	state * change_state(int choice);
};

class state_continue : public state
{
public:
	state_continue();
	~state_continue(){};
	state * change_state(int choice);
};

class state_Achievements : public state
{
public:
	state_Achievements();
	~state_Achievements(){};
	state * change_state(int choice);
};

class state_Options : public state
{
public:
	state_Options();
	~state_Options(){};
	state * change_state(int choice);
};

//In-game states
class state_pause_menu : public state
{
public:
	state_pause_menu();
	~state_pause_menu(){};
	state * change_state(int choice);
};

class state_in_game_options : public state
{
public:
	state_in_game_options();
	~state_in_game_options(){};
	state * change_state(int choice);
};

class state_back_to_main_menu : public state
{
public:
	state_back_to_main_menu();
	~state_back_to_main_menu(){};
	state * change_state(int choice);
};

class state_died : public state
{
public:
	state_died();
	~state_died(){};
	state * change_state(int choice);
};

class the_state_machine
{
private:
public:
	state *the_current_state_of_state_machine;
	the_state_machine();
	~the_state_machine(){};
	void nextstate(int choice);
	void FMSupdate();

};

//enum STATE
//{
//	STATE_TYPE = 0,
//	STATE_MAIN_MENU,
//	STATE_PLAY,
//	STATE_CONTINUE,
//	STATE_OPTIONS,
//	STATE_PAUSE,
//	STATE_GAME_OVER,
//	STATE_END,
//};
//
//enum PAUSEMENU
//{
//	PAUSEMENU_START = 0,
//	RESUME,
//	PAUSE_MENU_OPTIONS,
//	BACK_TO_MAIN_MENU,
//	PAUSEMENU_END,
//};

#endif