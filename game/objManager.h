#ifndef OBJ_MANAGER_H
#define OBJ_MANAGER_H
class GameObject;



namespace objManager
{
	enum objectID
	{
		OBJ_TEST,
		OBJ_MAX
	};
	void Update();
	void Draw();
	GameObject* CreateObject(objectID ID,float x, float y, float velX, float velY);
}

#endif