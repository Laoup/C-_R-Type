#include "../include/ennemy.hh"

ennemy::ennemy()
{
  this->move_strat = STRATEGY::DEFAULT;
  this->limitedLeft = true;
}

ennemy::ennemy(std::shared_ptr<handlerSprite> sprite_manager) : ship(sprite_manager)
{
  /*this->sprite_manager->makeMyVertexArray(this->vertex_array, 127, 45, 0, 0);
  this->texture = this->sprite_manager->getTexture(2);*/
  this->sprite_manager->makeMyVertexArray(this->getDrawable().getVertexArray(), 127, 45, 0, 0);
  this->getDrawable().setTexture(this->sprite_manager->getTexture(2));
  this->width = 127;
  this->height = 45;
  this->move_strat = STRATEGY::DEFAULT;
  this->limitedLeft = true;
}

ennemy::ennemy(std::shared_ptr<handlerSprite> sprite_manager, int textureIdentificator, STRATEGY strat, int x, int y) : ship(sprite_manager)
{
  /*this->sprite_manager->makeMyVertexArray(this->vertex_array, x, y, 0, 0);
  this->texture = this->sprite_manager->getTexture(textureIdentificator);*/
  this->sprite_manager->makeMyVertexArray(this->getDrawable().getVertexArray(), x, y, 0, 0);
  this->getDrawable().setTexture(this->sprite_manager->getTexture(textureIdentificator));
  this->width = x;
  this->height = y;
  this->move_strat = strat;
  this->limitedLeft = true;
}

ennemy::~ennemy()
{
  printf("One Ennemy is deleted !\n");
}

STRATEGY  ennemy::getStrategy()
{
  return (this->move_strat);
}
