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
  std::vector<element *>::iterator  it;
  int i;

  i = 0;
  if (key_map[KEY::UP] == STATE::PRESSED)
    this->m_physique.moveUP(this->ships[0]);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->m_physique.moveDOWN(this->ships[0]);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->m_physique.moveLEFT(this->ships[0]);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->m_physique.moveRIGHT(this->ships[0]);
  if (this->ships.begin() + 1 != this->ships.end())
    {
      it = this->ships.begin() + 1;//récupére le 1er ennemy
      while (it != this->ships.end())
        {
          this->m_physique.moveEnnemy(it);
          it++;
        }

    }

}

sf::Sprite&  game::returnSpritePlayer()
{
  return(this->ships[0]->returnSprite());
}

handlerSprite  game::returnVertexPlayer()
{
  return(this->ships[0]->returnVertexSprite());
}

void  game::returnVertexVectorMovableObject(std::vector<handlerSprite>& vec) // Il est peut-etre possible dans cette fonction d'utiliser un itérateur, cependant pour l'instant cela produit une erreur -> solution possible 1) Pointeur intelligents et peut etre dynamique cast
{
  int i;
  //std::vector<element *>::iterator  it;

  /*it = this->ships.begin();
  while (it != this->ships.end())
    {
      vec.push_back(it->returnVertexSprite());
      it++;
    }*/
  i = 0;
  while (i != this->ships.size())
    {
      vec.push_back(this->ships[i]->returnVertexSprite());
      i++;
    }
}
