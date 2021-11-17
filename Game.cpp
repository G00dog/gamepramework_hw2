#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Tile.h"
#include "Pillar.h"

Game* Game::s_pInstance = 0;

extern int tile[20];
extern int slimeX;
extern int slimeY;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }

  m_bRunning = true;

  if(!TheTextureManager::Instance()->load("Assets/Slime.png","slime",m_pRenderer))
  {
    return false;
  }
  if(!TheTextureManager::Instance()->load("Assets/Tile.png","tile",m_pRenderer))
  {
    return false;
  }
  if(!TheTextureManager::Instance()->load("Assets/Pillar.png","pillar",m_pRenderer))
  {
    return false;
  }

  for(int x = 0; x < 20; x++)
  {
    m_gameObjects.push_back(new Tile(new LoaderParams(x*32,448,32,32,"tile")));
  }
 
  m_gameObjects.push_back(new Pillar(new LoaderParams(300,384,64,64,"pillar")));
  m_gameObjects.push_back(new Pillar(new LoaderParams(400,384,64,64,"pillar")));
  m_gameObjects.push_back(new Pillar(new LoaderParams(400,320,64,64,"pillar")));
  m_gameObjects.push_back(new Pillar(new LoaderParams(500,384,64,64,"pillar")));

  m_gameObjects.push_back(new Player(new LoaderParams(slimeX,slimeY,32,32,"slime")));

  return true;
}

void Game::update()
{
   for(int i = 0; i<m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  
  for(int i = 0; i<m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }

  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::clean()
{
  TheInputHandler::Instance()->clean();
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}