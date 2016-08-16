#include "MapGenerator.h"
#include <time.h>

Generator::Generator()
	: CurRooms(0)
	, level(LEVEL1)
	, playerRoomPosition(0,0)
{
}

Generator::~Generator()
{
}

void Generator::GenerateStructure(/*int seed*/)
{
	srand(time(NULL));
	
	if (CurRooms == 0)
		GenerateLevel(MaxRooms + 1,Vector2(0,0));

	while (CurRooms < MaxRooms)
	{
		//check room
		Vector2 newRoom = Rooms[CurRooms - 1]->RoomPosition + RandomDirection();

		//check surrounding
		if (!CheckRoom(newRoom))
			GenerateLevel(MaxRooms + 1, newRoom); 
	}
}

Vector2 Generator::RandomDirection()
{
	int direction = rand() % 4 + 1;
	switch (direction)
	{
	case 1:
		return Vector2(0, 1);
		break;
	case 2:
		return Vector2(0, -1);
		break;
	case 3:
		return Vector2(1, 0);
		break;
	case 4:
		return Vector2(-1, 0);
		break;
	}
}

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

void Generator::GenerateLevel(int number,Vector2 position)
{
	Node*startRoom = new Node(rand() % number, position);
	Rooms.push_back(startRoom);
	CurRooms++;
}

void Generator::Read(TileMap * tilemap)
{
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		if (curr->RoomPosition == playerRoomPosition)
		{
			switch (curr->contentType)
			{
		case LEVEL1:
			tilemap->LoadMap("Image//MapDesign_1.csv", 1024, 800);
			break;
		case LEVEL2:
			tilemap->LoadMap("Image//MapDesign_2.csv", 1024, 800);
			break;
		case LEVEL3:
			tilemap->LoadMap("Image//MapDesign_3.csv", 1024, 800);
			break;
		case LEVEL4:
			tilemap->LoadMap("Image//MapDesign_4.csv", 1024, 800);
			break;
		case LEVEL5:
			tilemap->LoadMap("Image//MapDesign_5.csv", 1024, 800);
			break;
		case LEVEL6:
			tilemap->LoadMap("Image//MapDesign_6.csv", 1024, 800);
			break;
		case LEVEL7:
			tilemap->LoadMap("Image//MapDesign_7.csv", 1024, 800);
			break;
			}
		}
	
	}
}
