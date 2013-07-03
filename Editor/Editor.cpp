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

  Grid gridObject;

  void Init()
  {
    
  }
  
  void PlaceObject()
  {
    float x=0;
    float y=0;
    float gridX = Mouse::GetX() - ((int)Mouse::GetX() % gridSizeX);
    float gridY = Mouse::GetY() - ((int)Mouse::GetY() % gridSizeY);


    /*if(grid)
    {
      x = Mouse::GetX() - ((int)Mouse::GetX() % gridSizeX);
      y = Mouse::GetY() - ((int)Mouse::GetY() % gridSizeY);
    }
    else
    {
    */
      x = Mouse::GetX();
      y = Mouse::GetY();
    //}

    if(objManager::PlaceFree(Mouse::GetX(), Mouse::GetY()))
    {
      if(grid)        
        objManager::CreateObject(selectedObject, gridX, gridY, 0, 0);
      else
        objManager::CreateObject(selectedObject, x, y, 0, 0);
    }
  }

  void RemoveObject()
  {
    
    float x = Mouse::GetX();
    float y = Mouse::GetY();

    if(!objManager::PlaceFree(x, y))
    {
      objManager::DestroyObject(x, y);
    }
  }
  
  void SelectObject()
  {
    highlightedObject = objManager::GetGameObject(Mouse::GetX(), Mouse::GetY());
    //Find position relative to object before moving
  }
  void MoveObject()
  {
    if(!highlightedObject)
      return;

    //Set object position to mouse position with the relative distance found in
    //selectObject()

    highlightedObject->SetX(highlightedObject->GetX() + Mouse::GetDX());
    highlightedObject->SetY(highlightedObject->GetY() + Mouse::GetDY());
  }

  void Draw()
  {
    al_set_target_backbuffer(Display::GetDisplay());
    gridObject.SetSize(gridSizeX, gridSizeY);
    gridObject.Draw();
  }
}