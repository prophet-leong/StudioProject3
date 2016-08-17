#ifndef GEOMETRYTYPE_H
#define GEOMETRYTYPE_H
////comment this out later
#include <iostream>

enum GEOMETRY_TYPE
{
	GEO_AXES,
	GEO_CROSSHAIR,
	GEO_LIGHTBALL,
	GEO_SPHERE,
	GEO_QUAD,
	GEO_CUBE,
	GEO_RING,
	GEO_CONE,
	GEO_BACKGROUND,
	GEO_OBJECT,
	GEO_TEXT,
	GEO_MARIO,
	GEO_COIN,
	// ground tile
	GEO_TILEGROUND,
	//tree tile
	GEO_TILETREE,
	//rear map
	GEO_TILESTRUCTURE,
	//hero
	GEO_TILEHERO_FRAME0,
	GEO_TILEHERO_FRAME1,
	GEO_TILEHERO_FRAME2,
	GEO_TILEHERO_FRAME3,
	//enemy
	GEO_TILEENEMY_FRAME0,
	GEO_TILEENEMY_FRAME1,
	GEO_TILEENEMY_FRAME2,
	GEO_TILEENEMY_FRAME3,

	//Placeholder
	GEO_PLACEHOLDER,

	//bullet for hero
	GEO_SALT,
	GEO_FIRESALT,
	NUM_GEOMETRY,

	//Trap Section
	GEO_SPIKE_TRAP,


};





#endif // !GEOMETRYTYPE_H
