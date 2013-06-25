#include "objManager.h"
#include "globals.h"
#include "GameObject.h"
#include <map>
#include <vector>

#include "obj_Test.h"

namespace objManager
{
	std::map<int, std::vector<GameObject*>> objects;
	std::vector<GameObject*> banana;

	obj_Test *obj_test;
	
	void UpdateObjects();
	void Collisions();

	void Update()
	{
		UpdateObjects();
		Collisions();
	}
	void Draw()
	{
		std::map<int, std::vector<GameObject*>>::iterator iter;
		std::vector<GameObject*>::iterator iter2;
		for(iter = objects.begin(); iter!=objects.end(); iter++)
		{
			for(iter2 = (*iter).second.begin(); iter2 != (*iter).second.end(); ++iter2)
				(*iter2)->Draw();
		}
	}
	GameObject* CreateObject(objectID ID,float x, float y, float velX, float velY)
	{
		switch(ID)
		{
		case OBJ_TEST:
			obj_test = new obj_Test();
			obj_test->Init(x,y,velX,velY);			
			objects[obj_test->GetDepth()].push_back(obj_test);
			return obj_test;
			break;
		}
	}

	//private
	void UpdateObjects()
	{
		std::map<int, std::vector<GameObject*>>::iterator iter;
		std::vector<GameObject*>::iterator iter2;
		for(iter = objects.begin(); iter!=objects.end(); iter++)
		{
			for(iter2 = (*iter).second.begin(); iter2 != (*iter).second.end(); ++iter2)
				(*iter2)->Update();
		}
	}
	void Collisions()
	{
		std::map<int, std::vector<GameObject*>>::iterator miter;
		std::map<int, std::vector<GameObject*>>::iterator miter2;
		std::vector<GameObject*>::iterator iter;
		std::vector<GameObject*>::iterator iter2;
		for(miter = objects.begin(); miter!=objects.end(); ++miter)
		{
			for(iter = (*miter).second.begin(); iter != (*miter).second.end(); ++iter)
			{
				for(miter2 = miter; miter2!=objects.end(); ++miter2)
				{
					if(miter2 == miter)
						iter2=iter+1;
					else
						iter2=(*miter2).second.begin();
					for(; iter2!=(*miter2).second.end(); ++iter2)
					{
						if((*iter)->CheckCollision(*iter2))
						{
							if(iter == iter2)
								continue;
							if(!(*iter)->GetCollidable() || !(*iter2)->GetCollidable())
								continue;

							(*iter)->Collided(*iter2);
							(*iter2)->Collided(*iter);
						}
					}
				}
			}
		}
	}
}