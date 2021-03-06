#ifndef BITMAP_H
#define BITMAP_H
#include "globals.h"
#include <allegro5/allegro.h>
#include <vector>

namespace Bitmap
{
  enum bitmaps
  {
    IMG_TEST,
    IMG_TEST2,
    IMG_MAX
  };
  //public functions
  void Init();
  void DestroyBitmaps();

  void LoadBitmap(unsigned int bitmapNum);
  void LoadBitmap(std::vector<unsigned int> &bitmapNum);

  ALLEGRO_BITMAP* GetBitmap(unsigned int bitmapNum);
}

#endif