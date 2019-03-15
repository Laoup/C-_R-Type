#ifndef BACKGROUND_HH_
# define BACKGROUND_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"

class background
{

  handlerSprite *sprite_manager;
  sf::Sprite    sprite;

public:
  background();
  background(handlerSprite *);
  ~background();

  void  defineSize(int, int);
  sf::Sprite&  returnSprite();
};

#endif
