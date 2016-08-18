#ifndef MAP_NODE_H
#define MAP_NODE_H
#include"Vector2.h"

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