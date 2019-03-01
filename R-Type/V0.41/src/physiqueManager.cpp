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
  else if (st == STRATEGY::BOSS)
    ;
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
        moveLEFT(vec[i], SPEED * 3);
      else if (direct == DIRECTION::RIGHT)
        moveRIGHT(vec[i], SPEED * 3);
      i++;
    }
}


void  physiqueManager::checkCollision(element *player, element *ennemy, std::vector<object *> &objs)
{
  /*sf::Vector2f position_p;
  sf::Vector2f position_e;*/
  std::array<float, 4> position_p;
  std::array<float, 4> position_e;

  position_p = player->getPositionVector();
  position_e = ennemy->getPositionVector();

  //printf("pos_p : y = %f, pos_p : height = %f\npos_e : y = %f, pos_e : height = %f\n", position_p[1], position_p[3], position_e[1], position_e[3]);
  //printf("here player position x %f, and position y %f, width = %f, height = %f\n", position_p[0], position_p[1], position_p[2], position_p[3]);
  if (position_e[0] - position_e[3] > (position_p[0] + position_p[3])
   || position_e[0] + position_e[3] < (position_p[0] - position_p[3])
   || position_p[1] - (position_p[3] / 2) > position_e[1] + (position_e[3] / 2)
   || position_p[1] + (position_p[3] / 2) < position_e[1] - (position_e[3] / 2)
   || player->getOut() == 1 || ennemy->getOut() == 1 || player->getSolid() == false
   || ennemy->getSolid() == false)
    ;
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

void  physiqueManager::checkBorderCollision(element *player, view &v)
{
  std::array<float, 4>  pos;

  pos = player->getPositionVector();

  if (player->getLimited() == true)
  {
    if (pos[0] - v.getLeftSidePos() < 50)
      player->setOut(1);
    else if (pos[0] > v.getRightSidePos() - 50)
      player->setOut(1);
    else if (pos[1] - v.getUpSidePos() < 100)
      player->setOut(1);
    else if (pos[1] > v.getDownSidePos() - 100)
      player->setOut(1);
  }
}

object*  physiqueManager::fireOrder(ship *ship, DIRECTION direction)
{
  return (ship->fireing(direction));
}

void    physiqueManager::TileTheMap(int xSizeWindow, int xSizeBackground, std::array<int, 3> &arr)
{
  printf("TILE THE MAP: xSizeWindow = %d, xSizeBackground = %d", xSizeWindow, xSizeBackground);
  //std::array<int, 3>  arr;
  int ref;
  int count;

  count = 0;
  ref = xSizeWindow / 2;
  printf("      ref = %d", ref);
  arr[2] = 0;
  if ((2 * ref) >= xSizeBackground)
    {
      arr[0] = -1;
      arr[1] = -1;
      //return (arr);
    }
  while (xSizeBackground >= ref)
    {
      xSizeBackground = xSizeBackground - ref;
      count = count + 1;
    }
  arr[0] = ref;
  printf("    arr[0] = %d, ref = %d\n", arr[0], ref);
  arr[1] = count;
  //return (arr);
}

//Clairement des choses a revoir sur cette fonction !
void            physiqueManager::generateEnnemys(int posSide, std::array<int, 3> &arr, std::vector<ship *> &ships, int xSizeBackground, int xSizeWindow)
{
  int           count;
  float         stock;
  std::vector<ship *>::iterator it;
  bool          boss;

  printf("%d < %d\n", xSizeBackground, xSizeWindow);
  printf("%d", posSide);


  if (posSide + (X_SIZE_WINDOW / 2) < xSizeBackground - xSizeWindow)
    {
      count = 0;
      stock = 0;
      while (posSide >= stock)
        {
          count = count + 1;
          //stock = arr[0] * count;
          stock = (X_SIZE_WINDOW / 2) * count;
        }
      if (count != arr[2])
        {
          ships.push_back(new ennemy);
          it = ships.end() - 1;
          (*it)->setPosition(posSide + (arr[0] / 6) ,250);
          ships.push_back(new ennemy);
          it = ships.end() - 1;
          (*it)->setPosition(posSide + (arr[0] / 0.75) ,250);
          arr[2] = count;
        }
    }
  else
    {
      boss = false;
      it = ships.begin();
      while (it != ships.end())
        {
          if ((*it)->getBoss() == true)
            boss = true;
          it++;
        }
      if (boss == false)
        {
          ships.push_back(new ennemy("./ressources/boss.png", STRATEGY::BOSS, 155, 166));
          it = ships.end() - 1;
          (*it)->setLifePoints(3);
          (*it)->promote();
          //(*it)->setPosition(xSizeBackground - (xSizeWindow / 2), 250);
          printf("utils size background%d\n", xSizeBackground);
          (*it)->setPosition(xSizeBackground - 155, 250);//+155 = largeur de l'ennemi
          (*it)->setRotation(90);
        }
    }
}
