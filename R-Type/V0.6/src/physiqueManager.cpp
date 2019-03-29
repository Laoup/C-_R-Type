#include "../include/element.hh"
#include "../include/ennemy.hh"
#include "../include/physiqueManager.hh"

physiqueManager::physiqueManager()
{

}

physiqueManager::~physiqueManager()
{

}

void  physiqueManager::moveUp(std::shared_ptr<element> elem, double speed)
{
  elem->getDrawable().move(0, (-1 * speed));
}

void  physiqueManager::moveDown(std::shared_ptr<element> elem, double speed)
{
  elem->getDrawable().move(0, speed);
}

void  physiqueManager::moveLeft(std::shared_ptr<element> elem, double speed)
{
  elem->getDrawable().move((speed * -1), 0);
}

void  physiqueManager::moveRight(std::shared_ptr<element> elem, double speed)
{
  elem->getDrawable().move(speed, 0);
}

void  physiqueManager::createPlayerShip(std::shared_ptr<handlerSprite> sprite_manager)
{
  std::shared_ptr<player> player_ship;

  player_ship = std::make_shared<player> (sprite_manager);
  this->ships.push_back(std::move(player_ship));
  this->ships[0]->getDrawable().setPosition(150,250);
}

void  physiqueManager::applyPlayerTurn(int count, bool endMap)
{
  std::vector<std::shared_ptr<object>>  v_obj;

  /*if (key_map[KEY::UP] == STATE::PRESSED)
    this->ships[0]->getDrawable().move(0, -1 * SPEED);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->ships[0]->getDrawable().move(0, SPEED);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->ships[0]->getDrawable().move((SPEED * -1.15), 0);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->ships[0]->getDrawable().move((SPEED * 1.5), 0);*/

  if (key_map[KEY::UP] == STATE::PRESSED)
    {
      if (key_map[KEY::LEFT] == STATE::NOTPRESS && endMap == true)
        this->moveRight(this->ships[0], SPEED * 0.5);
      this->moveUp(this->ships[0]);
    }
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    {
      if (key_map[KEY::LEFT] == STATE::NOTPRESS && endMap == true)
        this->moveRight(this->ships[0], SPEED * 0.5);
      this->moveDown(this->ships[0]);
    }
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->moveLeft(this->ships[0], SPEED * 1.15);
  if (key_map[KEY::RIGHT] == STATE::PRESSED || key_map[KEY::RIGHT] == STATE::NOTPRESS && key_map[KEY::LEFT] == STATE::NOTPRESS
  && key_map[KEY::UP] == STATE::NOTPRESS && key_map[KEY::DOWN] == STATE::NOTPRESS && endMap == true)
    this->moveRight(this->ships[0], SPEED * 1.5);
  if (count == 2000)
    {
      v_obj = this->fireOrder(this->ships[0], DIRECTION::RIGHT, this->ships[0]->getBoss());
      while (v_obj.size() != 0)
        {
          this->objects.push_back(std::move(v_obj[0]));
          v_obj.erase(v_obj.begin());
        }
      //count = 0;
    }
}

void  physiqueManager::applyEnnemyTurn(int count, std::shared_ptr<handlerSprite> sprite_manager)
{
  std::vector<std::shared_ptr<object>>  v_obj;
  int i;

  if (this->ships.size() > 1)
    {
      i = 1;
      while (i != this->ships.size())
        {
          this->moveEnnemy(this->ships[i]);
          if (count == 2000)
            {
              v_obj = this->fireOrder(this->ships[i], DIRECTION::LEFT, this->ships[i]->getBoss());
              while (v_obj.size() != 0)
                {
                  this->objects.push_back(std::move(v_obj[0]));
                  v_obj.erase(v_obj.begin());
                }
              //count = 0;
            }
          this->checkCollision(this->ships[0], this->ships[i], sprite_manager);
          i++;
        }
    }
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

void  physiqueManager::moveObjectVector()
{
  DIRECTION direct;
  int       i;

  i = 0;
  while (i != this->objects.size())
    {
      direct = this->objects[i]->getDirection();
      if (direct == DIRECTION::LEFT)
        this->objects[i]->getDrawable().move(-1 * (SPEED * 3), 0);
      else if (direct == DIRECTION::RIGHT)
        this->objects[i]->getDrawable().move(SPEED * 3, 0);
      else if (direct == DIRECTION::LEFTINF)
        this->objects[i]->getDrawable().move(-1 * (SPEED * 3), SPEED * 3);
      else if (direct == DIRECTION::LEFTSUP)
        this->objects[i]->getDrawable().move(-1 * (SPEED * 3), -1 * (SPEED * 3));
      else if (direct == DIRECTION::RIGHTINF)
        this->objects[i]->getDrawable().move(SPEED * 3, SPEED * 3);
      else if (direct == DIRECTION::RIGHTSUP)
        this->objects[i]->getDrawable().move(SPEED * 3, -1 * (SPEED * 3));
      i++;
    }
}

void  physiqueManager::applyObjectsCollision(bool endMap, std::shared_ptr<handlerSprite> sprite_manager)
{
  int i;
  int i2;

  i2 = 0;
  while (i2 != this->objects.size())
    {
      i = 0;
      while (i != this->ships.size())
        {
          if (this->ships[i]->getBoss() == true && endMap == true || this->ships[i]->getBoss() == false)
            this->checkCollision(this->objects[i2], this->ships[i], sprite_manager);
          this->checkCollision(this->objects[i2], this->ships[0], sprite_manager);
          i++;
        }
      i2++;
    }
}

void  physiqueManager::applyBordersCollision(view &handler_view)
{
  int i;

  i = 0;
  while (i != this->ships.size())
    {
      this->checkBorderCollision(this->ships[i], handler_view);
      i++;
    }
  i = 0;
  while (i != this->objects.size())
    {
      this->checkBorderCollision(this->objects[i], handler_view);
      i++;
    }
}

void  physiqueManager::checkCollision(std::shared_ptr<element> player, std::shared_ptr<element> ennemy, std::shared_ptr<handlerSprite> sprite_manager)
{
  std::array<float, 4> position_p;
  std::array<float, 4> position_e;
  std::shared_ptr<object> n_obj;

  position_p = player->getPositionVector();
  position_e = ennemy->getPositionVector();

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
      n_obj->getDrawable().setPosition(ennemy->getDrawable().getPosition().x, ennemy->getDrawable().getPosition().y);
      this->objects.push_back(std::move(n_obj));
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
      //ERROR ?
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
void            physiqueManager::generateEnnemys(int posSide, std::array<int, 3> &arr, int xSizeBackground, std::shared_ptr<handlerSprite> sprite_manager)
{
  int           count;
  float         stock;
  std::vector<std::shared_ptr<ship>>::iterator it;
  std::shared_ptr<ship> n_ship;
  bool          boss;

  if (posSide + (X_SIZE_WINDOW / 5) < xSizeBackground - X_SIZE_WINDOW)
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
          this->createWaveEnnemys(posSide, arr, sprite_manager);
          arr[2] = count;
        }
    }
  else
    {
      boss = false;
      it = this->ships.begin();
      while (it != this->ships.end())
        {
          if ((*it)->getBoss() == true)
            boss = true;
          it++;
        }
      if (boss == false)
        {
          n_ship = std::make_shared<ennemy> (sprite_manager, 3, STRATEGY::BOSS, 155, 166);
          this->ships.push_back(std::move(n_ship));
          it = this->ships.end() - 1;
          (*it)->setLifePoints(5);
          (*it)->promote();
          //(*it)->setImortal(true);
          (*it)->getDrawable().setPosition(xSizeBackground - 155, 250);//+155 = largeur de l'ennemi
          (*it)->getDrawable().setRotation(90);
        }
    }
}

