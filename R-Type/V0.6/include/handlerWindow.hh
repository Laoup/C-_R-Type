#ifndef HANDLERWINDOW_HH_
# define HANDLERWINDOW_HH_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "config.hh"
#include "handlerSprite.hh"
#include "element.hh"

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
  void windowDraw(element *);
  void windowDraw(drawableClass &);
  void windowDrawMenu(drawableClass &);
  void windowDraw(sf::Text &);
  void windowDisplay();

  void setView(sf::View &);
  void setXSize(int);
  void setYSize(int);

  sf::RenderWindow&  getWindow();
  sf::View           getDefaultView();
};

#endif
