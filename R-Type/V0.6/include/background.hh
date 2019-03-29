#ifndef BACKGROUND_HH_
# define BACKGROUND_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"
#include <memory>

class background
{

  std::shared_ptr<handlerSprite> sprite_manager;
  sf::Sprite    sprite;

public:
  background();
  background(std::shared_ptr<handlerSprite>);
  ~background();

  void  defineSize(int, int);
  sf::Sprite&  returnSprite();
};

#endif
