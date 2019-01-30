#include "background.hh"

background::background()
{

}

background::background(std::string str)
{
  this->handler_sprite.makeSprite(str);
}

background::~background()
{

}

void  background::defineSize(int x, int y)
{
  this->handler_sprite.defineRectSprite(x, y);
}

sf::Sprite&  background::returnSprite()
{
  return (this->handler_sprite.getSprite());
}
