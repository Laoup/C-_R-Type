#include "../include/element.hh"
#include <array>

element::element()
{
  /*std::string str = "./ressources/Starfighter.png";

  //handler_sprite.makeSprite("./ressources/StarFighter/Starfighter.png");
  handler_sprite.makeSprite("./ressources/Guardian/guardious.png");*/
  this->out = 0;
  this->solid = true;
  this->limited = false;
}

element::~element()
{

}

void  element::setPosition(float valueX, float valueY)
{
  //this->handler_sprite.getSprite().setPosition(valueX, valueY);
  this->handler_sprite.setPosition(valueX, valueY);
}

sf::Vector2f  element::getPosition()
{
  return (this->handler_sprite.getPosition());
}

void  element::setRotation(int val)
{
  this->handler_sprite.setRotation(val);

}

void  element::setOut(int val)
{
  this->out = val;
}

int  element::getOut()
{
  return (this->out);
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

int  element::getX()
{
  return(this->handler_sprite.getX());
}

int  element::getY()
{
  return(this->handler_sprite.getY());
}

bool  element::getSolid()
{
  return (this->solid);
}

bool  element::getLimited()
{
  return (this->limited);
}

sf::Sprite&  element::returnSprite()
{
  return (this->handler_sprite.getSprite());
}

const handlerSprite element::returnVertexSprite()
{
  return (this->handler_sprite);
}

/*STRATEGY element::getStrategy()
{

}*/

/*sf::Vector2f element::getPositionVector()
{
  return (this->handler_sprite.getPosition());
}*/

std::array<float, 4> element::getPositionVector()
{
  sf::Vector2f vec;
  std::array<float, 4> arr;

  vec = this->handler_sprite.getPosition();
  arr = this->handler_sprite.getWidthHeight();
  arr[0] = vec.x;
  arr[1] = vec.y;
  return (arr);
  //return (this->handler_sprite.getPosition());
}
