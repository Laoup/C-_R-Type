#ifndef BACKGROUND_HH_
# define BACKGROUND_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"

class background
{

  handlerSprite handler_sprite;

public:
  background();
  background(std::string);
  ~background();

  void  defineSize(int, int);
  sf::Sprite&  returnSprite();
};

#endif
