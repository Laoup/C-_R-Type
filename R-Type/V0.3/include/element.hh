#ifndef ELEMENT_HH_
# define ELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "handlerSprite.hh"

enum class STRATEGY {DEFAULT};

class element : public sf::Transformable //A tester l'héritage est peut-etre de trop ici car toutes les fonctions sont gérées par le handler sprite
{
  //float x;
  //float y;
protected:

  handlerSprite handler_sprite;
  int           out;

public:
  element();
  virtual ~element();

  virtual void setPosition(float, float);
  virtual sf::Vector2f getPosition();

  void setOut(int);
  int  getOut();

  virtual void moveX(float);
  virtual void moveY(float);

  virtual void getTexture(std::string &) = 0;
  //virtual STRATEGY  getStrategy();
  //virtual sf::Vector2f getPositionVector();
  virtual std::array<float, 4> getPositionVector();

  int getX();
  int getY();

  virtual sf::Sprite&     returnSprite();
  virtual const handlerSprite   returnVertexSprite();
};

#endif
