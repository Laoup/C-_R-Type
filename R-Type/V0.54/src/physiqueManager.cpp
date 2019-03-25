#include "../include/element.hh"
#include "../include/ennemy.hh"
#include "../include/physiqueManager.hh"

physiqueManager::physiqueManager()
{

}

physiqueManager::~physiqueManager()
{

}

void  physiqueManager::moveEnnemy(std::shared_ptr<ship> ennemy)
{
  STRATEGY  st;
  int       x;
  int       y;

  st = ennemy->getStrategy();
  if (st == STRATEGY::DEFAULT)
    ennemy->getDrawable().move(-1 * SPEED, 0);
  else if (st == STRATEGY::BOSS)
    {
      y = ennemy->getDrawable().getPosition().y;
      if (y > 375)
        ennemy->setMemorie(false);
      else if (y < 125)
        ennemy->setMemorie(true);
      if (ennemy->getMemorie() == false)
        ennemy->getDrawable().move(0, -1 * SPEED);
      if (ennemy->getMemorie() == true)
        ennemy->getDrawable().move(0, SPEED);
    }
}

void  physiqueManager::moveObjectVector(std::vector<std::shared_ptr<object>> vec)
{
  DIRECTION direct;
  int       i;

  i = 0;
  while (i != vec.size())
    {
      direct = vec[i]->getDirection();
      if (direct == DIRECTION::LEFT)
        vec[i]->getDrawable().move(-1 * (SPEED * 3), 0);
      else if (direct == DIRECTION::RIGHT)
        vec[i]->getDrawable().move(SPEED * 3, 0);
      else if (direct == DIRECTION::LEFTINF)
        vec[i]->getDrawable().move(-1 * (SPEED * 3), SPEED * 3);
      else if (direct == DIRECTION::LEFTSUP)
        vec[i]->getDrawable().move(-1 * (SPEED * 3), -1 * (SPEED * 3));
      else if (direct == DIRECTION::RIGHTINF)
        vec[i]->getDrawable().move(SPEED * 3, SPEED * 3);
      else if (direct == DIRECTION::RIGHTSUP)
        vec[i]->getDrawable().move(SPEED * 3, -1 * (SPEED * 3));
      i++;
    }
}

void  physiqueManager::checkCollision(std::shared_ptr<element> player, std::shared_ptr<element> ennemy, std::vector<std::shared_ptr<object>> &objs, std::shared_ptr<handlerSprite> sprite_manager)
{
  std::array<float, 4> position_p;
  std::array<float, 4> position_e;
  //object               *n_obj;
  std::shared_ptr<object> n_obj;

  position_p = player->getPositionVector();
  position_e = ennemy->getPositionVector();

  /*if (position_e[0] - position_e[3] > (position_p[0] + position_p[3])
   || position_e[0] + position_e[3] < (position_p[0] - position_p[3])
   || position_p[1] - (position_p[3] / 2) > position_e[1] + (position_e[3] / 2)
   || position_p[1] + (position_p[3] / 2) < position_e[1] - (position_e[3] / 2)
   || player->getOut() == 1 || ennemy->getOut() == 1 || player->getSolid() == false
   || ennemy->getSolid() == false)
      ;*/
  //printf("\n\nPlayer -> vec.x = %f,   vec.y = %f  ,    height = %f\n", position_p[0], position_p[1], position_p[3]);
  //printf("Ennemy -> vec.x = %f,  vec.y = %f,        height = %f\n\n", position_e[0], position_e[1], position_e[3]);
  if (position_e[0] > (position_p[0] + position_p[2] - 10)
  || (position_e[1] + position_e[3] - 15) < position_p[1]
  || position_e[1] > (position_p[1] + position_p[3] - 10)
  || (position_e[0] + position_e[2] - 10) < position_p[0]
  || player->getOut() == 1 || ennemy->getOut() == 1 || player->getSolid() == false
  || ennemy->getSolid() == false)
          ;
  else
    {
      player->takeDamage();
      ennemy->takeDamage();
      if (player->getLifePoints() == 0)
        player->setOut(1);
      if (ennemy->getLifePoints() == 0)
        ennemy->setOut(1);
      printf("BOOOOOOOOOUM!!!!!!!!!!!!!!");
      n_obj = std::make_shared<object> (sprite_manager, TYPE::EXPLOSION);
      //n_obj = new object(sprite_manager, TYPE::EXPLOSION);
      n_obj->getDrawable().setPosition(ennemy->getDrawable().getPosition().x, ennemy->getDrawable().getPosition().y);
      //objs.push_back(n_obj);
      objs.push_back(std::move(n_obj));
      //FUTURE IMPLEMENTATION DES OBJETS !
      /*n_obj = new object(TYPE::SHIELD);
      n_obj->setPosition(ennemy->getPosition().x - 75, ennemy->getPosition().y);
      objs.push_back(n_obj);*/
      //printf("here player position x %f, and position y %f\n", position_p.x, position_p.y);
    }

}

