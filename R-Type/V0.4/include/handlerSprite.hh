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

  int   x;
  int   y;
  int   height;
  int   width;

  float origin_x;
  float origin_y;

public:
  handlerSprite();
  ~handlerSprite();

  bool makeSprite(std::string);
  //bool makeSpriteR(std::string);
  //bool makeVertexSprite(std::string, int = 200, int = 150, int = 125,int = 80,int = 140,int = 80, int = 0,int = 0);
  bool makeVertexSprite(std::string, int = 140, int = 80, int = 0, int = 0);

  //void repeatTexture();
  void  defineRectSprite(int, int);

  sf::Sprite&  getSprite();
  int getX();
  int getY();
  int getWidth();
  int getHeight();
  //sf::Vector2f  getPosition();
  std::array<float, 4>  getWidthHeight();

private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;

  void  defineOrigin(int, int);
};

#endif
