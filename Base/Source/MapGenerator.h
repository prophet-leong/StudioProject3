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
		LEVELS_END,
	};
	LEVELS level;

	void GenerateStructure(/*int seed*/);
	void Read(TileMap * tilemap);
	bool Check(Vector2 AddtoNext);
	void GoToNextLevel(Vector2 AddToCurrent);

	const unsigned int MaxRooms = LEVELS_END;
	unsigned int CurRooms;

private:
	//pointers to node
	
	bool CheckRoom(Vector2 newRoom);
	Vector2 RandomDirection();
	void GenerateLevel(int number,Vector2 position);

	vector<Node*>Rooms;
	Vector2 playerRoomPosition;

};

#endif