void  physiqueManager::checkBorderCollision(std::shared_ptr<element> player, view &v)
{
  std::array<float, 4>  pos;

  pos = player->getPositionVector();

  if (player->getLimitedLeft() == true)
    {
      if (pos[0] - v.getLeftSidePos() < 50)
        player->setOut(1);
      else if (pos[1] - v.getUpSidePos() < 100)
        player->setOut(1);
      else if (pos[1] > v.getDownSidePos() - 100)
        player->setOut(1);
    }
  if (player->getLimitedRight() == true)
    {
      if (pos[0] > v.getRightSidePos() - 50)
        player->setOut(1);
      else if (pos[1] - v.getUpSidePos() < 100)
        player->setOut(1);
      else if (pos[1] > v.getDownSidePos() - 100)
        player->setOut(1);
  }
}

std::vector<std::shared_ptr<object>>  physiqueManager::fireOrder(std::shared_ptr<ship> ship, DIRECTION direction, bool boss)
{
  if (boss == false)
    return (ship->fireing(direction));
  else
    return (ship->fireingRadial(direction));
}

void    physiqueManager::TileTheMap(int xSizeWindow, int xSizeBackground, std::array<int, 3> &arr)
{
  int ref;
  int count;

  count = 0;
  ref = xSizeWindow / 2;
  arr[2] = 0;
  if ((2 * ref) >= xSizeBackground)
    {
      arr[0] = -1;
      arr[1] = -1;
    }
  while (xSizeBackground >= ref)
    {
      xSizeBackground = xSizeBackground - ref;
      count = count + 1;
    }
  arr[0] = ref;
  arr[1] = count;
}

//Clairement des choses a revoir sur cette fonction !
void            physiqueManager::generateEnnemys(int posSide, std::array<int, 3> &arr, std::vector<std::shared_ptr<ship>> &ships, int xSizeBackground, int xSizeWindow, std::shared_ptr<handlerSprite> sprite_manager)
{
  int           count;
  float         stock;
  std::vector<std::shared_ptr<ship>>::iterator it;
  std::shared_ptr<ship> n_ship;
  bool          boss;

  if (posSide + (X_SIZE_WINDOW / 2) < xSizeBackground - xSizeWindow)
    {
      count = 0;
      stock = 0;
      while (posSide >= stock)
        {
          count = count + 1;
          stock = (X_SIZE_WINDOW / 2) * count;
        }
      if (count != arr[2])
        {
          this->createWaveEnnemys(posSide, arr, ships, sprite_manager);
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
          n_ship = std::make_shared<ennemy> (sprite_manager, 3, STRATEGY::BOSS, 155, 166);
          ships.push_back(std::move(n_ship));
          //ships.push_back(new ennemy(sprite_manager, 3, STRATEGY::BOSS, 155, 166));
          it = ships.end() - 1;
          (*it)->setLifePoints(5);
          (*it)->promote();
          //(*it)->setImortal(true);
          (*it)->getDrawable().setPosition(xSizeBackground - 155, 250);//+155 = largeur de l'ennemi
          (*it)->getDrawable().setRotation(90);
        }
    }
}

void            physiqueManager::createWaveEnnemys(int posSide, std::array<int, 3> &arr, std::vector<std::shared_ptr<ship>> &ships, std::shared_ptr<handlerSprite> sprite_manager)
{
  std::vector<std::shared_ptr<ship>>::iterator it;
  std::shared_ptr<ship>         n_ship;
  int                           random_nb;
  int                           tmp;

  srand(time(NULL));
  random_nb = (rand() % 8) + 1;

  tmp = random_nb;
  while (tmp != 0)
    {
      n_ship = std::make_shared<ennemy> (sprite_manager);
      ships.push_back(std::move(n_ship));
      //ships.push_back(new ennemy(sprite_manager));
      tmp = tmp - 1;
    }
  it = ships.end() - 1;
  if (random_nb == 1)
    (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,250);
  else if (random_nb == 2)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,175);
      it = ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,325);
    }
  else if (random_nb == 3)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,425);
      it = ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 4) ,225);
    }
  else if (random_nb == 4)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,400);
      it = ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 4) ,225);
      it = ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 3) ,525);
    }
  else if (random_nb == 5)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,425);
      it = ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.9) , 150);
      it = ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,525);
      it = ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,250);
    }
  else if (random_nb == 6)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,425);
      it = ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) ,225);
      it = ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,100);
      it = ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.15) ,400);
      it = ships.end() - 6;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,200);
    }
  else if (random_nb == 7)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 50);
      it = ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 550);
      it = ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) , 150);
      it = ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) , 450);
      it = ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) , 275);
      it = ships.end() - 6;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) , 375);
      it = ships.end() - 7;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.15) , 325);
    }
  else if (random_nb == 8)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 250);
      it = ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 450);
      it = ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) , 525);
      it = ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2.5) , 150);
      it = ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.85) , 475);
      it = ships.end() - 6;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.65) , 375);
      it = ships.end() - 7;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.45) , 275);
      it = ships.end() - 8;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.25) , 100);
    }
}
