#ifndef GAME_HH_
# define GAME_HH_


#include <SFML/Graphics.hpp>
#include "config.hh"
/*#include "handlerWindow.hh"
#include "handlerKeyMapping.hh"
#include "handlerSprite.hh"
#include "element.hh"
#include "ship.hh"
#include "object.hh"
#include "player.hh"
#include "ennemy.hh"
#include "physiqueManager.hh"
#include "view.hh"
#include "musicManager.hh"*/
#include "drawableClass.hh"
#include "IGame.hh"
//#include <vector>
#include <array>
#include <memory>

class game : public IGame
{
  /*handlerWindow         handler_window;
  handlerKeyMapping     handler_key;*/
  sf::Vector2f          mouse_click_val;


  drawableClass           drawable_menu;
  std::map<KEY, STATE>    key_map;
  /*physiqueManager         m_physique;
  view                    handler_view;*/
  std::array<int, 3>      basis;
  /*std::shared_ptr<handlerSprite> sprite_manager;
  //musicManager            music_manager;*/

public:

  game();
  ~game();

  void  launchGame();

  int   menu();
  int   endScreen();

  void  initializeTheGame();
  //void  initializeTheGame(sf::View, int, int);
  void  initializeLockedScreen();
  void  applyTurn();
  //int   deleteDeadElems();
};

#endif
