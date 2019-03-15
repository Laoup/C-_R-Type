#include "../include/element.hh"
#include <array>

element::element()
{
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

void  element::setOut(int val)
{
  this->out = val;
}

int  element::getOut()
{
  return (this->out);
}

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

std::array<float, 4> element::getPositionVector()
{
  sf::Vector2f vec;
  std::array<float, 4> arr;

  vec = this->getPosition();
  arr[0] = vec.x;
  arr[1] = vec.y;
  arr[2] = this->width;
  arr[3] = this->height;
  return (arr);
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
