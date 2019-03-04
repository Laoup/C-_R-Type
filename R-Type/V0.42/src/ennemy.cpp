#include "../include/ennemy.hh"

ennemy::ennemy()
{
  this->handler_sprite.makeVertexSprite("./ressources/simpleEnnemy.png", 127, 45, 0, 0);
  this->move_strat = STRATEGY::DEFAULT;
}

ennemy::ennemy(std::string str, int x, int y)
{
  this->handler_sprite.makeVertexSprite(str, x, y, 0, 0);
  this->move_strat = STRATEGY::DEFAULT;
}

ennemy::ennemy(std::string str, STRATEGY strat, int x, int y)
{
  this->handler_sprite.makeVertexSprite(str, x, y, 0, 0);
  this->move_strat = strat;
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
