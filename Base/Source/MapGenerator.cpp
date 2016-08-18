#include "MapGenerator.h"
#include <time.h>

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

Generator::~Generator()
{
}

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
			GenerateLevel(MaxRooms, newRoom);
	}
}

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

void Generator::GenerateLevel(int number,Vector2 position)
{
	Node*startRoom = new Node(rand() % number, position);
	Rooms.push_back(startRoom);
	CurRooms++;
}
#include<iostream>
void Generator::Read(TileMap * tilemap)
{
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		std::cout << curr->RoomPosition << endl;
	}
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		if (curr->RoomPosition == playerRoomPosition)
		{
			curr->contentType = 0;
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

void Generator::GoToNextLevel(Vector2 AddToCurrent)
{
	playerRoomPosition = playerRoomPosition + AddToCurrent;
}

bool Generator::Check(Vector2 AddToNext)
{
	Vector2 tempPos = playerRoomPosition + AddToNext;
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		if (curr->RoomPosition == tempPos)
			return true;
	}
	return false;
}

Node* Generator::GetCurrentRoom()
{
	for (vector<Node*>::iterator iter = Rooms.begin(); iter != Rooms.end(); ++iter)
	{
		Node *curr = (Node *)*iter;
		if (curr->RoomPosition == playerRoomPosition)
			return curr;
	}
}
