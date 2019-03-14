#include "../include/ennemy.hh"

/*
OLD
ennemy::ennemy()
{
  this->handler_sprite.makeVertexSprite("./ressources/simpleEnnemy.png", 127, 45, 0, 0);
  this->move_strat = STRATEGY::DEFAULT;
  this->limitedLeft = true;
}
*/

ennemy::ennemy()
{
  //this->sprite_manager->makeMyVertexArray(this->vertex_array, 127, 45, 0, 0);
  //this->texture = this->sprite_manager->getTexture(2);
  this->move_strat = STRATEGY::DEFAULT;
  this->limitedLeft = true;
}

ennemy::ennemy(handlerSprite *sprite_manager) : ship(sprite_manager)
{
  this->sprite_manager->makeMyVertexArray(this->vertex_array, 127, 45, 0, 0);
  this->texture = this->sprite_manager->getTexture(2);
  this->width = 127;
  this->height = 45;
  this->move_strat = STRATEGY::DEFAULT;
  this->limitedLeft = true;
}

/*
OLD
ennemy::ennemy(std::string str, int x, int y)
{
  this->handler_sprite.makeVertexSprite(str, x, y, 0, 0);
  this->move_strat = STRATEGY::DEFAULT;
  this->limitedLeft = true;
}

ennemy::ennemy(std::string str, STRATEGY strat, int x, int y)
{
  this->handler_sprite.makeVertexSprite(str, x, y, 0, 0);
  this->move_strat = strat;
  this->limitedLeft = true;
}*/

ennemy::ennemy(handlerSprite *sprite_manager, int textureIdentificator, STRATEGY strat, int x, int y) : ship(sprite_manager)
{
  //this->handler_sprite.makeVertexSprite(str, x, y, 0, 0);
  this->sprite_manager->makeMyVertexArray(this->vertex_array, x, y, 0, 0);
  this->texture = this->sprite_manager->getTexture(textureIdentificator);
  this->width = x;
  this->height = y;
  this->move_strat = strat;
  this->limitedLeft = true;
}

ennemy::~ennemy()
{
  printf("One Ennemy is deleted !\n");
}

void  ennemy::getTexture(std::string& str)
{
  this->handler_sprite.makeVertexSprite(str);
}

STRATEGY  ennemy::getStrategy()
{
  return (this->move_strat);
}
