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
  /*this->handler_background = new background("./ressources/background2.png");
  this->handler_background->defineSize(800, 600);*/
  this->ships.push_back(new player);
  this->ships[0]->setPosition(50,250);
  //this->ships[0]->setPosition(800,600);
  this->ships.push_back(new ennemy);
  this->ships[1]->setPosition(500,250);
}

void  game::initializeTheGame(sf::View view)
{
  this->handler_view.setView(view);
  this->handler_view.defineBackground("./ressources/background2.png", 1600, 600);
  //this->handler_view = view;
  //!!
  //this->handler_background = new background("./ressources/background2.png");
  //this->handler_background->defineSize(1600, 600);
  //!!
  this->ships.push_back(new player);
  this->ships[0]->setPosition(0,250);
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
  int i2;

  this->handler_view.move(0.85,0);
  count++;
  if (key_map[KEY::UP] == STATE::PRESSED)
    this->m_physique.moveUP(this->ships[0]);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->m_physique.moveDOWN(this->ships[0]);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->m_physique.moveLEFT(this->ships[0]);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->m_physique.moveRIGHT(this->ships[0]);
  if (count == 100)
    {
      this->objects.push_back(this->m_physique.fireOrder(this->ships[0], DIRECTION::RIGHT));
      //count = 0;
    }

  //this->objects = this->ships[0]->getFireList();
  this->m_physique.moveObjectVector(this->objects);

  /*for (int v = 0; v != this->objects.size(); v++)
    {
      this->objects[v]->setPosition(200+v,200+v);
    }*/
  if (this->ships.size() > 1)
    {
      i = 1;
      while (i != this->ships.size())
        {
          this->m_physique.moveEnnemy(this->ships[i]);
          if (count == 100000000000000)
            {
              this->objects.push_back(this->m_physique.fireOrder(this->ships[i], DIRECTION::LEFT));
              count = 0;
            }
          this->m_physique.checkCollision(this->ships[0], this->ships[i], this->objects);
          i++;
        }
      }
  i2 = 0;
  while (i2 != this->objects.size())
    {
      i = 0;
      while (i != this->ships.size())
        {
          this->m_physique.checkCollision(this->objects[i2], this->ships[i], this->objects);
          this->m_physique.checkCollision(this->objects[i2], this->ships[0], this->objects);
          i++;
        }
      i2++;
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

sf::View&    game::returnView()
{
  return (this->handler_view.getView());
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
      //if (this->ships[i]->getOut() == 0)
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

int  game::deleteDeadElems()
{
  element *elem;
  int i;

  i = 0;
  if (this->ships[0]->getOut() == 1)
    {
      //FIN DE LA PARTIE BIEN TOUT LIBERER !
      while (this->objects.size() != 0)
        {
          elem = this->objects[i];
          this->objects.erase(this->objects.begin());
          delete elem;
        }
      while (this->ships.size() != 0)
        {
          elem = this->ships[i];
          this->ships.erase(this->ships.begin());
          delete elem;
        }
      return (0);
    }
  while (i < this->ships.size())
    {
      if (this->ships[i]->getOut() == 1)
        {
          elem = this->ships[i];
          this->ships.erase(this->ships.begin() + i);
          delete elem;
        }
      i++;
    }
  i = 0;
  while (i < this->objects.size())
    {
      if (this->objects[i]->getOut() == 1)
        {
          elem = this->objects[i];
          this->objects.erase(this->objects.begin() + i);
          delete elem;
        }
      i++;
    }
  return (1);
}

sf::Sprite&  game::returnBackground()
{
  //return (this->handler_background->returnSprite());
  return (this->handler_view.getBackground());
}
