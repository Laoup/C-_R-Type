#include "../include/handlerWindow.hh"
#include <SFML/System/String.hpp>

handlerWindow::handlerWindow()
{
  sf::String  str = "";

  this->window.create(sf::VideoMode(X_SIZE_WINDOW, Y_SIZE_WINDOW), "");
  this->x = X_SIZE_WINDOW;
  this->y = Y_SIZE_WINDOW;
  this->title = "";
}

handlerWindow::handlerWindow(const string title)
{
  sf::String  str = title;

  this->window.create(sf::VideoMode(X_SIZE_WINDOW, Y_SIZE_WINDOW), title);
  this->x = X_SIZE_WINDOW;
  this->y = Y_SIZE_WINDOW;
  this->title = title;
}

handlerWindow::handlerWindow(int x, int y, string title)
{
  sf::String  str = title;

  this->window.create(sf::VideoMode(x, y), title);
  this->x = x;
  this->y = y;
  this->title = title;
}

handlerWindow::~handlerWindow()
{
  this->window.close();
}

bool handlerWindow::windowIsOpen()
{
  return (this->window.isOpen());
}

bool handlerWindow::windowIsEvent(sf::Event &event)
{
  return (this->window.pollEvent(event));
}

void handlerWindow::windowClear(sf::Color color)
{
  this->window.clear(color);
}

void handlerWindow::windowDraw(sf::Sprite &sprite)
{
  this->window.draw(sprite);
}

void handlerWindow::windowDraw(handlerSprite &vertex)
{
  this->window.draw(vertex);
}

void handlerWindow::windowDraw(sf::Text &text)
{
  this->window.draw(text);
}

void handlerWindow::windowDisplay()
{
  this->window.display();
}

void handlerWindow::setView(sf::View &view)
{
  this->window.setView(view);
}

void handlerWindow::setXSize(int x)
{
  this->x = x;
  window.setSize(sf::Vector2u(x, this->y));
}

void handlerWindow::setYSize(int y)
{
  this->y = y;
  window.setSize(sf::Vector2u(this->x, y));
}

sf::RenderWindow&  handlerWindow::getWindow()
{
  return (this->window);
}

sf::View           handlerWindow::getDefaultView()
{
  return (this->window.getDefaultView());
}
