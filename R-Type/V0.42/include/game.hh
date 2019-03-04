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
#include <vector>
#include <array>

class game
{
  handlerSprite           title;
  sf::Font                font;
  sf::Text                text;
  std::vector<ship *>     ships;
  //std::vector<object *>   objects;
  physiqueManager         m_physique;
  std::map<KEY, STATE>    key_map;
  //background*             handler_background;
  //sf::View                view;
  view                    handler_view;
  std::array<int, 3>      basis;

//  handlerKeyMapping handler_key;

  void  applyPlayerTurn(int);
  void  applyEnnemyTurn(int);
  void  applyObjectsCollision();
  void  applyBordersCollision();

public:
  std::vector<object *>   objects;

  game();
  ~game();

  void  setKeyMap(std::map<KEY, STATE>  &);

  void  menu(sf::View, int, int);

  void  initializeTheGame();
  void  initializeTheGame(sf::View, int, int);
  void  applyTurn();
  int   deleteDeadElems();

  sf::View&                            returnView();
  sf::Sprite&                          returnSpritePlayer();
  handlerSprite                        returnVertexPlayer();
  //std::vector<const handlerSprite>          returnVertexVectorMovableObject();
  void          returnVertexVectorMovableObject(std::vector<handlerSprite> &);
  sf::Sprite&   returnBackground();
  sf::Sprite&   returnSpriteTitle();
  sf::Text&     returnText();
};

#endif
