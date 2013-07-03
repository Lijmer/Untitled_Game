#include "objManager.h"

#include <allegro5/allegro_native_dialog.h>
#include <map>
#include <vector>

#include "globals.h"
#include "Display.h"
#include "GameObject.h"

#include "Mask.h"
#include "RectangleMask.h"
#include "CircleMask.h"
#include "TriangleMask.h"

#include "obj_Test.h"
#include "obj_Test2.h"

namespace objManager
{
  std::map<int, std::vector<GameObject*>> objects;
  std::map<int, std::vector<GameObject*>> staticObjects;
  std::vector<GameObject*> banana;

  obj_Test  *obj_test;
  obj_Test2 *obj_test2;

  void UpdateObjects();
  void Collisions();

  void Init()
  {
  }

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
  void DrawStaticObjects()
  {

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
    case OBJ_TEST2:
      obj_test2 = new obj_Test2();
      obj_test2->Init(x,y,velX,velY);			
      objects[obj_test2->GetDepth()].push_back(obj_test2);
      return obj_test2;
      break;
    }
    return 0;
  }

  GameObject* GetGameObject(float x, float y)
  {
    std::map<int, std::vector<GameObject*>>::const_iterator iter;
    std::vector<GameObject*>::const_iterator iter2;
    for(iter = objects.begin(); iter!= objects.end(); ++iter)
    {
      for(iter2=(*iter).second.begin(); iter2!=(*iter).second.end(); ++iter2)
      {
        //if( (int)(*iter2)->GetX() == (int)x && (int)(*iter2)->GetY() == (int)y)
          //return (*iter2);
        if((*iter2)->CheckCollision(x, y))
          return (*iter2);
      }
    }
    return 0;
  }

  bool PlaceFree(float x, float y)
  {
    std::map<int, std::vector<GameObject*>>::const_iterator iter;
    std::vector<GameObject*>::const_iterator iter2;
    for(iter = objects.begin(); iter!=objects.end(); ++iter)
    {
      for(iter2 = (*iter).second.begin(); iter2!=(*iter).second.end(); ++iter2)
      {
        //if( (int)(*iter2)->GetX() == (int)x && (int)(*iter2)->GetY() == (int)y)
        //  return false;
        if((*iter2)->CheckCollision(x, y))
          return false;
      }
    }
    return true;
  }
  bool PlaceFree(float x, float y, objectID otherID)
  {
    std::map<int, std::vector<GameObject*>>::const_iterator iter;
    std::vector<GameObject*>::const_iterator iter2;
    for(iter = objects.begin(); iter!=objects.end(); ++iter)
    {
      for(iter2 = (*iter).second.begin(); iter2!=(*iter).second.end(); ++iter2)
      {
        if( (int)(*iter2)->GetX() == (int)x &&
          (int)(*iter2)->GetY() == (int)y &&
          (*iter2)->GetID() == otherID)
        {
          return false;
        }
      }
    }
    return true;
  }
  bool PlaceFree(float x, float y, Mask &mask)
  {
    std::map<int, std::vector<GameObject*>>::const_iterator iter;
    std::vector<GameObject*>::const_iterator iter2;
    for(iter = objects.begin(); iter!=objects.end(); ++iter)
    {
      for(iter2 = (*iter).second.begin(); iter2!=(*iter).second.end(); ++iter2)
      {
        if((*iter2)->CheckCollision(mask))
          return false;
      }
    }
    return true;
  }
  bool PlaceFree(float x, float y, Mask &mask, objectID otherID)
  {
    std::map<int, std::vector<GameObject*>>::const_iterator iter;
    std::vector<GameObject*>::const_iterator iter2;
    for(iter = objects.begin(); iter!=objects.end(); ++iter)
    {
      for(iter2 = (*iter).second.begin(); iter2!=(*iter).second.end(); ++iter2)
      {
        if((*iter2)->GetID() != otherID)
          continue;

        if((*iter2)->CheckCollision(mask))
          return false;
      }
    }
    return true;
  }

  void DestroyObject(float x, float y)
  {
    std::map<int, std::vector<GameObject*>>::iterator iter;
    std::vector<GameObject*>::iterator iter2;
    for(iter = objects.begin(); iter!=objects.end(); ++iter)
    {
      for(iter2 = (*iter).second.begin(); iter2!=(*iter).second.end(); ++iter2)
      {
        if((*iter2)->CheckCollision(x,y))
        {
          (*iter2)->Destroy();
          delete (*iter2);
          (*iter).second.erase(iter2);
          return;
        }
      }
    }
  }
  void DestroyObject(GameObject *object)
  {
    std::map<int, std::vector<GameObject*>>::iterator iter;
    std::vector<GameObject*>::iterator iter2;
    for(iter = objects.begin(); iter!=objects.end(); ++iter)
    {
      for(iter2 = (*iter).second.begin(); iter2!=(*iter).second.end(); ++iter2)
      {
        if((*iter2) == object)
        {
          (*iter2)->Destroy();
          delete (*iter2);
          (*iter).second.erase(iter2);
          return;
        }
      }
    }
    al_show_native_message_box(Display::GetDisplay(), "objManager", "Error", 
      "Tried to destroy object that is not in vector, something is very wrong",
      0, ALLEGRO_MESSAGEBOX_ERROR);
  }

  void DestroyAllObjects()
  {
    std::map<int, std::vector<GameObject*>>::iterator iter;
    std::vector<GameObject*>::iterator iter2;
    for(iter = objects.begin(); iter!=objects.end(); ++iter)
    {
      for(iter2 = (*iter).second.begin(); iter2!=(*iter).second.end();)
      {
        (*iter2)->Destroy();
        delete (*iter2);
        iter2 = (*iter).second.erase(iter2);
      }
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
