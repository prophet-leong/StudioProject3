#include "MapNode.h"


Node::Node()
	: contentType(0)
	, RoomPosition(0,0)
	, up(NULL)
	, down(NULL)
	, left(NULL)
	, right(NULL)
{

}

Node::Node(int contentType,int x,int y)
	: contentType(contentType)
	, RoomPosition(x, y)
	, up(NULL)
	, down(NULL)
	, left(NULL)
	, right(NULL)
{

}

Node::Node(int contentType, Vector2 newRoomPosition)
	: contentType(contentType)
	, RoomPosition(newRoomPosition)
	, up(NULL)
	, down(NULL)
	, left(NULL)
	, right(NULL)
{

}

Node::~Node()
{
	delete up, down, left, right;
}