void            physiqueManager::createWaveEnnemys(int posSide, std::array<int, 3> &arr, std::shared_ptr<handlerSprite> sprite_manager)
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
      this->ships.push_back(std::move(n_ship));
      //ships.push_back(new ennemy(sprite_manager));
      tmp = tmp - 1;
    }
  it = this->ships.end() - 1;
  if (random_nb == 1)
    (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,250);
  else if (random_nb == 2)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,175);
      it = this->ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,325);
    }
  else if (random_nb == 3)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = this->ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,425);
      it = this->ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 4) ,225);
    }
  else if (random_nb == 4)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = this->ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,400);
      it = this->ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 4) ,225);
      it = this->ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 3) ,525);
    }
  else if (random_nb == 5)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = this->ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,425);
      it = this->ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.9) , 150);
      it = this->ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,525);
      it = this->ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,250);
    }
  else if (random_nb == 6)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,125);
      it = this->ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) ,425);
      it = this->ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) ,225);
      it = this->ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,100);
      it = this->ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.15) ,400);
      it = this->ships.end() - 6;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) ,200);
    }
  else if (random_nb == 7)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 50);
      it = this->ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 550);
      it = this->ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) , 150);
      it = this->ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) , 450);
      it = this->ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) , 275);
      it = this->ships.end() - 6;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.75) , 375);
      it = this->ships.end() - 7;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.15) , 325);
    }
  else if (random_nb == 8)
    {
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 250);
      it = this->ships.end() - 2;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 6) , 450);
      it = this->ships.end() - 3;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2) , 525);
      it = this->ships.end() - 4;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 2.5) , 150);
      it = this->ships.end() - 5;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.85) , 475);
      it = this->ships.end() - 6;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.65) , 375);
      it = this->ships.end() - 7;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.45) , 275);
      it = this->ships.end() - 8;
      (*it)->getDrawable().setPosition(posSide + (arr[0] / 0.25) , 100);
    }
}

void  physiqueManager::setKeyMap(std::map<KEY, STATE>  &key_map)
{
  this->key_map = key_map;
}

void  physiqueManager::returnVertexVectorMovableObject(std::vector<drawableClass>& vec)
{
  int     i;
  //std::vector<element *>::iterator  it;

  i = 0;
  while (i != this->ships.size())
    {
      vec.push_back(this->ships[i]->getDrawable());
      i++;
    }
  i = 0;
  while (i != this->objects.size())
    {
      vec.push_back(this->objects[i]->getDrawable());
      i++;
    }
}

int  physiqueManager::deleteDeadElems()
{
  int i;

  i = 0;
  if (this->ships[0]->getOut() == 1)
    {
      //FIN DE LA PARTIE BIEN TOUT LIBERER !
      while (this->objects.size() != 0)
        {
          this->objects.erase(this->objects.begin());
        }
      while (this->ships.size() != 0)
        {
          this->ships.erase(this->ships.begin());
        }
      return (0);
    }
  while (i < this->ships.size())
    {
      if (this->ships[i]->getBoss() == true && this->ships[i]->getOut() == 1)
        {
          while (this->objects.size() != 0)
            {
              this->objects.erase(this->objects.begin());
            }
          while (this->ships.size() != 0)
            {
              this->ships.erase(this->ships.begin());
            }
          return (0);
        }
      i++;
    }
  i = 0;
  while (i < this->ships.size())
    {
      if (this->ships[i]->getOut() == 1)
        {
          this->ships.erase(this->ships.begin() + i);
        }
      else
        i++;
    }
  i = 0;
  while (i < this->objects.size())
    {
      if (this->objects[i]->getOut() == 1)
        {
          this->objects.erase(this->objects.begin() + i);
        }
      else
        i++;
    }
  return (1);
}
