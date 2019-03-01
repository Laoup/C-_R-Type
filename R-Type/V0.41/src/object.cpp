#include "object.hh"

object::object()
{
  this->speed = SPEED;//la même que les vaisseaux.
  this->direction = DIRECTION::LEFT;
  //this->dangerous = true
}

object::object(TYPE type)
{
  //this->dangerous = true
  if (type == TYPE::ATTACK)
    this->speed = SPEED * 3;
  else if (type == TYPE::EXPLOSION)
    {
      this->speed = 0;
      this->handler_sprite.makeVertexSprite("./ressources/explosion.png", 128, 128, 0, 0);
      this->solid = false;
    }
  this->type = type;
  this->direction = DIRECTION::LEFT;
}

object::object(TYPE type, DIRECTION direction)
{
  //this->dangerous = true;
  if (type == TYPE::ATTACK)
    {
      printf("YOLLLLOOOOO\n\n\n");
      this->speed = SPEED * 3;
      this->handler_sprite.makeVertexSprite("./ressources/Fireball1.png", 64, 32, 0, 0);
    }
  this->direction = direction;
  this->type = type;
}

object::~object()
{
}

void  object::getTexture(std::string& str)
{
  this->handler_sprite.makeVertexSprite(str);
}

DIRECTION object::getDirection()
{
  return (this->direction);
}
