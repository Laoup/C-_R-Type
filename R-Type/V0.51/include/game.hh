#ifndef GAME_HH_
# define GAME_HH_

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
#include <vector>
#include <array>

class game
{
  handlerSprite           title;
  sf::Font                font;
  sf::Text                text;
  sf::Text                text2;
  sf::Text                text3;
  std::vector<ship *>     ships;
  physiqueManager         m_physique;
  std::map<KEY, STATE>    key_map;
  view                    handler_view;
  std::array<int, 3>      basis;
  handlerSprite           sprite_manager;
  musicManager            music_manager;

  void  applyPlayerTurn(int, bool);
  void  applyEnnemyTurn(int);
  void  applyObjectsCollision(bool);
  void  applyBordersCollision();

public:
  std::vector<object *>   objects;

  game();
  ~game();

  void  setKeyMap(std::map<KEY, STATE>  &);

  void  menu(sf::View, int, int);
  int   endScreen(sf::Vector2f , int, int);

  void  initializeTheGame();
  void  initializeTheGame(sf::View, int, int);
  void  initializeLockedScreen(sf::View, int, int);
  void  getTheWindow(sf::View);
  void  applyTurn();
  int   deleteDeadElems();

  sf::View&                            returnView();

  void          returnVertexVectorMovableObject(std::vector<element *> &);
  sf::Sprite&   returnBackground();
  sf::Sprite&   returnSpriteTitle();
  sf::Text&     returnText();
  sf::Text&     returnText2();
  sf::Text&     returnText3();
};

#endif
