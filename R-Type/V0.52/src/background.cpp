#include "background.hh"

background::background()
{

}


background::background(handlerSprite *sprite_manager)
{
  this->sprite_manager = sprite_manager;
  this->sprite_manager->texturizeMySprite(this->sprite, 0);
}

background::~background()
{
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
