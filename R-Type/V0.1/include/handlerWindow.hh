#ifndef HANDLERWINDOW_HH_
# define HANDLERWINDOW_HH_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "handlerSprite.hh"

using namespace std;

class handlerWindow
{

  sf::RenderWindow  window;
  int               x;
  int               y;
  std::string       title;

public:
  handlerWindow();
  handlerWindow(int, int, string);
  handlerWindow(string);
  ~handlerWindow();

  bool windowIsOpen();
  bool windowIsEvent(sf::Event &);

  void windowClear(sf::Color );
  void windowDraw(sf::Sprite &);
  void windowDraw(handlerSprite &);
  void windowDisplay();

  void setXSize(int);
  void setYSize(int);

  sf::RenderWindow&  getWindow();
};

#endif
