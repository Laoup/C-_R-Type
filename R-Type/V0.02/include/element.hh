#ifndef ELEMENT_HH_
# define ELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"

class element : public sf::Transformable
{
  //float x;
  //float y;
  handlerSprite handler_sprite;

public:
  element();
  ~element();

  void setPosition(float, float);

  void moveX(float);
  void moveY(float);

  float getX();
  float getY();

  sf::Sprite&  returnSprite();
};

#endif
