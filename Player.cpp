#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

int slimeX = 100;
int slimeY = 300;

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  handleInput();
  m_currentFrame = ((SDL_GetTicks() / 150) % 3);

  SDLGameObject::update();
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
  {
    m_velocity.setX(4);
    slimeX+=4;
    SDLGameObject::m_flip = SDL_FLIP_NONE;
  }
  else
  {
    m_velocity.setX(0);
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
  {
    m_velocity.setX(-4);
    slimeX-=4;
    SDLGameObject::m_flip = SDL_FLIP_HORIZONTAL;
  } 
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W) && isJump == false)
  {
    m_velocity.setY(-100);
    slimeY-=100;

    isJump = true;
  }
  else if(slimeY + 23 >= 448)
  {
    m_velocity.setY(0);
    isJump = false;
  }
  else
  {
    m_velocity.setY(5);//숫자 조절
    slimeY+=5;
  } 
}

void Player::clean() {}