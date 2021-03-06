#pragma once

#include "SDLGameObject.h"
#include "SDL.h"

class Tile : public SDLGameObject
{
public:
  Tile(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};