#ifndef OBJ_MANAGER_H
#define OBJ_MANAGER_H
class GameObject
namespace objManager
{
	void UpdateObjects();
	void DrawObjects();
	GameObject* CreateObject(float x, float y, float velX, float velY);
}

#endif