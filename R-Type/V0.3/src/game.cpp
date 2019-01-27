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
  //this->ships[0]->setPosition(800,600);
  this->ships.push_back(new ennemy);
  this->ships[1]->setPosition(500,250);
}


 // Il est peut-etre possible dans cette fonction d'utiliser un itérateur, cependant pour l'instant cela produit une erreur -> solution possible 1) Pointeur intelligents et peut etre dynamique cast
 // C'est le même probleme que pour returnVertexVectorMovableObject un peu plus bas
void  game::applyTurn()
{
  static int  count = 0;
  std::vector<element *>::iterator  it;
  int i;

  count++;
  if (key_map[KEY::UP] == STATE::PRESSED)
    this->m_physique.moveUP(this->ships[0]);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->m_physique.moveDOWN(this->ships[0]);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->m_physique.moveLEFT(this->ships[0]);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->m_physique.moveRIGHT(this->ships[0]);
  if (count == 40)
    {
      this->objects.push_back(this->m_physique.fireOrder(this->ships[0], DIRECTION::RIGHT));
      count = 0;
    }
    sf::Vector2f  pos;

  //pos = this->ships[0]->getPosition();
  //printf("\n\nSir ! My pos x is = %f, And my pos y is = %f\n\n", pos.x, pos.y);
  //this->objects = this->ships[0]->getFireList();
  this->m_physique.moveObjectVector(this->objects);

  /*for (int v = 0; v != this->objects.size(); v++)
    {
      this->objects[v]->setPosition(200+v,200+v);
    }*/
  int i2 = 0;
  if (this->ships.size() > 1)
    {
      while (i2 != this->objects.size())
        {
          this->m_physique.checkCollision(this->objects[i2], this->ships[1], this->objects);
          i2++;
        }
      i = 1;
      while (i != this->ships.size())
        {
          this->m_physique.moveEnnemy(this->ships[i]);
          this->m_physique.fireOrder(this->ships[i], DIRECTION::LEFT);
          this->m_physique.checkCollision(this->ships[0], this->ships[i], this->objects);
          i++;
        }
      }
  /*if (this->ships.begin() + 1 != this->ships.end())
    {
      it = this->ships.begin() + 1;//récupére le 1er ennemy
      while (it != this->ships.end())
        {
          this->m_physique.moveEnnemy(it);
          it++;
        }

    }*/

}

sf::Sprite&  game::returnSpritePlayer()
{
  return(this->ships[0]->returnSprite());
}

handlerSprite  game::returnVertexPlayer()
{
  return(this->ships[0]->returnVertexSprite());
}

 // Il est peut-etre possible dans cette fonction d'utiliser un itérateur, cependant
 // pour l'instant cela produit une erreur -> solution possible 1) Pointeur intelligents et peut etre dynamique cast
void  game::returnVertexVectorMovableObject(std::vector<handlerSprite>& vec)
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
      if (this->ships[i]->getOut() == 0)
        vec.push_back(this->ships[i]->returnVertexSprite());
      i++;
    }
  i = 0;
  while (i != this->objects.size())
    {
      vec.push_back(this->objects[i]->returnVertexSprite());
      i++;
    }
}
