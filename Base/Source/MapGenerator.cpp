#include "MapGenerator.h"
#include <time.h>
/***********************************************/
/*!
\brief
default constructor
*/
/***********************************************/
Generator::Generator()
	: CurRooms(0)
	, level(LEVEL1)
	, playerRoomPosition(0,0)
	, up(0, 1)
	, down(0, -1)
	, left(-1, 0)
	, right(1, 0)
{
}
/***********************************************/
/*!
\brief
default destructor
*/
/***********************************************/
Generator::~Generator()
{
}
/***********************************************/
/*!
\brief
Generates the Structure of the rooms randomly
\param
seed : the seed used to randomise the level inputed by the player
*/
/***********************************************/
void Generator::GenerateStructure(/*string seed*/)
{
	srand(time(NULL));
	//srand (stoi(seed));
	if (CurRooms == 0)
		GenerateLevel(MaxRooms,Vector2(0,0));

	while (CurRooms < MaxRooms)
	{
		//check room
		Vector2 newRoom = Rooms[CurRooms - 1]->RoomPosition + RandomDirection();

		//check surrounding
		if (!CheckRoom(newRoom))
		{
			if (CurRooms + 1 == MaxRooms)
			{
				Node*endRoom = new Node(CurRooms, newRoom);
				Rooms.push_back(endRoom);
				CurRooms++;
			}
			else
				GenerateLevel(MaxRooms, newRoom);
		}
		
	}
}
/***********************************************/
/*!
\brief
returns a Vector2 random direction
\return
returns a random direction 
*/
/***********************************************/
Vector2 Generator::RandomDirection()
{
	int direction = rand() % 4 + 1;
	switch (direction)
	{
	case 1:
		return up;
	case 2:
		return down;
	case 3:
		return left;
	case 4:
		return right; 
	}
}
/***********************************************/
/*!
\brief
check if the next room is empty or not
\param	newRoom
the coordinates of the new room
\returns
returns whether or not the room that is going to be created already have an exsisting room
*/
/***********************************************/
bool Generator::CheckRoom(Vector2 newRoom)
{
	for (vector<Node*>::iterator iter = Rooms.begin();iter != Rooms.end();++iter)
	{
		Node *curr = (Node *)*iter;
		if (curr->RoomPosition == newRoom)
			return true;
	}
	return false;
}
/***********************************************/
/*!
\brief
connect the individual room nodes together 
*/
/***********************************************/
void Generator::ConnectRooms()
{
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		for (vector<Node*>::iterator iter2 = iter+1; iter2 != Rooms.end(); ++iter2)
		{
			Node *next = (Node *)*iter2;

			if (curr->RoomPosition + up == next->RoomPosition)
			{
				curr->up = next;
				next->down = curr;
			}
			if (curr->RoomPosition + down == next->RoomPosition)
			{
				curr->down = next;
				next->up = curr;
			}
			if (curr->RoomPosition + left == next->RoomPosition)
			{
				curr->left = next;
				next->right = curr;
			}
			if (curr->RoomPosition + right == next->RoomPosition)
			{
				curr->right = next;
				next->left = curr;
			}
		}
	}
}
/***********************************************/
/*!
\brief
generate the level of a room
\param number: the Type of the Room
		position: position of the new room 
/***********************************************/
void Generator::GenerateLevel(int number,Vector2 position)
{
	int randNo = rand() % number;
	while (randNo + 1 >= MaxRooms)
	{
		randNo = rand() % number;
	}
	Node*startRoom = new Node(randNo, position);
	Rooms.push_back(startRoom);
	CurRooms++;
}
/***********************************************/
/*!
\brief
read and change the map according to the room player is in
\param tilemap : to edit tilemap and change to its respective level
*/
/***********************************************/
void Generator::Read(TileMap * tilemap)
{
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		if (curr->RoomPosition == playerRoomPosition)
		{
			//curr->contentType = 4;
			switch (curr->contentType)
			{
		case LEVEL1:
			tilemap->LoadMap("Image//Maps//MapDesign_1.csv", 1024, 800);
			break;
		case LEVEL2:
			tilemap->LoadMap("Image//Maps//MapDesign_2.csv", 1024, 800);
			break;
		case LEVEL3:
			tilemap->LoadMap("Image//Maps//MapDesign_3.csv", 1024, 800);
			break;
		case LEVEL4:
			tilemap->LoadMap("Image//Maps//MapDesign_4.csv", 1024, 800);
			break;
		case LEVEL5:
			tilemap->LoadMap("Image//Maps//MapDesign_5.csv", 1024, 800);
			break;
		case LEVEL6:
			tilemap->LoadMap("Image//Maps//MapDesign_6.csv", 1024, 800);
			break;
		case LEVEL7:
			tilemap->LoadMap("Image//Maps//MapDesign_7.csv", 1024, 800);
			break;
		case LEVEL8:
			tilemap->LoadMap("Image//Maps//MapDesign_8.csv", 1024, 800);
			break; 
		case LEVEL9:
			tilemap->LoadMap("Image//Maps//MapDesign_9.csv", 1024, 800);
			break; 
		case LEVEL10:
			tilemap->LoadMap("Image//Maps//MapDesign_10.csv", 1024, 800);
			break;
			}
		}
	
	}
}
/***********************************************/
/*!
\brief
move to next room
\param addToCurrent:used to add to players curr pos
and transfer the map
*/
/***********************************************/
void Generator::GoToNextLevel(Vector2 AddToCurrent)
{
	playerRoomPosition = playerRoomPosition + AddToCurrent;
}
/***********************************************/
/*!
\brief
Get the Pointer that points to current room
\return
returns a Node pointer that is pointing to curr room
*/
/***********************************************/
Node* Generator::GetCurrentRoom()
{
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		if (curr->RoomPosition == playerRoomPosition)
			return curr;
	}
}
