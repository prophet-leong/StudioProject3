#ifndef GENERATOR_H
#define GENERATOR_H
#include "TileMap.h"
#include "MapNode.h"
#include "Hero.h"
#include "Enemy.h"
#include "Tile.h"

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

	const unsigned int MaxRooms = 7;
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