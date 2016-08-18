#ifndef GENERATOR_H
#define GENERATOR_H
#include "TileMap.h"
#include "MapNode.h"

class Generator
{
public:
	Generator();
	~Generator();

	enum LEVELS
	{
		LEVEL1,
		LEVEL2,
		LEVEL3,
		LEVEL4,
		LEVEL5,
		LEVEL6,
		LEVEL7,
		LEVEL8,
		LEVEL9,
		LEVEL10,
		LEVELS_END,
	};
	LEVELS level;

	void GenerateStructure(/*string seed*/);
	void Read(TileMap * tilemap);
	bool Check(Vector2 AddtoNext);
	void GoToNextLevel(Vector2 AddToCurrent);
	void ConnectRooms();

	Node* GetCurrentRoom();

	const unsigned int MaxRooms = LEVELS_END;
	unsigned int CurRooms;

private:
	//pointers to node
	
	bool CheckRoom(Vector2 newRoom);
	Vector2 RandomDirection();
	void GenerateLevel(int number,Vector2 position);

	vector<Node*>Rooms;
	Vector2 playerRoomPosition;
	Vector2 up, down, left, right;

};

#endif