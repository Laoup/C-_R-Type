#include "../include/element.hh"

element::element()
{
  /*std::string str = "./ressources/Starfighter.png";

  //handler_sprite.makeSprite("./ressources/StarFighter/Starfighter.png");
  handler_sprite.makeSprite("./ressources/Guardian/guardious.png");*/
}

element::~element()
{

}

void  element::setPosition(float valueX, float valueY)
{
  //this->handler_sprite.getSprite().setPosition(valueX, valueY);
  this->handler_sprite.setPosition(valueX, valueY);
}

void  element::moveX(float value)
{
  //this->handler_sprite.getSprite().move(0, value);
  this->handler_sprite.move(0, value);
}

void  element::moveY(float value)
{
  //this->handler_sprite.getSprite().move(value, 0);
  this->handler_sprite.move(value, 0);
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

handlerSprite& element::returnVertexSprite()
{
  return (this->handler_sprite);
}
