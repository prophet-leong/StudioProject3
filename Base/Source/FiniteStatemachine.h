#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

#include <iostream>
using std::cout;
using std::endl;


class state
{
private:
	int currentstate;
public:
	state();
	state(int newstate);
	~state(){};
	virtual state * change_state(int choice) = 0;
};

//main state
class state_main_menu : public state
{
public:
	state_main_menu();
	~state_main_menu(){};
	state * change_state(int choice);
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

class state_exit : public state
{
public:
	state_exit();
	~state_exit(){};
	state * change_state(int choice);
};

class the_state_machine
{
private:
	state *thecurrentstate;
public:
	the_state_machine();
	~the_state_machine(){};
	void nextstate(int choice);
};

#endif