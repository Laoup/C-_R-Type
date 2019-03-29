#include "../include/game.hh"

/*game::game() : sprite_manager(std::make_shared<handlerSprite> ()), handler_window("R-TYPE")
{
}*/

game::game()
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

  while (this->getHandlerWindow().windowIsOpen() && end == 0 || end == 1)
    {
      if (play == 0)
        {
          this->initializeLockedScreen();
          while (play == 0)
            {
              this->getHandlerWindow().windowClear(sf::Color::Black);
              this->mouse_click_val = this->getHandlerKey().returnMouseClick();
              play = this->menu();
              this->getHandlerWindow().windowIsEvent(this->getHandlerKey().getEvent());
              this->getHandlerWindow().windowDraw(this->getHandlerView().getBackground());
              this->getHandlerWindow().windowDrawMenu(this->drawable_menu);
              this->getHandlerWindow().setView(this->getHandlerView().getView());
              this->getHandlerWindow().windowDisplay();
            }
          this->initializeTheGame();
        }
        this->getHandlerWindow().windowIsEvent(this->getHandlerKey().getEvent());
        this->key_map = this->getHandlerKey().returnKey2();
        this->getPhysiqueManager().setKeyMap(this->key_map);
        //this->setKeyMap(this->key_map);this->handler_view.getView()
        this->applyTurn();

        this->getHandlerWindow().windowClear(sf::Color::Black);

        this->getPhysiqueManager().returnVertexVectorMovableObject(movable_object);

        it = movable_object.begin();
        this->getHandlerWindow().setView(this->getHandlerView().getView());
        this->getHandlerWindow().windowDraw(this->getHandlerView().getBackground());
        while (it != movable_object.end())
          {
            this->getHandlerWindow().windowDraw(*it);
            it++;
          }
        movable_object.erase(movable_object.begin(), movable_object.end());

        //End the current frame
        this->getHandlerWindow().windowDisplay();

        if (this->getPhysiqueManager().deleteDeadElems() == 0)
          {
            if (end == 0)
              this->initializeLockedScreen();
            else if (end == 1)
              this->getHandlerView().setView(this->getHandlerWindow().getDefaultView());
            //this->getTheWindow(this->handler_window.getDefaultView());
            end = 0;
            while (this->getHandlerWindow().windowIsOpen() && end == 0)
              {
                this->getHandlerWindow().windowClear(sf::Color::Black);
                this->mouse_click_val = this->getHandlerKey().returnMouseClick();
                end = this->endScreen();
                this->getHandlerWindow().windowIsEvent(this->getHandlerKey().getEvent());
                this->getHandlerWindow().windowDraw(this->getHandlerView().getBackground());
                this->getHandlerWindow().windowDrawMenu(this->drawable_menu);
                this->getHandlerWindow().setView(this->getHandlerView().getView());
                this->getHandlerWindow().windowDisplay();
                sf::sleep(sf::milliseconds(50));
              }
            if (end == 1)
              this->initializeTheGame();
          }
      }
}

int  game::menu()
{
  sf::FloatRect bounding_box;

  this->getHandlerView().defineBackground(this->getSpriteManager(), X_SIZE_WINDOW, Y_SIZE_WINDOW);

  this->drawable_menu.setSprite(this->getSpriteManager()->getTexture(6));
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
  this->getHandlerView().setWindowSize(X_SIZE_WINDOW, Y_SIZE_WINDOW);
  this->getHandlerView().setView(this->getHandlerWindow().getDefaultView());
  this->drawable_menu.setFontText("./ressources/abhinaya.ttf");
}

int   game::endScreen()
{
  sf::FloatRect bounding_boxY;
  sf::FloatRect bounding_boxN;

  this->getHandlerView().defineBackground(this->getSpriteManager(), X_SIZE_WINDOW, Y_SIZE_WINDOW);
  //this->title->makeSprite("./ressources/r_type_logo.png", 700, 200);
  this->drawable_menu.setSprite(this->getSpriteManager()->getTexture(6));
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

void  game::initializeTheGame()
{
  std::shared_ptr<player> player_ship;

  this->getHandlerView().setWindowSize(X_SIZE_WINDOW, Y_SIZE_WINDOW);
  this->getHandlerView().setView(this->getHandlerWindow().getDefaultView());
  this->getHandlerView().defineBackground(this->getSpriteManager(), 3000, 600);
  this->getPhysiqueManager().TileTheMap(X_SIZE_WINDOW, 3000, this->basis);

  this->getPhysiqueManager().createPlayerShip(this->getSpriteManager());

  //this->music_manager.playGameMusic();
  /*this->ships.push_back(new ennemy(&this->sprite_manager));
  this->ships[1]->getDrawable().setPosition(500,250);*/
}

 // Il est peut-etre possible dans cette fonction d'utiliser un itérateur, cependant pour l'instant cela produit une erreur -> solution possible 1) Pointeur intelligents et peut etre dynamique cast
 // C'est le même probleme que pour returnVertexVectorMovableObject un peu plus bas
void  game::applyTurn()
{
  static int  count = 0;
  bool        endMap;

  count++;
  endMap = this->getHandlerView().getRightSidePos() < this->getHandlerView().getXSizeBackground();
  if (endMap)
    this->getHandlerView().move(SPEED / 2 ,0);

  this->getPhysiqueManager().generateEnnemys(this->getHandlerView().getRightSidePos(), this->basis, this->getHandlerView().getXSizeBackground(), this->getSpriteManager());

  this->getPhysiqueManager().applyPlayerTurn(count, endMap);

  this->getPhysiqueManager().moveObjectVector();

  this->getPhysiqueManager().applyEnnemyTurn(count, this->getSpriteManager());

  /*if (this->ships.size() > 1)
    {
      this->applyEnnemyTurn(count);
    }*/
  this->getPhysiqueManager().applyObjectsCollision(!endMap, this->getSpriteManager());
  this->getPhysiqueManager().applyBordersCollision(this->getHandlerView());
  if (count == 2000)
    count = 0;
}
