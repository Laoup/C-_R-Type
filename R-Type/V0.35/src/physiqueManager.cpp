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

void  physiqueManager::moveUP(element *entity, float speed)
{
  /*float x_pos;

  x_pos = player.getX();
  x_pos = x_pos - 0.5;*/
  entity->moveX(-1*speed);
}

void  physiqueManager::moveDOWN(element *entity, float speed)
{
  /*float x_pos;

  x_pos = player.getX();
  x_pos = x_pos + 0.5;*/
  entity->moveX(speed);
}

void  physiqueManager::moveLEFT(element *entity, float speed)
{
/*  float y_pos;

  y_pos = player.getY();
  y_pos = y_pos - 0.5;*/
  entity->moveY(-1*speed);
  //entity->getPosition();
  //float x;
  //x = entity->getPosition().x;
  //std::cout << "x = " << entity->getPosition().x << std::endl;
  //player.move(0, -0.5);
}

void  physiqueManager::moveRIGHT(element *entity, float speed)
{
/*  float y_pos;

  y_pos = player.getY();
  y_pos = y_pos + 0.5;*/
  entity->moveY(speed);
}

/*void  physiqueManager::moveEnnemy(std::vector<element *>::iterator it_ennemy)
{
  STRATEGY  st;


  st = *(it_ennemy)->getStrategy();
  if (st == STRATEGY::DEFAULT)
    moveLEFT(*it_ennemy);
}*/


void  physiqueManager::moveEnnemy(ship *ennemy)
{
  STRATEGY  st;

  st = ennemy->getStrategy();
  if (st == STRATEGY::DEFAULT)
    moveLEFT(ennemy);
}

void  physiqueManager::moveObjectVector(std::vector<object *> vec)
{
  DIRECTION direct;
  int       i;

  i = 0;
  while (i != vec.size())
    {
      direct = vec[i]->getDirection();
      if (direct == DIRECTION::LEFT)
        moveLEFT(vec[i], 2.5);
      else if (direct == DIRECTION::RIGHT)
        moveRIGHT(vec[i], 2.5);
      i++;
    }
}

//Il Faudra absolument reprendre le système de collision il est tres flou pour l'instant
void  physiqueManager::checkCollision(element *player, element *ennemy, std::vector<object *> &objs)
{
  /*sf::Vector2f position_p;
  sf::Vector2f position_e;*/
  std::array<float, 4> position_p;
  std::array<float, 4> position_e;

  position_p = player->getPositionVector();
  position_e = ennemy->getPositionVector();

  if (((position_e[0] - (position_e[3])) > (position_p[0] + (position_p[3])))
  || ((position_e[0] + position_e[3]) < (position_p[0] - position_p[3]))
  || (position_e[1] - (position_e[4] / 3)) > (position_p[1] + (position_p[4]))
  || (position_e[1] + (position_e[4] / 3) ) < (position_p[1] - (position_p[4] / 4))
  || player->getOut() == 1 || ennemy->getOut() == 1 || player->getSolid() == false
  || ennemy->getSolid() == false)
    printf("here player position x %f, and position y %f, width = %f, height = %f\n", position_p[0], position_p[1], position_p[2], position_p[3]);
  else
    {
      player->setOut(1);
      ennemy->setOut(1);
      printf("BOOOOOOOOOUM!!!!!!!!!!!!!!");
      object  *n_obj;
      n_obj = new object(TYPE::EXPLOSION);
      n_obj->setPosition(ennemy->getPosition().x, ennemy->getPosition().y);
      objs.push_back(n_obj);
      //printf("here player position x %f, and position y %f\n", position_p.x, position_p.y);
    }

}

/*void  physiqueManager::checkBorderCollision(element *player)
{
  std::array<float, 4>  pos;

  pos = player->getPositionVector();

  if (pos.x < )
}*/

object*  physiqueManager::fireOrder(ship *ship, DIRECTION direction)
{
  return (ship->fireing(direction));
}
