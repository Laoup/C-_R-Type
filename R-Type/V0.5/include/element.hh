#ifndef ELEMENT_HH_
# define ELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"

enum class STRATEGY {DEFAULT, BOSS};

class element : public sf::Drawable, public sf::Transformable //A tester l'héritage est peut-etre de trop ici car toutes les fonctions sont gérées par le handler sprite
{
  //float x;
  //float y;
protected:

  handlerSprite handler_sprite;

  //NEW 0.44
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

  /*
  OLD
  virtual void setPosition(float, float);
  virtual sf::Vector2f getPosition();
  virtual void setRotation(int);
  */

  void setOut(int);
  int  getOut();

  virtual void moveX(float);
  virtual void moveY(float);

  virtual void getTexture(std::string &) = 0;
  //virtual STRATEGY  getStrategy();
  //virtual sf::Vector2f getPositionVector();
  virtual std::array<float, 4> getPositionVector();

  /*
  OLD
  int getX();
  int getY();
  */

  int getWidth();
  int getHeight();

  bool  getSolid();
  bool  getLimitedLeft();
  bool  getLimitedRight();

  void  setLifePoints(int);
  int   getLifePoints();
  void  takeDamage();

  virtual sf::Sprite&     returnSprite();
  virtual const handlerSprite   returnVertexSprite();

private:

  virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;
};

#endif
