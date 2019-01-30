#ifndef VIEW_HH_
# define VIEW_HH_

#include <array>
#include <SFML/Graphics.hpp>
#include "background.hh"

class view
{
  background  *my_background;
  sf::View    my_view;

  int         xSizeWindow;
  int         ySizeWindow;

public:
  view();
  ~view();

  void  move(float, float);

  void  setView(sf::View);
  void  setWindowSize(int, int);
  void  defineBackground(std::string, int, int);

  sf::View&     getView();
  sf::Sprite&   getBackground();
  sf::Vector2f  getCenterPos();
  float         getLeftSidePos();
  float         getRightSidePos();
  float         getUpSidePos();
  float         getDownSidePos();

  /*view& operator=(const view &);*/
};

#endif
