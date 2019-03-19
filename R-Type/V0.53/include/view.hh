#ifndef VIEW_HH_
# define VIEW_HH_

#include <array>
#include <memory>
#include <SFML/Graphics.hpp>
#include "background.hh"

class view
{
  //background  *my_background;
  std::shared_ptr<background> my_background;
  sf::View    my_view;

  int         xSizeWindow;
  int         ySizeWindow;
  int         xSizeBackground;
  int         ySizeBackground;


public:
  view();
  ~view();

  void  move(float, float);

  void  setView(sf::View);
  void  setWindowSize(int, int);
  void  defineBackground(std::shared_ptr<handlerSprite>, int, int);

  sf::View&     getView();
  sf::Sprite&   getBackground();
  int           getXSizeBackground();
  int           getXSizeWindow();
  sf::Vector2f  getCenterPos();
  int           getRightSidePos();
  int           getLeftSidePos();
  int           getUpSidePos();
  int           getDownSidePos();

  /*view& operator=(const view &);*/
};

#endif
