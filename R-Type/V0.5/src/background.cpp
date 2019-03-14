#include "background.hh"

background::background()
{

}

/*
OLD
background::background(std::string str)
{
  this->handler_sprite.makeSprite(str);
}
*/

background::background(handlerSprite *sprite_manager)
{
  this->sprite_manager = sprite_manager;
  this->sprite_manager->texturizeMySprite(this->sprite, 0);
}

background::~background()
{
  //delete this->sprite_manager;
}

/*
OLD
void  background::defineSize(int x, int y)
{
  this->handler_sprite.defineRectSprite(x, y);
}
*/

void  background::defineSize(int x, int y)
{
  this->sprite.setTextureRect({0, 0, x, y});
}

/*
OLD
sf::Sprite&  background::returnSprite()
{
  return (this->handler_sprite.getSprite());
}
*/

sf::Sprite&  background::returnSprite()
{
  return (this->sprite);
}
