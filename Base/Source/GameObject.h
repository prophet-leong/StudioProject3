#ifndef GAMEOBJECT_H 
#define GAMEOBJECT_H
#include "Vector2.h"
#include "Mesh.h"
#include <string>
#include "GeometryType.h"
using std::string;

class GameObject
{
public:
	GameObject();
	GameObject(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile);
	~GameObject();

	void Init(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile);
	void SetPos(int x,int y);
	void SetPos(Vector2 newPos);
	void SetTexture(GEOMETRY_TYPE newTexture);

	Vector2 GetPosition();

	//public variables
	int health;
	bool active;
	Vector2 scale;

	//Mesh* mesh;
	string meshName;
	string meshTexture;
	GEOMETRY_TYPE type;
protected:

	Vector2 Position;
	const int size = 32;

};

#endif GAMEOBJECT_H