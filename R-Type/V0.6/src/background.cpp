#include "background.hh"

background::background()
{
  printf("constructor of background\n");
}


background::background(std::shared_ptr<handlerSprite> sprite_manager)
{
  printf("constructor of background\n");
  this->sprite_manager = sprite_manager;
  this->sprite_manager->texturizeMySprite(this->sprite, 0);
}

background::~background()
{
  printf("destructor of background\n");
  //delete this->sprite_manager;
}

void  background::defineSize(int x, int y)
{
  this->sprite.setTextureRect({0, 0, x, y});
}

sf::Sprite&  background::returnSprite()
{
  return (this->sprite);
}
