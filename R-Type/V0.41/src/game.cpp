#include "../include/game.hh"

game::game()
{
}

game::~game()
{
}

void  game::applyPlayerTurn(int count)
{
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
}

void  game::applyEnnemyTurn(int count)
{
  int i;

  if (this->ships.size() > 1)
    {
      i = 1;
      while (i != this->ships.size())
        {
          this->m_physique.moveEnnemy(this->ships[i]);
          if (count == 100)
            {
              this->objects.push_back(this->m_physique.fireOrder(this->ships[i], DIRECTION::LEFT));
              //count = 0;
            }
          this->m_physique.checkCollision(this->ships[0], this->ships[i], this->objects);
          i++;
        }
    }
}

void  game::applyObjectsCollision()
{
  int i;
  int i2;

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
}

void  game::applyBordersCollision()
{
  int i;

  i = 0;
  while (i != this->ships.size())
    {
      this->m_physique.checkBorderCollision(this->ships[i], this->handler_view);
      i++;
    }
}

void  game::setKeyMap(std::map<KEY, STATE>  &key_map)
{
  this->key_map = key_map;
}

void  game::menu(sf::View view, int xSizeWindow, int ySizeWindow)
{
  this->handler_view.setWindowSize(xSizeWindow, ySizeWindow);
  this->handler_view.setView(view);
  if (!this->font.loadFromFile("./ressources/abhinaya.ttf"))
    {
      printf("Impossible de charger la Font dans le menu");
    }
  this->text.setFont(this->font);
  this->text.setString("Start");
  this->text.setFillColor(sf::Color::Red);
  this->text.setCharacterSize(50);
  this->text.setPosition(200, 200);
  this->handler_view.defineBackground("./ressources/background2.png", 3000, 600);
  this->title.makeSprite("./ressources/r_type_logo.png");
  //this->title.setOrigin(700 / 2, 204 / 2);//x/2 et y/2 de l'image de base
  this->title.setPosition((xSizeWindow / 2), ySizeWindow / 2);
}

/* FONCTION PAS A JOUR */
void  game::initializeTheGame()
{
  /*this->handler_background = new background("./ressources/background2.png");
  this->handler_background->defineSize(800, 600);*/
  this->ships.push_back(new player);
  this->ships[0]->setPosition(150,250);
  //this->ships[0]->setPosition(800,600);
  this->ships.push_back(new ennemy);
  this->ships[1]->setPosition(500,250);
}

void  game::initializeTheGame(sf::View view, int xSizeWindow, int ySizeWindow)
{
  this->handler_view.setWindowSize(xSizeWindow, ySizeWindow);
  this->handler_view.setView(view);
  this->handler_view.defineBackground("./ressources/background2.png", 3000, 600);
  //this->basis = this->m_physique.TileTheMap(xSizeWindow, 2000);
  this->m_physique.TileTheMap(xSizeWindow, 3000, this->basis);
  printf("OK & basis[0] = %d\n", this->basis[0]);
  //this->handler_view = view;
  //!!
  //this->handler_background = new background("./ressources/background2.png");
  //this->handler_background->defineSize(1600, 600);
  //!!
  this->ships.push_back(new player);
  this->ships[0]->setPosition(150,250);
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
  //int i;
  //int i2;

  count++;
  if (this->handler_view.getRightSidePos() < this->handler_view.getXSizeBackground())
    this->handler_view.move(SPEED / 2 ,0);
  //printf("this->handler_view.getXSizeBackground() = %d, this->handler_view.getXSizeWindow() = %d\n", this->handler_view.getXSizeBackground(), this->handler_view.getXSizeWindow());
  printf("this->handler_view.getRightSidePos() = %d\n", this->handler_view.getRightSidePos());
  this->m_physique.generateEnnemys(this->handler_view.getRightSidePos(), this->basis, this->ships, this->handler_view.getXSizeBackground(), this->handler_view.getXSizeWindow());

  this->applyPlayerTurn(count);

  this->m_physique.moveObjectVector(this->objects);

  if (this->ships.size() > 1)
    {
      this->applyEnnemyTurn(count);
    }
  this->applyObjectsCollision();
  this->applyBordersCollision();
  if (count == 10)
    count = 0;

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

sf::Sprite&  game::returnSpriteTitle()
{
  return(this->title.getSprite());
}

sf::Text&   game::returnText()
{
  return (this->text);
}
