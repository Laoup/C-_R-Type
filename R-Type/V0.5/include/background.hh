#ifndef BACKGROUND_HH_
# define BACKGROUND_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"

class background
{

  /*
  OLD
  handlerSprite handler_sprite;
  */

  //NEW 0.44
  handlerSprite *sprite_manager;
  sf::Sprite    sprite;

public:
  background();
  /*
  OLD
  background(std::string);
  */
  background(handlerSprite *);
  ~background();

  void  defineSize(int, int);
  sf::Sprite&  returnSprite();
};

#endif
