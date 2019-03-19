#include "ship.hh"

ship::ship()
{
  this->boss = false;
  this->memorie = false;
  //this->immortal = false;
}

ship::ship(std::shared_ptr<handlerSprite> sprite_manager) : element(sprite_manager)
{
  this->boss = false;
  this->memorie = false;
  //this->immortal = false;
}

ship::~ship()
{
}

STRATEGY ship::getStrategy()
{

}

/*object*  ship::fireing(DIRECTION direction)
{
  object  *obj;
  sf::Vector2f pos;

  obj = new object(this->sprite_manager, TYPE::ATTACK, direction);
  pos = this->getDrawable().getPosition();
  if (direction == DIRECTION::RIGHT)
    obj->getDrawable().setPosition(pos.x + (this->getWidth() * 1.25), pos.y + 25);//+25 pour équilibrer l'origine des tirs du vaisseau player
  else if (direction == DIRECTION::LEFT)
    obj->getDrawable().setPosition(pos.x - (this->getWidth() * 1.5), pos.y);
  //this->fire_list.push_back(obj);
  return (obj);
}*/

/*object*  ship::fireing(DIRECTION direction)
{
  object  *obj;
  sf::Vector2f pos;

  obj = new object(this->sprite_manager, TYPE::ATTACK, direction);
  pos = this->getDrawable().getPosition();
  if (direction == DIRECTION::RIGHT)
    obj->getDrawable().setPosition(pos.x + (this->getWidth() - 10), pos.y + 25);//+25 pour équilibrer l'origine des tirs du vaisseau player
  else if (direction == DIRECTION::LEFT)
    obj->getDrawable().setPosition(pos.x - (this->getWidth()), pos.y);
  //this->fire_list.push_back(obj);
  return (obj);
}*/

std::shared_ptr<object>  ship::fireing(DIRECTION direction)
{
  std::shared_ptr<object> obj;
  sf::Vector2f pos;

  obj = std::make_shared<object> (this->sprite_manager, TYPE::ATTACK, direction);
  pos = this->getDrawable().getPosition();
  if (direction == DIRECTION::RIGHT)
    obj->getDrawable().setPosition(pos.x + (this->getWidth() - 10), pos.y + 25);//+25 pour équilibrer l'origine des tirs du vaisseau player
  else if (direction == DIRECTION::LEFT)
    obj->getDrawable().setPosition(pos.x - (this->getWidth()), pos.y);
  //this->fire_list.push_back(obj);
  return (obj);
}

std::vector<object *> ship::getFireList()
{
  printf("fire list size = %d\n", this->fire_list.size());
  return (fire_list);
}

void                  ship::promote()
{
  this->boss = true;
}

bool                  ship::getBoss()
{
  return (this->boss);
}

void                  ship::setMemorie(bool val)
{
  this->memorie = val;
}

bool                  ship::getMemorie()
{
  return (this->memorie);
}

/*sf::Vector2f  ship::getPosition()
{
  return (this->element::getPosition());
}*/
