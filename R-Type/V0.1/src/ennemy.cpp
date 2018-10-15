#include "../include/ennemy.hh"

ennemy::ennemy()
{
  this->handler_sprite.makeVertexSprite("./ressources/guardious.png");
}

ennemy::~ennemy()
{
}

void  ennemy::getTexture(std::string& str)
{
  this->handler_sprite.makeVertexSprite(str);
}
