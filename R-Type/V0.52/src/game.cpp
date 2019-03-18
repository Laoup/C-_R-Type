#include "../include/game.hh"

game::game()
{
}

game::~game()
{
}


void  game::applyPlayerTurn(int count, bool endMap)
{
  /*if (key_map[KEY::UP] == STATE::PRESSED)
    this->ships[0]->getDrawable().move(0, -1 * SPEED);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->ships[0]->getDrawable().move(0, SPEED);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->ships[0]->getDrawable().move((SPEED * -1.15), 0);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->ships[0]->getDrawable().move((SPEED * 1.5), 0);*/
  if (key_map[KEY::UP] == STATE::PRESSED)
    {
      if (key_map[KEY::LEFT] == STATE::NOTPRESS && endMap == true)
        this->ships[0]->getDrawable().move(SPEED * 0.5, 0);
      this->ships[0]->getDrawable().move(0, (-1 * SPEED));
    }
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    {
      if (key_map[KEY::LEFT] == STATE::NOTPRESS && endMap == true)
        this->ships[0]->getDrawable().move((SPEED * 0.5), 0);
      this->ships[0]->getDrawable().move(0, SPEED);
    }
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->ships[0]->getDrawable().move((SPEED * -1.15), 0);
  if (key_map[KEY::RIGHT] == STATE::PRESSED || key_map[KEY::RIGHT] == STATE::NOTPRESS && key_map[KEY::LEFT] == STATE::NOTPRESS
  && key_map[KEY::UP] == STATE::NOTPRESS && key_map[KEY::DOWN] == STATE::NOTPRESS && endMap == true)
    this->ships[0]->getDrawable().move((SPEED * 1.5), 0);
  if (count == 2000)
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
          if (count == 2000 && this->ships[i]->getBoss() == false)
            {
              this->objects.push_back(this->m_physique.fireOrder(this->ships[i], DIRECTION::LEFT));
              //count = 0;
            }
          this->m_physique.checkCollision(this->ships[0], this->ships[i], this->objects, &this->sprite_manager);
          i++;
        }
    }
}

