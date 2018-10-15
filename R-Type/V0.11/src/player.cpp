#include "../include/player.hh"

player::player()
{
  this->handler_sprite.makeVertexSprite("./ressources/guardious.png");
}

player::~player()
{
}

void  player::getTexture(std::string& str)
{
  this->handler_sprite.makeVertexSprite(str);
}
