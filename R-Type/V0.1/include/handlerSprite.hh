#ifndef HANDLERSPRITE_HH_
# define HANDLERSPRITE_HH_

#include <SFML/Graphics.hpp>
#include <iostream>

class handlerSprite : public sf::Drawable, public sf::Transformable
{

  sf::Sprite  sprite;
  sf::Texture texture;

  sf::VertexArray vertex_array;
  sf::Texture     texture_vertex;

public:
  handlerSprite();
  ~handlerSprite();

  bool makeSprite(std::string);
  bool makeVertexSprite(std::string);

  sf::Sprite&  getSprite();

private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;
};

#endif
