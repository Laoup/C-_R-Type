#ifndef GAME_HH_
# define GAME_HH_

#include "handlerKeyMapping.hh"
#include "handlerSprite.hh"
#include "element.hh"
#include "player.hh"
#include "ennemy.hh"
#include "physiqueManager.hh"
#include <vector>

class game
{
  std::vector<element *>  ships;
  physiqueManager         m_physique;
  std::map<KEY, STATE>    key_map;

//  handlerKeyMapping handler_key;

public:
  game();
  ~game();

  void  setKeyMap(std::map<KEY, STATE>  &);

  void  initializeTheGame();
  void  applyTurn();

  sf::Sprite&                           returnSpritePlayer();
  handlerSprite                        returnVertexPlayer();
  //std::vector<const handlerSprite>          returnVertexVectorMovableObject();
  void          returnVertexVectorMovableObject(std::vector<handlerSprite> &);
};

#endif
