#ifndef GAME_HH_
# define GAME_HH_

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

class game
{
  std::vector<ship *>     ships;
  //std::vector<object *>   objects;
  physiqueManager         m_physique;
  std::map<KEY, STATE>    key_map;
  //background*             handler_background;
  //sf::View                view;
  view                    handler_view;

//  handlerKeyMapping handler_key;

public:
  std::vector<object *>   objects;

  game();
  ~game();

  void  setKeyMap(std::map<KEY, STATE>  &);

  void  initializeTheGame();
  void  initializeTheGame(sf::View);
  void  applyTurn();
  int   deleteDeadElems();

  sf::View&                            returnView();
  sf::Sprite&                          returnSpritePlayer();
  handlerSprite                        returnVertexPlayer();
  //std::vector<const handlerSprite>          returnVertexVectorMovableObject();
  void          returnVertexVectorMovableObject(std::vector<handlerSprite> &);
  sf::Sprite&    returnBackground();
};

#endif
