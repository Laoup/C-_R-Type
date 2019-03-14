#include "../include/player.hh"

/*
OLD

player::player()
{
  this->handler_sprite.makeVertexSprite("./ressources/guardious.png");
  this->limitedLeft = true;
  this->limitedRight = true;
}*/

player::player()
{
  //this->sprite_manager->makeMyVertexArray(this->vertex_array, 140, 80, 0, 0);
  //this->texture = this->sprite_manager->getTexture(1);
  this->limitedLeft = true;
  this->limitedRight = true;
}

player::player(handlerSprite *sprite_manager) : ship(sprite_manager)
{
  this->sprite_manager->makeMyVertexArray(this->vertex_array, 140, 80, 0, 0);
  this->texture = this->sprite_manager->getTexture(1);
  this->width = 140;
  this->height = 80;
  this->limitedLeft = true;
  this->limitedRight = true;
}

player::~player()
{
  printf("One Player is deleted ! \n");
}

void  player::getTexture(std::string& str)
{
  this->handler_sprite.makeVertexSprite(str);
}

STRATEGY player::getStrategy()
{

}
