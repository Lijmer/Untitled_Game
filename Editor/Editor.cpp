#include "Editor.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "objManager.h"
#include "GameObject.h"
#include "Display.h"
#include "Grid.h"

namespace Editor
{
  bool grid = true;
  int gridSizeX = 32;
  int gridSizeY = 32;
  objectID selectedObject = OBJ_TEST;

  GameObject* highlightedObject = 0;  
  float relativeX=0;
  float relativeY=0;

  Grid gridObject;



  void Init()
  {
    
  }
  
  void PlaceObject()
  {
    float x = Mouse::GetX();
    float y = Mouse::GetY();

    if(!Keyboard::GetKey(ALLEGRO_KEY_ALT) || !grid)
      gridObject.TranslateGrid(x,y);

    if(objManager::PlaceFree(Mouse::GetX(), Mouse::GetY()))
      SelectObject(objManager::CreateObject(selectedObject, x, y, 0, 0));
  }

  void RemoveObject()
  {
    
    float x = Mouse::GetX();
    float y = Mouse::GetY();

    if(!objManager::PlaceFree(x, y))
      objManager::DestroyObject(x, y);
  }
  
  void SelectObject()
  {
    highlightedObject = objManager::GetGameObject(Mouse::GetX(), Mouse::GetY());
    if(!highlightedObject)
      return;
    relativeX = highlightedObject->GetX() - Mouse::GetX();
    relativeY = highlightedObject->GetY() - Mouse::GetY();
  }
  void SelectObject(GameObject *object)
  {
    highlightedObject = object;
    if(!highlightedObject)
      return;
    relativeX = highlightedObject->GetX() - Mouse::GetX();
    relativeY = highlightedObject->GetY() - Mouse::GetY();
  }
  void DeselectObject()
  {
    highlightedObject = 0;
    relativeX=0;
    relativeY=0;
  }
  void MoveObject()
  {
    if(!highlightedObject)
      return;
    float x = Mouse::GetX() + relativeX;
    float y = Mouse::GetY() + relativeY;

    if(!Keyboard::GetKey(ALLEGRO_KEY_ALT) || !grid)
      gridObject.TranslateGrid(x,y);

    highlightedObject->SetX(x);
    highlightedObject->SetY(y);
  }

  void Draw()
  {
    al_set_target_backbuffer(Display::GetDisplay());
    gridObject.SetSize(gridSizeX, gridSizeY);
    gridObject.Draw();
  }
}