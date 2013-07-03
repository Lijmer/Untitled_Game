#pragma once
class Grid
{
public:
  Grid(void);
  ~Grid(void);

  void SetSize(int x, int y)
  {
    Grid::x = x;
    Grid::y = y;
  }
  void Draw();
private:
  float x, y;
};

