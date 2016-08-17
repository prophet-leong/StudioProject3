#ifndef GATE_H
#define GATE_H
#include "Collideables.h"
#include "Hero.h"
#include "MapGenerator.h"

class Gate : public Collideables
{
public:
	Gate();
	Gate(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile, Generator * generator);
	virtual ~Gate();

	virtual bool CheckCollision(Avatar* theHero, TileMap* tilemap);
	virtual void CollisionResponse();

	Vector2 GetLocation();
	void SetLocation(Vector2 newLocation);
	bool Check(Vector2 Check);
private:
	string direction;
	Vector2 nextLocation;
	Generator* generator;
};

#endif