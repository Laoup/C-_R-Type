#include "ship.hh"

ship::ship()
{
  this->boss = false;
  this->memorie = false;
  //this->immortal = false;
  this->life_points = 1;
}

ship::~ship()
{
}

void  ship::getTexture(std::string& str)
{
  this->handler_sprite.makeVertexSprite(str);
}

STRATEGY ship::getStrategy()
{

}

object*  ship::fireing(DIRECTION direction)
{
  object  *obj;
  sf::Vector2f pos;

  obj = new object(TYPE::ATTACK, direction);
  pos = this->getPosition();
  printf("getX = %d\n", this->getX());
  //printf("\n\nSir ! My pos x is = %f, And my pos y is = %f\n\n", pos.x, pos.y);
  if (direction == DIRECTION::RIGHT)
    obj->setPosition(pos.x + (this->getX())/1.25, pos.y);
  else if (direction == DIRECTION::LEFT)
    obj->setPosition(pos.x - (this->getX()/1.5), pos.y);
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

void                  ship::setLifePoints(int nb)
{
  this->life_points = nb;
}

void                  ship::setMemorie(bool val)
{
  this->memorie = val;
}

bool                  ship::getMemorie()
{
  return (this->memorie);
}
