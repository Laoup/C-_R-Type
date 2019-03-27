#include "../include/game.hh"

game::game() : sprite_manager(std::make_shared<handlerSprite> ()), handler_window("R-TYPE")
{
}

game::~game()
{
}

void  game::launchGame()
{
  int                   end = 0;
  int                   play = 0;
  std::vector<drawableClass> movable_object;
  std::vector<drawableClass>::iterator it;

  while (this->handler_window.windowIsOpen() && end == 0 || end == 1)
    {
      if (play == 0)
        {
          this->initializeLockedScreen();
          while (play == 0)
            {
              this->handler_window.windowClear(sf::Color::Black);
              this->mouse_click_val = this->handler_key.returnMouseClick();
              play = this->menu();
              this->handler_window.windowIsEvent(this->handler_key.getEvent());
              this->handler_window.windowDraw(this->handler_view.getBackground());
              this->handler_window.windowDrawMenu(this->drawable_menu);
              this->handler_window.setView(this->handler_view.getView());
              this->handler_window.windowDisplay();
            }
          this->initializeTheGame();
        }
        this->handler_window.windowIsEvent(this->handler_key.getEvent());
        this->key_map = this->handler_key.returnKey2();
        this->m_physique.setKeyMap(this->key_map);
        //this->setKeyMap(this->key_map);this->handler_view.getView()
        this->applyTurn();

        this->handler_window.windowClear(sf::Color::Black);

        this->m_physique.returnVertexVectorMovableObject(movable_object);

        it = movable_object.begin();
        this->handler_window.setView(this->handler_view.getView());
        this->handler_window.windowDraw(this->handler_view.getBackground());
        while (it != movable_object.end())
          {
            this->handler_window.windowDraw(*it);
            it++;
          }
        movable_object.erase(movable_object.begin(), movable_object.end());

        //End the current frame
        this->handler_window.windowDisplay();

        if (this->m_physique.deleteDeadElems() == 0)
          {
            if (end == 0)
              this->initializeLockedScreen();
            else if (end == 1)
              this->handler_view.setView(this->handler_window.getDefaultView());
            //this->getTheWindow(this->handler_window.getDefaultView());
            end = 0;
            while (this->handler_window.windowIsOpen() && end == 0)
              {
                this->handler_window.windowClear(sf::Color::Black);
                this->mouse_click_val = this->handler_key.returnMouseClick();
                end = this->endScreen();
                this->handler_window.windowIsEvent(this->handler_key.getEvent());
                this->handler_window.windowDraw(this->handler_view.getBackground());
                this->handler_window.windowDrawMenu(this->drawable_menu);
                this->handler_window.setView(this->handler_view.getView());
                this->handler_window.windowDisplay();
                sf::sleep(sf::milliseconds(50));
              }
            if (end == 1)
              this->initializeTheGame();
          }
      }
}


/*void  game::applyPlayerTurn(int count, bool endMap)
{
  std::vector<std::shared_ptr<object>>  v_obj;

  /*if (key_map[KEY::UP] == STATE::PRESSED)
    this->ships[0]->getDrawable().move(0, -1 * SPEED);
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    this->ships[0]->getDrawable().move(0, SPEED);
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->ships[0]->getDrawable().move((SPEED * -1.15), 0);
  if (key_map[KEY::RIGHT] == STATE::PRESSED)
    this->ships[0]->getDrawable().move((SPEED * 1.5), 0);*/
/*
  if (key_map[KEY::UP] == STATE::PRESSED)
    {
      if (key_map[KEY::LEFT] == STATE::NOTPRESS && endMap == true)
        this->m_physique.moveRight(this->ships[0], SPEED * 0.5);
      this->m_physique.moveUp(this->ships[0]);
    }
  if (key_map[KEY::DOWN] == STATE::PRESSED)
    {
      if (key_map[KEY::LEFT] == STATE::NOTPRESS && endMap == true)
        this->m_physique.moveRight(this->ships[0], SPEED * 0.5);
      this->m_physique.moveDown(this->ships[0]);
    }
  if (key_map[KEY::LEFT] == STATE::PRESSED)
    this->m_physique.moveLeft(this->ships[0], SPEED * 1.15);
  if (key_map[KEY::RIGHT] == STATE::PRESSED || key_map[KEY::RIGHT] == STATE::NOTPRESS && key_map[KEY::LEFT] == STATE::NOTPRESS
  && key_map[KEY::UP] == STATE::NOTPRESS && key_map[KEY::DOWN] == STATE::NOTPRESS && endMap == true)
    this->m_physique.moveRight(this->ships[0], SPEED * 1.5);
  if (count == 2000)
    {
      v_obj = this->m_physique.fireOrder(this->ships[0], DIRECTION::RIGHT, this->ships[0]->getBoss());
      while (v_obj.size() != 0)
        {
          this->objects.push_back(std::move(v_obj[0]));
          v_obj.erase(v_obj.begin());
        }
      //count = 0;
    }
}*/

