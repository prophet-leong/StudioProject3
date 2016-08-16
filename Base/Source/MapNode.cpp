#include "MapNode.h"


Node::Node()
	: contentType(0)
	, RoomPosition(0,0)
	//, left(nullptr)
	//, right(nullptr)
	//, up(nullptr)
	//, down(nullptr)
{

}

Node::Node(int contentType,int x,int y)
	: contentType(contentType)
	, RoomPosition(x,y)
	/*
	, left(nullptr)
	, right(nullptr)
	, up(nullptr)
	, down(nullptr)*/
{

}

Node::Node(int contentType, Vector2 newRoomPosition)
	: contentType(contentType)
	, RoomPosition(newRoomPosition)
{

}

Node::~Node()
{
}

