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
  void TranslateGrid(int &x, int&y);
  void TranslateGrid(float &x, float &y);
  void Draw();
private:
  int x, y;
};

