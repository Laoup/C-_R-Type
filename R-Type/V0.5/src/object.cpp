#include "object.hh"

object::object()
{
  this->speed = SPEED;//la même que les vaisseaux.
  this->direction = DIRECTION::LEFT;
  //this->dangerous = true
  //this->limited = true;
}

/*
OLD

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
      this->limitedLeft = true;
    }
  else if (type == TYPE::SHIELD)
    {
      this->speed = SPEED * 3;
      this->handler_sprite.makeVertexSprite("./ressources/", 128, 128, 0, 0);
      this->solid = false;
      this->limitedLeft = true;
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
      this->limitedRight = true;
    }
  this->direction = direction;
  this->type = type;
}
*/

object::object(handlerSprite* sprite_manager, TYPE type) : element(sprite_manager)
{
  //this->dangerous = true
  if (type == TYPE::ATTACK)
    this->speed = SPEED * 3;
  else if (type == TYPE::EXPLOSION)
    {
      this->speed = 0;
      this->sprite_manager->makeMyVertexArray(this->vertex_array, 128, 128, 0, 0);
      this->texture = this->sprite_manager->getTexture(5);
      this->width = 128;
      this->height = 128;
      this->solid = false;
      this->limitedLeft = true;
    }
/*  else if (type == TYPE::SHIELD)
    {
      this->speed = SPEED * 3;
      this->handler_sprite.makeVertexSprite("./ressources/", 128, 128, 0, 0);
      this->solid = false;
      this->limitedLeft = true;
    }
*/
  this->type = type;
  this->direction = DIRECTION::LEFT;
}

object::object(handlerSprite* sprite_manager, TYPE type, DIRECTION direction) : element(sprite_manager)
{
  //this->dangerous = true;
  if (type == TYPE::ATTACK)
    {
      this->speed = SPEED * 3;
      this->sprite_manager->makeMyVertexArray(this->vertex_array, 64, 32, 0, 0);
      this->texture = this->sprite_manager->getTexture(4);
      this->width = 64;
      this->height = 32;
      this->limitedRight = true;
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
