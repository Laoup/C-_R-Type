#ifndef DRAWABLECLASS_HH_
# define DRAWABLECLASS_HH_

#include <SFML/Graphics.hpp>
#include <map>

class drawableClass : public sf::Drawable, public sf::Transformable
{
  sf::VertexArray vertex_array;

  sf::Texture     *textureRef;

  sf::Sprite      sprite;

  std::map<std::string, sf::Text> map_text;
  sf::Font                        font;

public:

  drawableClass();
  ~drawableClass();

  sf::VertexArray &getVertexArray();
  void            setTextureRef(sf::Texture *);
  void            setSprite(sf::Texture *);
  void            setSpritePosition(float, float);
  bool            setFontText(std::string);
  void            addText(std::string, int = 40);
  void            setTextPosition(std::string, float , float);
  void            setColorText(std::string, sf::Color);

  sf::FloatRect   getBoundsText(std::string);
  sf::Sprite&     getSprite();
  std::map<std::string, sf::Text>&  getMapText();

private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;
};

#endif
