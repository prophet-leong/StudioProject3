#ifndef MAP_NODE_H
#define MAP_NODE_H
#include"Vector2.h"
/**************************************************/
/*!
\file		MapNode.h
\author		Chua Teck Lee
\par		Email:C_tecklee@hotmail.com
\brief		Class to define a Room
*/
/**************************************************/

/**************************************************/
/*!
			Class MapNode:
\brief		Defines a Room Node and its methods
*/
/**************************************************/
class Node
{
public:
	Node();
	Node(int contentType,int x,int y);
	Node(int contentType, Vector2 newRoomPosition);
	~Node();

	int contentType;

	Vector2 RoomPosition;

	Node *up, *down, *left, *right;

};


#endif