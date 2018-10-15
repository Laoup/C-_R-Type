#include "../include/element.hh"
#include "../include/physiqueManager.hh"

physiqueManager::physiqueManager()
{

}

physiqueManager::~physiqueManager()
{

}

void  physiqueManager::moveUP(element &player)
{
  /*float x_pos;

  x_pos = player.getX();
  x_pos = x_pos - 0.5;*/
  player.moveX(-0.85);
}

void  physiqueManager::moveDOWN(element &player)
{
  /*float x_pos;

  x_pos = player.getX();
  x_pos = x_pos + 0.5;*/
  player.moveX(0.85);
}

void  physiqueManager::moveLEFT(element &player)
{
/*  float y_pos;

  y_pos = player.getY();
  y_pos = y_pos - 0.5;*/
  player.moveY(-0.85);
  //player.move(0, -0.5);
}

void  physiqueManager::moveRIGHT(element &player)
{
/*  float y_pos;

  y_pos = player.getY();
  y_pos = y_pos + 0.5;*/
  player.moveY(0.85);
}
