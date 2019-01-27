#include "ship.hh"

ship::ship()
{
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
  obj->setPosition(pos.x + (this->getX()/2), pos.y);
  //this->fire_list.push_back(obj);
  return (obj);
}

std::vector<object *> ship::getFireList()
{
  printf("fire list size = %d\n", this->fire_list.size());
  return (fire_list);
}
