#include "../include/handlerSprite.hh"

handlerSprite::handlerSprite()
{
}

handlerSprite::~handlerSprite()
{
}

bool  handlerSprite::makeSprite(std::string path)
{
  if (this->texture.loadFromFile(path) == false)
    {
      std::cerr << "Impossible de charger la texture demandée" << std::endl;
      return (false);
    }
  this->sprite.setTexture(this->texture);
}

sf::Sprite&  handlerSprite::getSprite()
{
  return (this->sprite);
}
