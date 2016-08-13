#ifndef GAMEOBJECT_H 
#define GAMEOBJECT_H
#include "Vector2.h"
#include "Mesh.h"
#include <string>
using std::string;

class GameObject
{
public:

	GameObject(int x, int y, string meshName, string meshTexture);
	~GameObject();

	void SetPos(int x,int y);
	void SetPos(Vector2 newPos);
	void SetTexture(string newTexture);

	Vector2 GetPosition();

	//public variables
	int health;
	bool active;
	Vector2 scale;

	Mesh* mesh;
	string meshName;
	string meshTexture;

protected:

	Vector2 Position;
	const int size = 32;

};

#endif GAMEOBJECT_H