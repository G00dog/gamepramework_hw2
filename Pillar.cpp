#include "Pillar.h"

Pillar::Pillar(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Pillar::draw()
{
  SDLGameObject::draw();
}

void Pillar::update()
{
  SDLGameObject::update();
}

void Pillar::clean() {}