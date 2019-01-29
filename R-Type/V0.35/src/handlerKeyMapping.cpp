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
          std::cout << "Z" << std::endl;
          this->key_map[KEY::UP] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::Q)
        {
          std::cout << "Q" << std::endl;
          this->key_map[KEY::LEFT] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::D)
        {
          std::cout << "D" << std::endl;
          this->key_map[KEY::RIGHT] = STATE::NOTPRESS;
        }
      else if (event.key.code == sf::Keyboard::S)
        {
          std::cout << "S" << std::endl;
          this->key_map[KEY::DOWN] = STATE::NOTPRESS;
        }
    }
  return (this->key_map);
}
