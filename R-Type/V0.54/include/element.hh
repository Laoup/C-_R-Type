#ifndef ELEMENT_HH_
# define ELEMENT_HH_

#include <SFML/Graphics.hpp>
#include <memory>
#include "handlerSprite.hh"
#include "drawableClass.hh"
//#include "factory.hh"

enum class STRATEGY {DEFAULT, BOSS};

class element
{
  //float x;
  //float y;
protected:

  //handlerSprite handler_sprite;

  std::shared_ptr<handlerSprite> sprite_manager;
  //handlerSprite *sprite_manager;

  int           out;
  int           life_points;
  bool          solid;
  //bool          limited;
  bool          limitedRight;
  bool          limitedLeft;

  /*sf::VertexArray vertex_array;
  sf::Texture     *texture;*/
  //sf::transform   transform;
  drawableClass  drawable;


  int             width;
  int             height;

public:
  element();
  element(std::shared_ptr<handlerSprite>);
  virtual ~element();

  void setOut(int);
  int  getOut();

  virtual std::array<float, 4> getPositionVector();
  //sf::Vector2f  getPosition();

  int getWidth();
  int getHeight();

  bool  getSolid();
  bool  getLimitedLeft();
  bool  getLimitedRight();

  void  setLifePoints(int);
  int   getLifePoints();
  void  takeDamage();

  drawableClass&  getDrawable();

/*private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;*/
};

#endif
