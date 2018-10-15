#ifndef HANDLERSPRITE_HH_
# define HANDLERSPRITE_HH_

#include <SFML/Graphics.hpp>
#include <iostream>

class handlerSprite
{

  sf::Sprite  sprite;
  sf::Texture texture;

public:
  handlerSprite();
  ~handlerSprite();

  bool makeSprite(std::string);

  sf::Sprite&  getSprite();
};

#endif