/*void  game::applyEnnemyTurn(int count)
{
  std::vector<std::shared_ptr<object>>  v_obj;
  int i;

  if (this->ships.size() > 1)
    {
      i = 1;
      while (i != this->ships.size())
        {
          this->m_physique.moveEnnemy(this->ships[i]);
          if (count == 2000)
            {
              v_obj = this->m_physique.fireOrder(this->ships[i], DIRECTION::LEFT, this->ships[i]->getBoss());
              while (v_obj.size() != 0)
                {
                  this->objects.push_back(std::move(v_obj[0]));
                  v_obj.erase(v_obj.begin());
                }
              //count = 0;
            }
          this->m_physique.checkCollision(this->ships[0], this->ships[i], this->objects, this->sprite_manager);
          i++;
        }
    }
}*/

/*void  game::applyObjectsCollision(bool endMap)
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
            this->m_physique.checkCollision(this->objects[i2], this->ships[i], this->objects, this->sprite_manager);
          this->m_physique.checkCollision(this->objects[i2], this->ships[0], this->objects, this->sprite_manager);
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
}*/

/*void  game::setKeyMap(std::map<KEY, STATE>  &key_map)
{
  this->key_map = key_map;
}*/

int  game::menu()
{
  sf::FloatRect bounding_box;

  this->handler_view.defineBackground(this->sprite_manager, X_SIZE_WINDOW, Y_SIZE_WINDOW);

  this->drawable_menu.setSprite(this->sprite_manager->getTexture(6));
  this->drawable_menu.setSpritePosition((X_SIZE_WINDOW / 2) - 350, 0);

  this->drawable_menu.addText("Start", 60);
  this->drawable_menu.setTextPosition("Start", (X_SIZE_WINDOW / 2) - 75, Y_SIZE_WINDOW / 2);
  this->drawable_menu.setColorText("Start", sf::Color::Red);

  bounding_box = this->drawable_menu.getBoundsText("Start");
  if (bounding_box.contains(this->mouse_click_val))
    return (1);
  else
    return (0);
}

void  game::initializeLockedScreen()
{
  this->handler_view.setWindowSize(X_SIZE_WINDOW, Y_SIZE_WINDOW);
  this->handler_view.setView(this->handler_window.getDefaultView());
  this->drawable_menu.setFontText("./ressources/abhinaya.ttf");
}

/*void  game::getTheWindow(sf::View view)
{
  this->handler_view.setView(view);
}*/

