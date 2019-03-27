#ifndef GAME_HH_
# define GAME_HH_


#include "handlerWindow.hh"
#include <SFML/Graphics.hpp>

#include "config.hh"
#include "handlerKeyMapping.hh"
#include "handlerSprite.hh"
#include "element.hh"
#include "ship.hh"
#include "object.hh"
#include "player.hh"
#include "ennemy.hh"
#include "physiqueManager.hh"
#include "view.hh"
#include "musicManager.hh"
#include "drawableClass.hh"
#include <vector>
#include <array>
#include <memory>

class game
{
  handlerWindow         handler_window;
  handlerKeyMapping     handler_key;
  //std::map<KEY, STATE>  key_map;
  sf::Vector2f          mouse_click_val;


  drawableClass           drawable_menu;
  //std::shared_ptr<handlerSprite>           title;//celui ci n'est pas supprimé, probleme reglable avec la classe drawable je pense
  /*sf::Font                font;
  sf::Text                text;
  sf::Text                text2;
  sf::Text                text3;*/
  //std::vector<ship *>     ships;
  //std::vector<std::shared_ptr<ship>>     ships;
  physiqueManager         m_physique;
  std::map<KEY, STATE>    key_map;
  view                    handler_view;
  std::array<int, 3>      basis;
  std::shared_ptr<handlerSprite> sprite_manager;
  //handlerSprite           *sprite_manager;
  //musicManager            music_manager;

  //void  applyPlayerTurn(int, bool);
  //void  applyEnnemyTurn(int);
  //void  applyObjectsCollision(bool);
  //void  applyBordersCollision();

public:
  //std::vector<object *>   objects;
  //std::vector<std::shared_ptr<object>>   objects;

  game();
  ~game();

  void  launchGame();

  //void  setKeyMap(std::map<KEY, STATE>  &);

  int   menu();
  int   endScreen();

  void  initializeTheGame();
  //void  initializeTheGame(sf::View, int, int);
  void  initializeLockedScreen();
  //void  getTheWindow(sf::View);
  void  applyTurn();
  int   deleteDeadElems();

  //void          returnVertexVectorMovableObject(std::vector<element *> &);
  //void          returnVertexVectorMovableObject(std::vector<drawableClass> &);
  //sf::View&                            returnView();
  /*sf::Sprite&   returnBackground();
  //sf::Sprite&   returnSpriteTitle();
  sf::Text&     returnText();
  sf::Text&     returnText2();
  sf::Text&     returnText3();
  drawableClass&  returnDrawableMenu();*/
};

#endif
