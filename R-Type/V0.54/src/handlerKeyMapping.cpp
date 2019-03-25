#include "../include/handlerKeyMapping.hh"

#include <iostream>

handlerKeyMapping::handlerKeyMapping()
{
  this->key_map[KEY::UP] = STATE::NOTPRESS;
  this->key_map[KEY::DOWN] = STATE::NOTPRESS;
  this->key_map[KEY::LEFT] = STATE::NOTPRESS;
  this->key_map[KEY::RIGHT] = STATE::NOTPRESS;
  this->key_map[KEY::CLOSE] = STATE::NOTPRESS;
}

handlerKeyMapping::~handlerKeyMapping()
{

}

void  handlerKeyMapping::setLastEvent(sf::Event &event)
{
  this->event = event;
}

sf::Event& handlerKeyMapping::getEvent()
{
  return (this->event);
}



std::map<KEY, STATE>  handlerKeyMapping::returnKey()
{
  if (event.type == sf::Event::Closed)
    {
      this->key_map[KEY::CLOSE] = STATE::PRESSED;
    }
  else if (event.type == sf::Event::KeyPressed)
    {
      if (event.key.code == sf::Keyboard::Z)
        {
          //std::cout << "Z" << std::endl;
          this->key_map[KEY::UP] = STATE::PRESSED;
        }
      else if (event.key.code == sf::Keyboard::Q)
        {
          //std::cout << "Q" << std::endl;
          this->key_map[KEY::LEFT] = STATE::PRESSED;
        }
      else if (event.key.code == sf::Keyboard::D)
        {
          //std::cout << "D" << std::endl;
          this->key_map[KEY::RIGHT] = STATE::PRESSED;
        }
      else if (event.key.code == sf::Keyboard::S)
        {
          //std::cout << "S" << std::endl;
          this->key_map[KEY::DOWN] = STATE::PRESSED;
        }
    }
  else if (event.type == sf::Event::KeyReleased)
    {
      if (event.key.code == sf::Keyboard::Z)
        {
          //std::cout << "Z" << std::endl;
          this->key_map[KEY::UP] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::Q)
        {
          //std::cout << "Q" << std::endl;
          this->key_map[KEY::LEFT] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::D)
        {
          //std::cout << "D" << std::endl;
          this->key_map[KEY::RIGHT] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::S)
        {
          //std::cout << "S" << std::endl;
          this->key_map[KEY::DOWN] = STATE::NOTPRESS;
        }
    }
  return (this->key_map);
}

std::map<KEY, STATE>  handlerKeyMapping::returnKey2()
{

  /*this->key_map[KEY::UP] = STATE::NOTPRESS;
  this->key_map[KEY::LEFT] = STATE::NOTPRESS;
  this->key_map[KEY::RIGHT] = STATE::NOTPRESS;
  this->key_map[KEY::DOWN] = STATE::NOTPRESS;*/
  /*if (event.type == sf::Event::MouseMoved)
    {
      std::cout << 'B' << std::endl;
      std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
      std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
    }*/
  if (event.type == sf::Event::KeyReleased)
    {
      if (event.key.code == sf::Keyboard::Z)
        {
          this->key_map[KEY::UP] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::Q)
        {
          this->key_map[KEY::LEFT] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::D)
        {
          this->key_map[KEY::RIGHT] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::S)
        {
          this->key_map[KEY::DOWN] = STATE::NOTPRESS;
        }
    }
  else
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
          //std::cout << "Z" << std::endl;
          this->key_map[KEY::UP] = STATE::PRESSED;
        }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
          //std::cout << "Q" << std::endl;
          this->key_map[KEY::LEFT] = STATE::PRESSED;
        }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
          //std::cout << "D" << std::endl;
          this->key_map[KEY::RIGHT] = STATE::PRESSED;
        }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
          //std::cout << "S" << std::endl;
          this->key_map[KEY::DOWN] = STATE::PRESSED;
        }
    }
  return (this->key_map);
}

sf::Vector2f   handlerKeyMapping::returnMouseClick()
{
  sf::Vector2f  arr;
  /*if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Right)
        {
          std::cout << "the right button was pressed" << std::endl;
          std::cout << "mouse x: " << event.mouseButton.x << std::endl;
          std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        }
    }*/
  arr.x = 0;
  arr.y = 0;
  if (event.type == sf::Event::MouseButtonPressed)
    {
      std::cout << "mouse x: " << event.mouseButton.x << std::endl;
      std::cout << "mouse y: " << event.mouseButton.y << std::endl;
      arr.x = event.mouseButton.x;
      arr.y = event.mouseButton.y;
    }
  return (arr);
}
