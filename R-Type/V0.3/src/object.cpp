#include "object.hh"

object::object()
{
  this->speed = 0.85;//la même que les vaisseaux.
}

object::object(TYPE type)
{
  if (type == TYPE::ATTACK)
    this->speed = 1.7;
  else if (type == TYPE::EXPLOSION)
    {
      this->speed = 0;
      this->handler_sprite.makeVertexSprite("./ressources/explosion.png", 128, 128, 0, 0);
    }
  this->type = type;
}

object::object(TYPE type, DIRECTION direction)
{
  if (type == TYPE::ATTACK)
    {
      printf("YOLLLLOOOOO\n\n\n");
      this->speed = 1.7;
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