int   game::endScreen()
{
  sf::FloatRect bounding_boxY;
  sf::FloatRect bounding_boxN;

  this->handler_view.defineBackground(this->sprite_manager, X_SIZE_WINDOW, Y_SIZE_WINDOW);
  //this->title->makeSprite("./ressources/r_type_logo.png", 700, 200);
  this->drawable_menu.setSprite(this->sprite_manager->getTexture(6));
  this->drawable_menu.setSpritePosition((X_SIZE_WINDOW / 2) - 350, 0);

  this->drawable_menu.addText("Do You want to Play Again", 50);
  this->drawable_menu.setTextPosition("Do You want to Play Again", (X_SIZE_WINDOW / 2) - 200, Y_SIZE_WINDOW / 2);
  this->drawable_menu.setColorText("Do You want to Play Again", sf::Color::Red);

  this->drawable_menu.addText("YES", 50);
  this->drawable_menu.setTextPosition("YES", (X_SIZE_WINDOW / 2) - 100, Y_SIZE_WINDOW / 2 + 75);
  this->drawable_menu.setColorText("YES", sf::Color::Red);

  this->drawable_menu.addText("NO", 50);
  this->drawable_menu.setTextPosition("NO", (X_SIZE_WINDOW / 2) + 100, Y_SIZE_WINDOW / 2 + 75);
  this->drawable_menu.setColorText("NO", sf::Color::Red);

  bounding_boxY = this->drawable_menu.getBoundsText("YES");
  bounding_boxN = this->drawable_menu.getBoundsText("NO");

  if (bounding_boxY.contains(this->mouse_click_val))
    return (1);
  else if (bounding_boxN.contains(this->mouse_click_val))
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

void  game::initializeTheGame()
{
  std::shared_ptr<player> player_ship;

  this->handler_view.setWindowSize(X_SIZE_WINDOW, Y_SIZE_WINDOW);
  this->handler_view.setView(this->handler_window.getDefaultView());
  this->handler_view.defineBackground(this->sprite_manager, 3000, 600);
  this->m_physique.TileTheMap(X_SIZE_WINDOW, 3000, this->basis);

  this->m_physique.createPlayerShip(this->sprite_manager);

  /*player_ship = std::make_shared<player> (this->sprite_manager);
  this->ships.push_back(std::move(player_ship));
  this->ships[0]->getDrawable().setPosition(150,250);*/

  //this->music_manager.playGameMusic();
  /*this->ships.push_back(new ennemy(&this->sprite_manager));
  this->ships[1]->getDrawable().setPosition(500,250);*/
}

 // Il est peut-etre possible dans cette fonction d'utiliser un itérateur, cependant pour l'instant cela produit une erreur -> solution possible 1) Pointeur intelligents et peut etre dynamique cast
 // C'est le même probleme que pour returnVertexVectorMovableObject un peu plus bas
void  game::applyTurn()
{
  static int  count = 0;
  std::vector<element *>::iterator  it;
  bool        endMap;
  //element     *convertor;

  //convertor = dynamic_cast<element *>(this->ships[0]);
  //printf("ApplyTurn pos ship[0] ==>  x = %d,   y = %d \n", convertor->getPosition().x, convertor->getPosition().y);
  count++;
  endMap = this->handler_view.getRightSidePos() < this->handler_view.getXSizeBackground();
  if (endMap)
    this->handler_view.move(SPEED / 2 ,0);

  this->m_physique.generateEnnemys(this->handler_view.getRightSidePos(), this->basis, this->handler_view.getXSizeBackground(), this->sprite_manager);

  this->m_physique.applyPlayerTurn(count, endMap);

  this->m_physique.moveObjectVector();

  this->m_physique.applyEnnemyTurn(count, this->sprite_manager);

  /*if (this->ships.size() > 1)
    {
      this->applyEnnemyTurn(count);
    }*/
  this->m_physique.applyObjectsCollision(!endMap, this->sprite_manager);
  this->m_physique.applyBordersCollision(this->handler_view);
  if (count == 2000)
    count = 0;

}

/*void  game::returnVertexVectorMovableObject(std::vector<drawableClass>& vec)
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
}*/

/*int  game::deleteDeadElems()
{
  int i;

  i = 0;
  if (this->ships[0]->getOut() == 1)
    {
      //FIN DE LA PARTIE BIEN TOUT LIBERER !
      printf("YAAAAOOOYY\n");
      while (this->objects.size() != 0)
        {
          this->objects.erase(this->objects.begin());
        }
      while (this->ships.size() != 0)
        {
          this->ships.erase(this->ships.begin());
        }
      return (0);
    }
  while (i < this->ships.size())
    {
      if (this->ships[i]->getBoss() == true && this->ships[i]->getOut() == 1)
        {
          while (this->objects.size() != 0)
            {
              this->objects.erase(this->objects.begin());
            }
          while (this->ships.size() != 0)
            {
              this->ships.erase(this->ships.begin());
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
          this->ships.erase(this->ships.begin() + i);
        }
      else
        i++;
    }
  i = 0;
  while (i < this->objects.size())
    {
      if (this->objects[i]->getOut() == 1)
        {
          this->objects.erase(this->objects.begin() + i);
        }
      else
        i++;
    }
  return (1);
}*/

/*sf::View&    game::returnView()
{
  return (this->handler_view.getView());
}

sf::Sprite&  game::returnBackground()
{
  return (this->handler_view.getBackground());
}

/*sf::Sprite&  game::returnSpriteTitle()
{
  return(this->title->getSprite());
}*/

/*drawableClass&  game::returnDrawableMenu()
{
  return (this->drawable_menu);
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
}*/
