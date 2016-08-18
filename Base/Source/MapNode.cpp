#include "MapNode.h"

/***********************************************/
/*!
\brief
default constructor
*/
/***********************************************/
Node::Node()
	: contentType(0)
	, RoomPosition(0,0)
	, up(NULL)
	, down(NULL)
	, left(NULL)
	, right(NULL)
{

}
/***********************************************/
/*!
\brief
constructor that takes in a content type and X-Y coordinates
\param contentType:Define the content of the room
		x : the X coordinate of the room 
		y : the Y coordinate of the room 
*/
/***********************************************/
Node::Node(int contentType,int x,int y)
	: contentType(contentType)
	, RoomPosition(x, y)
	, up(NULL)
	, down(NULL)
	, left(NULL)
	, right(NULL)
{

}
/***********************************************/
/*!
\brief
constructor that takes in a contentType and a Vector2
\param contentType:Define the content of the room
		newRoomPosition:The Position of the Room
*/
/***********************************************/
Node::Node(int contentType, Vector2 newRoomPosition)
	: contentType(contentType)
	, RoomPosition(newRoomPosition)
	, up(NULL)
	, down(NULL)
	, left(NULL)
	, right(NULL)
{

}
/***********************************************/
/*!
\brief
destructor that deletes the pointers created
*/
/***********************************************/
Node::~Node()
{
	delete up, down, left, right;
}

