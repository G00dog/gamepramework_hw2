#pragma once

#include "SDLGameObject.h"
#include "SDL.h"

class Pillar : public SDLGameObject
{
public:
  Pillar(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};