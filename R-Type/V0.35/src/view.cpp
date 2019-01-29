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

void  view::defineBackground(std::string str, int x, int y)
{
  //this->my_background = new background("./ressources/background2.png");
  this->my_background = new background(str);
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

/*view&   view::operator =(const view &other)
{

}*/
