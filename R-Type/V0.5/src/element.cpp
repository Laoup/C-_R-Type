#include "../include/element.hh"
#include <array>

element::element()
{
  /*std::string str = "./ressources/Starfighter.png";

  //handler_sprite.makeSprite("./ressources/StarFighter/Starfighter.png");
  handler_sprite.makeSprite("./ressources/Guardian/guardious.png");*/
  this->out = 0;
  this->solid = true;
  this->limitedRight = false;
  this->limitedLeft = false;
  this->life_points = 1;
}

element::element(handlerSprite *ptrSpriteManager)
{
  this->sprite_manager = ptrSpriteManager;
  //this->sprite_manager->makeMyVertexArray(this->vertex_array, 140, 80, 0, 0);
  this->out = 0;
  this->solid = true;
  this->limitedRight = false;
  this->limitedLeft = false;
  this->life_points = 1;
}

element::~element()
{

}

/*
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
*/

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

/*
OLD
int  element::getX()
{
  return(this->handler_sprite.getX());
}

int  element::getY()
{
  return(this->handler_sprite.getY());
}*/

int  element::getWidth()
{
  return(this->width);
}

int  element::getHeight()
{
  return(this->height);
}

bool  element::getSolid()
{
  return (this->solid);
}

bool  element::getLimitedLeft()
{
  return (this->limitedLeft);
}

bool  element::getLimitedRight()
{
  return (this->limitedRight);
}

void  element::setLifePoints(int nb)
{
  this->life_points = nb;
}

int   element::getLifePoints()
{
  return (this->life_points);
}

void  element::takeDamage()
{
  this->life_points = this->life_points - 1;
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

/*
OLD
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
*/

std::array<float, 4> element::getPositionVector()
{
  sf::Vector2f vec;
  std::array<float, 4> arr;

  vec = this->getPosition();
  //arr = this->getWidthHeight();
  arr[0] = vec.x;
  arr[1] = vec.y;
  arr[2] = this->width;
  arr[3] = this->height;
  return (arr);
  //return (this->handler_sprite.getPosition());
}

void    element::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
        states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

        // on applique la texture
        //states.texture = &this->texture;
        states.texture = this->texture;

        // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

        // on dessine le tableau de vertex
        target.draw(vertex_array, states);
}