void  game::applyObjectsCollision(bool endMap)
{
  int i;
  int i2;

  i2 = 0;
  while (i2 != this->objects.size())
    {
      i = 0;
      while (i != this->ships.size())
        {
          if (this->ships[i]->getBoss() == true && endMap == true || this->ships[i]->getBoss() == false)
            this->m_physique.checkCollision(this->objects[i2], this->ships[i], this->objects, &this->sprite_manager);
          this->m_physique.checkCollision(this->objects[i2], this->ships[0], this->objects, &this->sprite_manager);
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
  i = 0;
  while (i != this->objects.size())
    {
      this->m_physique.checkBorderCollision(this->objects[i], this->handler_view);
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
  this->handler_view.defineBackground(&this->sprite_manager, xSizeWindow, ySizeWindow);
  this->title.makeSprite("./ressources/r_type_logo.png");
  //this->title.setOrigin(700 / 2, 204 / 2);//x/2 et y/2 de l'image de base
  this->title.setPosition((xSizeWindow / 2), ySizeWindow / 2);
}

void  game::initializeLockedScreen(sf::View view, int xSizeWindow, int ySizeWindow)
{
  this->handler_view.setWindowSize(xSizeWindow, ySizeWindow);
  this->handler_view.setView(view);
  if (!this->font.loadFromFile("./ressources/abhinaya.ttf"))
    {
      printf("Impossible de charger la Font dans le menu");
    }
  this->text.setFont(this->font);
  this->text2.setFont(this->font);
  this->text3.setFont(this->font);
}

void  game::getTheWindow(sf::View view)
{
  this->handler_view.setView(view);
}

int   game::endScreen(sf::Vector2f  arr, int xSizeWindow, int ySizeWindow)
{
  sf::FloatRect bounding_boxY;
  sf::FloatRect bounding_boxN;

  this->handler_view.defineBackground(&this->sprite_manager, xSizeWindow, ySizeWindow);
  this->title.makeSprite("./ressources/r_type_logo.png", 700, 200);
  //this->title.setOrigin(350, 100);
  this->title.getSprite().setPosition((xSizeWindow / 2) - 350, 0);
  //this->text.setPosition(200, 200);
  this->text.setString("Do You want to Play Again");
  this->text.setCharacterSize(50);
  //this->text.setOrigin(bounding_box.width / 2.0f + bounding_box.left, bounding_box.height / 2.0f + bounding_box.top);//x/2 et y/2 de l'image de base
  this->text.setPosition((xSizeWindow / 2) - 200, ySizeWindow / 2);
  this->text.setFillColor(sf::Color::Red);
  this->text2.setString("YES");
  this->text2.setCharacterSize(50);
  this->text2.setPosition((xSizeWindow / 2) - 100, ySizeWindow / 2 + 75);
  this->text2.setFillColor(sf::Color::Red);
  this->text3.setString("NO");
  this->text3.setCharacterSize(50);
  this->text3.setPosition((xSizeWindow / 2) + 100, ySizeWindow / 2 + 75);
  this->text3.setFillColor(sf::Color::Red);
  bounding_boxY = this->text2.getGlobalBounds();
  bounding_boxN = this->text3.getGlobalBounds();
  //this->title.setOrigin(700 / 2, 204 / 2);//x/2 et y/2 de l'image de base
  if (bounding_boxY.contains(arr))
    return (1);
  else if (bounding_boxN.contains(arr))
    return (2);
  return (0);
}

/* FONCTION PAS A JOUR */
/*
void  game::initializeTheGame()
{
  /*this->handler_background = new background("./ressources/background2.png");
  this->handler_background->defineSize(800, 600);*/
  /*this->ships.push_back(new player);
  this->ships[0]->setPosition(150,250);
  //this->ships[0]->setPosition(800,600);
  this->ships.push_back(new ennemy);
  this->ships[1]->setPosition(500,250);
}
*/

void  game::initializeTheGame(sf::View view, int xSizeWindow, int ySizeWindow)
{
  this->handler_view.setWindowSize(xSizeWindow, ySizeWindow);
  this->handler_view.setView(view);
  this->handler_view.defineBackground(&this->sprite_manager, 3000, 600);
  this->m_physique.TileTheMap(xSizeWindow, 3000, this->basis);
  this->ships.push_back(new player(&this->sprite_manager));
  this->ships[0]->getDrawable().setPosition(150,250);
  //printf("\n\n\n\n\nthis->ship[0]->getPosition().x = %f, this->ship[0]->getPosition().y = %f \n\n\n\n\n\n\n\n\n\n\n", this->ships[0]->drawable.getPosition().x, this->ships[0]->drawable.getPosition().y);
  //this->music_manager.playGameMusic();
  this->ships.push_back(new ennemy(&this->sprite_manager));
  this->ships[1]->getDrawable().setPosition(500,250);
}

 // Il est peut-etre possible dans cette fonction d'utiliser un itérateur, cependant pour l'instant cela produit une erreur -> solution possible 1) Pointeur intelligents et peut etre dynamique cast
 // C'est le même probleme que pour returnVertexVectorMovableObject un peu plus bas
void  game::applyTurn()
{
  static int  count = 0;
  std::vector<element *>::iterator  it;
  bool        endMap;
  element     *convertor;

  convertor = dynamic_cast<element *>(this->ships[0]);
  //printf("ApplyTurn pos ship[0] ==>  x = %d,   y = %d \n", convertor->getPosition().x, convertor->getPosition().y);
  count++;
  endMap = this->handler_view.getRightSidePos() < this->handler_view.getXSizeBackground();
  if (endMap)
    this->handler_view.move(SPEED / 2 ,0);

  this->m_physique.generateEnnemys(this->handler_view.getRightSidePos(), this->basis, this->ships, this->handler_view.getXSizeBackground(), this->handler_view.getXSizeWindow(), &this->sprite_manager);

  this->applyPlayerTurn(count, endMap);

  this->m_physique.moveObjectVector(this->objects);

  if (this->ships.size() > 1)
    {
      this->applyEnnemyTurn(count);
    }
  this->applyObjectsCollision(!endMap);
  this->applyBordersCollision();
  if (count == 2000)
    count = 0;

}

sf::View&    game::returnView()
{
  return (this->handler_view.getView());
}

void  game::returnVertexVectorMovableObject(std::vector<drawableClass>& vec)
{
  int     i;
  //std::vector<element *>::iterator  it;

  i = 0;
  while (i != this->ships.size())
    {
      vec.push_back(this->ships[i]->getDrawable());
      i++;
    }
  i = 0;
  while (i != this->objects.size())
    {
      vec.push_back(this->objects[i]->getDrawable());
      i++;
    }
}

/*void  game::returnVertexVectorMovableObject(std::vector<element *>& vec)
{
  int     i;
  //std::vector<element *>::iterator  it;

  i = 0;
  while (i != this->ships.size())
    {
      vec.push_back(dynamic_cast<element *>(this->ships[i]));
      i++;
    }
  i = 0;
  while (i != this->objects.size())
    {
      vec.push_back(dynamic_cast<element *>(this->objects[i]));
      i++;
    }
}*/

int  game::deleteDeadElems()
{
  element *elem;
  int i;

  i = 0;
  if (this->ships[0]->getOut() == 1)
    {
      //FIN DE LA PARTIE BIEN TOUT LIBERER !
      printf("YAAAAOOOYY\n");
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
      if (this->ships[i]->getBoss() == true && this->ships[i]->getOut() == 1)
        {
          while (this->objects.size() != 0)
            {
              elem = this->objects[0];
              this->objects.erase(this->objects.begin());
              delete elem;
            }
          while (this->ships.size() != 0)
            {
              elem = this->ships[0];
              this->ships.erase(this->ships.begin());
              delete elem;
            }
          return (0);
        }
      i++;
    }
  i = 0;
  while (i < this->ships.size())
    {
      if (this->ships[i]->getOut() == 1)
        {
          elem = this->ships[i];
          printf("al\n");
          this->ships.erase(this->ships.begin() + i);
          delete elem;
        }
      else
        i++;
    }
  i = 0;
  while (i < this->objects.size())
    {
      if (this->objects[i]->getOut() == 1)
        {
          //printf("erase one objects\n");
          elem = this->objects[i];

          this->objects.erase(this->objects.begin() + i);
          delete elem;
        }
      else
        i++;
    }
  return (1);
}

sf::Sprite&  game::returnBackground()
{
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

sf::Text&   game::returnText2()
{
  return (this->text2);
}

sf::Text&   game::returnText3()
{
  return (this->text3);
}
