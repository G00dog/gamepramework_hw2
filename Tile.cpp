#include "Tile.h"

int tile[20] {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

Tile::Tile(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Tile::draw()
{
  SDLGameObject::draw();
}

void Tile::update()
{
  SDLGameObject::update();
}

void Tile::clean() {}