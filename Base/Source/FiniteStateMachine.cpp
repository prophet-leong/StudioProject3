#include "FiniteStatemachine.h"

//constructors
state::state() : current_state(0)
{

}
state::state(int newstate) : current_state(newstate)
{

}

state_main_menu::state_main_menu() : state(1)
{

}

state_play::state_play() : state(2)
{

}

state_continue::state_continue() : state(3)
{

}

state_Achievements::state_Achievements() : state(4)
{

}

state_Options::state_Options() : state(5)
{

}
//Options within game
state_pause_menu::state_pause_menu() : state(6)
{

}

state_in_game_options::state_in_game_options() : state(7)
{

}

state_back_to_main_menu::state_back_to_main_menu() : state(8)
{

}


//Exits Game
state_died::state_died() : state(9)
{

}

//These Functions will handle the changing of states
state * state_main_menu::change_state(int choice)
{
	cout << "Main menu state" << endl;
	if (choice == 2) // to play
	{
		reinterpret_cast<state_play *>(this)->state_play::state_play();
	}
	else if (choice == 3) // to continue a saved game
	{
		reinterpret_cast<state_continue *>(this)->state_continue::state_continue();
	}
	else if (choice == 4) //to go to the achievements screen
	{
		reinterpret_cast<state_Achievements *>(this)->state_Achievements::state_Achievements();
	}
	else if (choice == 5) // to change options
	{
		reinterpret_cast<state_Options *>(this)->state_Options::state_Options();
	}
	else if (choice == 9) // to exit game
	{
		reinterpret_cast<state_died *>(this)->state_died::state_died();
	}
	return this;
}
state * state_play::change_state(int choice)
{
	cout << "Play State" << endl;
	if (choice == 6) //to pause game within game
	{
		reinterpret_cast<state_pause_menu *>(this)->state_pause_menu::state_pause_menu();
	}
	if (choice == 1) //If you die, go back to main menu, does not save game since you died
	{
		reinterpret_cast<state_main_menu *>(this)->state_main_menu::state_main_menu();
	}
	return this;
}

state * state_continue::change_state(int choice)
{
	cout << "continue state" << endl;
	if (choice == 2)
	{
		reinterpret_cast<state_play *>(this)->state_play::state_play();
	}
	return this;
}

state * state_Achievements::change_state(int choice)
{
	cout << "Achievement state" << endl;
	if (choice == 1)
	{
		reinterpret_cast<state_main_menu *>(this)->state_main_menu::state_main_menu();
	}
	return this;
}

state * state_Options::change_state(int choice)
{
	cout << "Options state" << endl;
	if (choice == 1)
	{
		reinterpret_cast<state_main_menu *>(this)->state_main_menu::state_main_menu();
	}
	return this;
}

state * state_pause_menu::change_state(int choice)
{
	cout << "Pause menu state state" << endl;
	if (choice == 7)
	{
		reinterpret_cast<state_in_game_options *>(this)->state_in_game_options::state_in_game_options();
	}
	if (choice == 8)
	{
		reinterpret_cast<state_back_to_main_menu *>(this)->state_back_to_main_menu::state_back_to_main_menu();
	}
	if (choice == 2)
	{
		reinterpret_cast<state_play *>(this)->state_play::state_play();
	}
	return this;
}

state * state_in_game_options::change_state(int choice)
{
	cout << "in-game Options state" << endl;
	if (choice == 6)
	{
		reinterpret_cast<state_pause_menu *>(this)->state_pause_menu::state_pause_menu();
	}
	return this;
}

state * state_back_to_main_menu::change_state(int choice)
{
	cout << "Back to main menu state" << endl;
	if (choice == 1)
	{
		reinterpret_cast<state_main_menu *>(this)->state_main_menu::state_main_menu();
	}
	return this;
}

state * state_died::change_state(int choice)
{
	cout << "exiting" << endl;
	return this;
}



// the actual state machine
the_state_machine::the_state_machine() : the_current_state_of_state_machine(new state_main_menu())
{

}

void the_state_machine::nextstate(int choice)
{
	the_current_state_of_state_machine = the_current_state_of_state_machine->change_state(choice);
}