#include "view.hh"

view::view()
{
}

view::~view()
{

}

void  view::move(float x, float y)
{
  this->my_view.move(x, y);
}

void  view::setView(sf::View val)
{
  this->my_view = val;
}

void  view::setWindowSize(int xSizeWindow, int ySizeWindow)
{
  this->xSizeWindow = xSizeWindow;
  this->ySizeWindow = ySizeWindow;
}

void  view::defineBackground(handlerSprite *sprite_manager, int x, int y)
{
  this->xSizeBackground = x;
  this->ySizeBackground = y;
  this->my_background = new background(sprite_manager);
  this->my_background->defineSize(x, y);//1600, 600
}

sf::View&   view::getView()
{
  return (this->my_view);
}

sf::Sprite&   view::getBackground()
{
  return (this->my_background->returnSprite());
}

int           view::getXSizeBackground()
{
  return (this->xSizeBackground);
}

int           view::getXSizeWindow()
{
  return (this->xSizeWindow);
}

sf::Vector2f  view::getCenterPos()
{
  return (this->my_view.getCenter());
}

int        view::getLeftSidePos()
{
  sf::Vector2f  vec;

  vec = this->getCenterPos();
  return (vec.x - (this->xSizeWindow / 2));
}

int        view::getRightSidePos()
{
  sf::Vector2f  vec;

  vec = this->getCenterPos();
  return (vec.x + (this->xSizeWindow / 2));
}

int        view::getUpSidePos()
{
  sf::Vector2f  vec;

  vec = this->getCenterPos();
  return (vec.y - (this->xSizeWindow / 2));
}

int        view::getDownSidePos()
{
  sf::Vector2f  vec;

  vec = this->getCenterPos();
  return (vec.y + (this->xSizeWindow / 2));
}

/*view&   view::operator =(const view &other)
{

}*/
