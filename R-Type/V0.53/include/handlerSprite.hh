#ifndef HANDLERSPRITE_HH_
# define HANDLERSPRITE_HH_

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

class handlerSprite : public sf::Drawable, public sf::Transformable//Seulement utile pour les ecrans titre, possible d'améliorer ça
{

  sf::Sprite  sprite;
  sf::Texture texture;

  sf::VertexArray vertex_array;
  sf::Texture     texture_vertex;

  float origin_x;
  float origin_y;

  std::array<sf::Texture, 6> vectorTextures;

public:
  handlerSprite();
  handlerSprite(std::string);
  ~handlerSprite();

  bool makeSprite(std::string, int = 125, int = 80);
  //bool makeSpriteR(std::string);

  sf::Sprite&  getSprite();

  void  texturize(sf::RenderStates &, int);
  void  texturizeMySprite(sf::Sprite &, int);
  void  makeMyVertexArray(sf::VertexArray &, int, int, int, int);
  sf::Texture  *getTexture(int);

private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;

  void  defineOrigin(int, int);
};

#endif
