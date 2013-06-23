#include "objManager.h"
#include "globals.h"
#include "GameObject.h"
#include <map>
#include <vector>
namespace objManager
{
	std::map<int, std::vector<GameObject*>> objects;

	void Update()
	{
		std::map<int, std::vector<GameObject*>>::iterator iter;
		std::vector<GameObject*>::iterator iter2;
		for(iter = objects.begin(); iter!=objects.end(); iter++)
		{
			
		}
	}
}