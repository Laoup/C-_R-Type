#include "../include/ennemy.hh"

ennemy::ennemy()
{
  this->handler_sprite.makeVertexSprite("./ressources/simpleEnnemy.png", 130, 50);
  this->move_strat = STRATEGY::DEFAULT;
}

ennemy::~ennemy()
{
}

void  ennemy::getTexture(std::string& str)
{
  this->handler_sprite.makeVertexSprite(str);
}

STRATEGY  ennemy::getStrategy()
{
  return (this->move_strat);
}
