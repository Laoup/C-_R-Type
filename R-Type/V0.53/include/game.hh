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
#include <memory>

class game
{
  std::shared_ptr<handlerSprite>           title;//celui ci n'est pas supprimé, probleme reglable avec la classe drawable je pense
  sf::Font                font;
  sf::Text                text;
  sf::Text                text2;
  sf::Text                text3;
  //std::vector<ship *>     ships;
  std::vector<std::shared_ptr<ship>>     ships;
  physiqueManager         m_physique;
  std::map<KEY, STATE>    key_map;
  view                    handler_view;
  std::array<int, 3>      basis;
  std::shared_ptr<handlerSprite> sprite_manager;
  //handlerSprite           *sprite_manager;
  //musicManager            music_manager;

  void  applyPlayerTurn(int, bool);
  void  applyEnnemyTurn(int);
  void  applyObjectsCollision(bool);
  void  applyBordersCollision();

public:
  //std::vector<object *>   objects;
  std::vector<std::shared_ptr<object>>   objects;

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

  //void          returnVertexVectorMovableObject(std::vector<element *> &);
  void          returnVertexVectorMovableObject(std::vector<drawableClass> &);
  sf::Sprite&   returnBackground();
  sf::Sprite&   returnSpriteTitle();
  sf::Text&     returnText();
  sf::Text&     returnText2();
  sf::Text&     returnText3();
};

#endif
