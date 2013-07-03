#ifndef LEVEL_H
#define LEVEL_H

namespace Level
{
  enum levelID
  {
    LVL_TEST,
    LVL_MAX
  };

  void LoadLevel(int levelID);
  void SaveLevel();
  int GetCurrentLevel();


  /*Private fuctions that will be in cpp file
  *std::string& GetFilePath();
  *
  */
}

#endif