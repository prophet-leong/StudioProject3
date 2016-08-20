#include "PowerUp_Passive.h"
#include "Bullet_Surround.h"
#include "Hero.h"
PowerUp_Passive::PowerUp_Passive(GameObject *go,int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUp)
:PowerUp(x, y, typeOfTile, PowerUp)
{
	if (go->meshName == "HERO")
	{
		Hero* hero = (Hero*)go;
		for (int i = 0; i < 4; ++i)
		{
			Bullet_Surround* bullet = new Bullet_Surround(hero->GetPosition(), hero->direction, 1, 0, GEO_SALT, NO_ELEMENT, 50.f, float(90*i));
			bullet->SetScale(Vector2(0.3f,0.3f));
			hero->Projectile.push_back(bullet);
		}
	}
}


PowerUp_Passive::~PowerUp_Passive()
{
}
