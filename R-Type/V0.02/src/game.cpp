#include "../include/game.hh"

#include <iostream> //debugg

game::game()
{
}

game::~game()
{
}

void  game::setKeyMap(std::map<KEY, STATE>  &key_map)
{
  this->key_map = key_map;
}

void  game::initializeTheGame()
{
  player.setPosition(400, 300);
  /*player.setX(0);
  player.setY(0);*/
}

void  game::applyTurn()
{
  //std::cout << player.getPosition().x << std::endl;
  if (key_map[KEY::UP] == STATE::PRESSED)
    this->m_physique.moveUP(this->player);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->m_physique.moveDOWN(this->player);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->m_physique.moveLEFT(this->player);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->m_physique.moveRIGHT(this->player);
  //std::cout << player.getPosition().x << std::endl;
}

sf::Sprite&  game::returnSpritePlayer()
{
  return(this->player.returnSprite());
}
