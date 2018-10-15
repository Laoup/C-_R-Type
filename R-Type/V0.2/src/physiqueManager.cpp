#include "../include/element.hh"
#include "../include/ennemy.hh"
#include "../include/physiqueManager.hh"

#include <iostream> //debug

physiqueManager::physiqueManager()
{

}

physiqueManager::~physiqueManager()
{

}

void  physiqueManager::moveUP(element *entity)
{
  /*float x_pos;

  x_pos = player.getX();
  x_pos = x_pos - 0.5;*/
  entity->moveX(-0.85);
}

void  physiqueManager::moveDOWN(element *entity)
{
  /*float x_pos;

  x_pos = player.getX();
  x_pos = x_pos + 0.5;*/
  entity->moveX(0.85);
}

void  physiqueManager::moveLEFT(element *entity)
{
/*  float y_pos;

  y_pos = player.getY();
  y_pos = y_pos - 0.5;*/
  entity->moveY(-0.85);
  //entity->getPosition();
  //float x;
  //x = entity->getPosition().x;
  //std::cout << "x = " << entity->getPosition().x << std::endl;
  //player.move(0, -0.5);
}

void  physiqueManager::moveRIGHT(element *entity)
{
/*  float y_pos;

  y_pos = player.getY();
  y_pos = y_pos + 0.5;*/
  entity->moveY(0.85);
}

/*void  physiqueManager::moveEnnemy(std::vector<element *>::iterator it_ennemy)
{
  STRATEGY  st;


  st = *(it_ennemy)->getStrategy();
  if (st == STRATEGY::DEFAULT)
    moveLEFT(*it_ennemy);
}*/

void  physiqueManager::moveEnnemy(element *ennemy)
{
  STRATEGY  st;

  st = ennemy->getStrategy();
  if (st == STRATEGY::DEFAULT)
    moveLEFT(ennemy);
}

void  physiqueManager::checkCollision(element *player, element *ennemy)
{
  sf::Vector2f position_p;
  sf::Vector2f position_e;

  position_p = player->getPositionVector();
  position_e = ennemy->getPositionVector();


}
