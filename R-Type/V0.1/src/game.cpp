#include "../include/game.hh"

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
  this->ships.push_back(new player);
  this->ships[0]->setPosition(50,250);
  this->ships.push_back(new ennemy);
  this->ships[1]->setPosition(500,250);
}

void  game::applyTurn()
{
  if (key_map[KEY::UP] == STATE::PRESSED)
    this->m_physique.moveUP(this->ships[0]);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->m_physique.moveDOWN(this->ships[0]);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->m_physique.moveLEFT(this->ships[0]);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->m_physique.moveRIGHT(this->ships[0]);

}

sf::Sprite&  game::returnSpritePlayer()
{
  return(this->ships[0]->returnSprite());
}

handlerSprite&  game::returnVertexPlayer()
{
  return(this->ships[0]->returnVertexSprite());
}
