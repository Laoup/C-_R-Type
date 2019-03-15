#ifndef ELEMENT_HH_
# define ELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"

enum class STRATEGY {DEFAULT, BOSS};

class element : public sf::Drawable, public sf::Transformable
{
  //float x;
  //float y;
protected:

  //handlerSprite handler_sprite;

  handlerSprite *sprite_manager;

  int           out;
  int           life_points;
  bool          solid;
  //bool          limited;
  bool          limitedRight;
  bool          limitedLeft;

  sf::VertexArray vertex_array;
  sf::Texture     *texture;

  int             width;
  int             height;

public:
  element();
  element(handlerSprite *);
  virtual ~element();

  void setOut(int);
  int  getOut();

  virtual std::array<float, 4> getPositionVector();

  int getWidth();
  int getHeight();

  bool  getSolid();
  bool  getLimitedLeft();
  bool  getLimitedRight();

  void  setLifePoints(int);
  int   getLifePoints();
  void  takeDamage();

private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;
};

#endif
