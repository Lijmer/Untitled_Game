#include "Grid.h"
#include <allegro5/allegro_primitives.h>
#include "Display.h"

Grid::Grid(void)
{
  x=0;
  y=0;
}


Grid::~Grid(void)
{
}
void Grid::TranslateGrid(int &x, int &y)
{
  x-=x%Grid::x;
  y-=y%Grid::y;
  //x+=Grid::x/2;
  //y+=Grid::y/2;
}
void Grid::TranslateGrid(float &x, float &y)
{
  x-=(int)x % Grid::x;
  y-=(int)y % Grid::y;
  //x+=Grid::x/2;
  //y+=Grid::y/2;
}

void Grid::Draw()
{
  if(!x || !y)
    return;
  for(int i=0; i<_SH; i+=y)
  {
    al_draw_line(0, i, _SW, i, al_map_rgb(200,200,200), 1);
  }
  for(int i=0; i<_SW; i+=x)
  {
    al_draw_line(i, 0, i, _SH, al_map_rgb(200,200,200), 1);
  }  
}