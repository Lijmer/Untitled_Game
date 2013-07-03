#ifndef OBJ_MANAGER_H
#define OBJ_MANAGER_H
class GameObject;
class Mask;

enum objectID
{
  UNDEFINED,
  OBJ_TEST,
  OBJ_TEST2,
  OBJ_MAX
};

namespace objManager
{
  
  void Init();
  void Update();
  void Draw();
  GameObject* CreateObject(objectID ID,float x, float y, float velX, float velY);

  GameObject* GetGameObject(float x, float y);

  bool PlaceFree(float x, float y);
  bool PlaceFree(float x, float y, objectID otherID);
  bool PlaceFree(float x, float y, Mask &mask);
  bool PlaceFree(float x, float y, Mask &mask, objectID otherID);

  void DestroyObject(float x, float y);
  void DestroyObject(GameObject *object);
  void DestroyAllObjects();
}

#endif