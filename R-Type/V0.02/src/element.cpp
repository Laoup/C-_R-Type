#include "../include/element.hh"

element::element()
{
  std::string str = "./ressources/Starfighter.png";

  handler_sprite.makeSprite("./ressources/Starfighter.png");
}

element::~element()
{

}

void  element::setPosition(float valueX, float valueY)
{
  handler_sprite.getSprite().setPosition(valueX, valueY);
}

void  element::moveX(float value)
{
  handler_sprite.getSprite().move(0, value);
}

void  element::moveY(float value)
{
  handler_sprite.getSprite().move(value, 0);
}

float  element::getX()
{
  //return(this->x = value);
}

float  element::getY()
{
  //return(this->y = value);
}

sf::Sprite&  element::returnSprite()
{
  return (this->handler_sprite.getSprite());
}
