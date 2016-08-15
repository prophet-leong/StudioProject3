#include "GameObject.h"
#include "GL\glew.h"

#include "MeshBuilder.h"
#include "LoadTGA.h"
GameObject::GameObject()
	:Position(0, 0)
	, active(true)
	, scale(1.f, 1.f)
	, meshName(meshName)
{

}

GameObject::GameObject(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile)
	: Position(x,y)
	, active(true)
	, scale(1.f,1.f)
	, meshName(meshName)
{
	//mesh = MeshBuilder::Generate2DMesh(meshName, Color(1, 1, 1), 0.0f, 0.0f, size * scale.x, size * scale.y);
	//mesh->textureID = LoadTGA(meshTexture.c_str());
	type = typeOfTile;
}

GameObject::~GameObject()
{

}

void GameObject::Init(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile)
{
	SetPos(x, y);
	this->active = true;
	this->scale.Set(1.f, 1.f);
	this->meshName = meshName;
	type = typeOfTile;
}

void GameObject::SetPos(int x, int y)
{
	Position.x = x;
	Position.y = y;
}

void GameObject::SetPos(Vector2 newPos)
{
	Position.x = newPos.x;
	Position.y = newPos.y;
}

void GameObject::SetTexture(GEOMETRY_TYPE newTexture)
{
	type = newTexture;
	//mesh->textureID = LoadTGA(meshTexture.c_str());
}

Vector2 GameObject::GetPosition()
{
	return Position;
}