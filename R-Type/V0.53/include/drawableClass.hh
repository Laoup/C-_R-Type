#ifndef DRAWABLECLASS_HH_
# define DRAWABLECLASS_HH_

#include <SFML/Graphics.hpp>

class drawableClass : public sf::Drawable, public sf::Transformable
{
  sf::VertexArray vertex_array;
  sf::Texture     *texture;

public:

  drawableClass();
  ~drawableClass();

  sf::VertexArray &getVertexArray();
  void            setTexture(sf::Texture *);

private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;
};

#endif
